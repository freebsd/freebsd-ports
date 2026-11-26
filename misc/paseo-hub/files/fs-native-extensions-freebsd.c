#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/extattr.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <unistd.h>
#include <uv.h>

#include "../include/fs-ext.h"

#include "platform.h"

// flock(2) locks belong to the open file description, like the Linux OFD
// locks, but only cover the whole file, as on macOS.

int
fs_ext__try_lock(uv_os_fd_t fd, uint64_t offset, size_t length, fs_ext_lock_type_t type) {
  if (offset != 0 || length != 0) return UV_EINVAL;

  int res = flock(fd, (type == FS_EXT_WRLOCK ? LOCK_EX : LOCK_SH) | LOCK_NB);

  return res == -1 ? uv_translate_sys_error(errno) : res;
}

int
fs_ext__wait_for_lock(uv_os_fd_t fd, uint64_t offset, size_t length, fs_ext_lock_type_t type) {
  if (offset != 0 || length != 0) return UV_EINVAL;

  int res = flock(fd, type == FS_EXT_WRLOCK ? LOCK_EX : LOCK_SH);

  return res == -1 ? uv_translate_sys_error(errno) : res;
}

int
fs_ext__unlock(uv_os_fd_t fd, uint64_t offset, size_t length) {
  if (offset != 0 || length != 0) return UV_EINVAL;

  int res = flock(fd, LOCK_UN);

  return res == -1 ? uv_translate_sys_error(errno) : res;
}

int
fs_ext__trim(uv_os_fd_t fd, uint64_t offset, size_t length) {
  struct spacectl_range range = {
    .r_offset = (off_t) offset,
    .r_len = (off_t) length,
  };

  // fspacectl(2) may stop early, and then reports what is left in rmsr.
  while (range.r_len > 0) {
    int res = fspacectl(fd, SPACECTL_DEALLOC, &range, 0, &range);

    if (res == -1) return uv_translate_sys_error(errno);
  }

  return 0;
}

int
fs_ext__swap(const char *from, const char *to) {
  // FreeBSD has no atomic exchange of two paths.
  return UV_ENOSYS;
}

// Attribute names carry the namespace as a prefix, as on Linux and in the
// Linux emulation (sys/compat/linux/linux_xattr.c): "user.foo" is "foo" in
// EXTATTR_NAMESPACE_USER, and "system.foo" is "foo" in EXTATTR_NAMESPACE_SYSTEM.

static const char *fs_ext__attr_prefixes[] = {
  [EXTATTR_NAMESPACE_USER] = "user.",
  [EXTATTR_NAMESPACE_SYSTEM] = "system.",
};

static int
fs_ext__attr_name(const char *name, int *attrnamespace, const char **attrname) {
  for (int ns = EXTATTR_NAMESPACE_USER; ns <= EXTATTR_NAMESPACE_SYSTEM; ns++) {
    size_t len = strlen(fs_ext__attr_prefixes[ns]);

    if (strncmp(name, fs_ext__attr_prefixes[ns], len) == 0) {
      *attrnamespace = ns;
      *attrname = name + len;
      return 0;
    }
  }

  return UV_ENOTSUP;
}

int
fs_ext__get_attr(uv_os_fd_t fd, const char *name, uv_buf_t *value) {
  int ns;
  const char *attrname;

  int err = fs_ext__attr_name(name, &ns, &attrname);
  if (err < 0) return err;

  ssize_t res = extattr_get_fd(fd, ns, attrname, NULL, 0);

  if (res == -1) {
    if (errno == ENOATTR) return UV_ENODATA;

    return uv_translate_sys_error(errno);
  }

  *value = uv_buf_init(malloc(res), res);

  res = extattr_get_fd(fd, ns, attrname, value->base, value->len);

  if (res == -1) return uv_translate_sys_error(errno);

  // The value may have shrunk since the first call.
  value->len = res;

  return 0;
}

int
fs_ext__set_attr(uv_os_fd_t fd, const char *name, const uv_buf_t *value) {
  int ns;
  const char *attrname;

  int err = fs_ext__attr_name(name, &ns, &attrname);
  if (err < 0) return err;

  ssize_t res = extattr_set_fd(fd, ns, attrname, value->base, value->len);

  return res == -1 ? uv_translate_sys_error(errno) : 0;
}

int
fs_ext__remove_attr(uv_os_fd_t fd, const char *name) {
  int ns;
  const char *attrname;

  int err = fs_ext__attr_name(name, &ns, &attrname);
  if (err < 0) return err;

  int res = extattr_delete_fd(fd, ns, attrname);

  if (res == -1) {
    if (errno == ENOATTR) return UV_ENODATA;

    return uv_translate_sys_error(errno);
  }

  return 0;
}

int
fs_ext__list_attrs(uv_os_fd_t fd, char **names, size_t *length) {
  char *raw[EXTATTR_NAMESPACE_SYSTEM + 1] = {NULL};
  size_t raw_len[EXTATTR_NAMESPACE_SYSTEM + 1] = {0};

  size_t count = 0, size = 0;

  *names = NULL;
  *length = 0;

  for (int ns = EXTATTR_NAMESPACE_USER; ns <= EXTATTR_NAMESPACE_SYSTEM; ns++) {
    ssize_t res = extattr_list_fd(fd, ns, NULL, 0);

    if (res != -1) {
      raw[ns] = malloc(res > 0 ? res : 1);

      res = extattr_list_fd(fd, ns, raw[ns], res);
    }

    if (res == -1) {
      // Like listxattr(2) on Linux, leave out what the caller may not read.
      if (ns == EXTATTR_NAMESPACE_SYSTEM) {
        free(raw[ns]);
        raw[ns] = NULL;
        continue;
      }

      int err = uv_translate_sys_error(errno);

      for (int i = 0; i <= ns; i++) free(raw[i]);

      return err;
    }

    // Each entry is a length byte followed by the name, without a NUL. Stop
    // at an entry cut short, should the list have grown since the first call.
    size_t i = 0;

    while (i < (size_t) res) {
      size_t len = (unsigned char) raw[ns][i];

      if (i + 1 + len > (size_t) res) break;

      count++;
      size += strlen(fs_ext__attr_prefixes[ns]) + len + 1;
      i += len + 1;
    }

    raw_len[ns] = i;
  }

  // An array of pointers followed by the NUL terminated names, the layout
  // that the other platforms build from listxattr(2).
  size_t offset = count * sizeof(char *);

  *names = malloc(offset + size > 0 ? offset + size : 1);
  *length = count;

  char **pointers = (char **) *names;
  char *next = *names + offset;
  size_t j = 0;

  for (int ns = EXTATTR_NAMESPACE_USER; ns <= EXTATTR_NAMESPACE_SYSTEM; ns++) {
    size_t prefix_len = strlen(fs_ext__attr_prefixes[ns]);

    for (size_t i = 0; i < raw_len[ns]; i += (unsigned char) raw[ns][i] + 1) {
      size_t len = (unsigned char) raw[ns][i];

      memcpy(next, fs_ext__attr_prefixes[ns], prefix_len);
      memcpy(next + prefix_len, raw[ns] + i + 1, len);
      next[prefix_len + len] = '\0';

      memcpy(&pointers[j++], &next, sizeof(char *));

      next += prefix_len + len + 1;
    }

    free(raw[ns]);
  }

  return 0;
}
