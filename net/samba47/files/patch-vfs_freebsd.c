--- /dev/null	2018-03-05 02:00:00 UTC
+++ source3/modules/vfs_freebsd.c	2018-03-05 02:04:19.982828000 +0100
@@ -0,0 +1,1782 @@
+/*
+ * This module implements VFS calls specific to FreeBSD
+ *
+ * Copyright (C) Timur I. Bakeyev, 2018
+ *
+ * This program is free software; you can redistribute it and/or modify
+ * it under the terms of the GNU General Public License as published by
+ * the Free Software Foundation; either version 3 of the License, or
+ * (at your option) any later version.
+ *  
+ * This program is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ * GNU General Public License for more details.
+ *  
+ * You should have received a copy of the GNU General Public License
+ * along with this program; if not, see <http://www.gnu.org/licenses/>.
+ */
+
+#include "includes.h"
+
+//#include "../source3/include/includes.h"
+#include "lib/util/tevent_unix.h"
+#include "lib/util/tevent_ntstatus.h"
+#include "system/filesys.h"
+
+#include <sys/sysctl.h>
+
+
+#ifndef EXTATTR_MAXNAMELEN
+#define EXTATTR_MAXNAMELEN		UINT8_MAX
+#endif
+
+#define EXTATTR_NAMESPACE(NS)		EXTATTR_NAMESPACE_ ## NS, \
+					EXTATTR_NAMESPACE_ ## NS ## _STRING ".", \
+					.data.len = (sizeof(EXTATTR_NAMESPACE_ ## NS ## _STRING ".") - 1)
+
+#define EXTATTR_EMPTY			0x00
+#define EXTATTR_USER			0x01
+#define EXTATTR_SYSTEM			0x02
+#define EXTATTR_SECURITY		0x03
+#define EXTATTR_TRUSTED			0x04
+
+
+static bool is_secure = true;
+static bool is_legacy = false;
+
+typedef struct {
+	int namespace;
+	char name[EXTATTR_MAXNAMELEN+1];
+	union {
+		uint16_t len;
+		uint16_t flags;
+	} data;
+} extattr_attr;
+
+
+/* XXX: This order doesn't match namespace ids order! */
+static extattr_attr extattr[] = {
+	{ EXTATTR_NAMESPACE(EMPTY) },
+	{ EXTATTR_NAMESPACE(SYSTEM) },
+	{ EXTATTR_NAMESPACE(USER) },
+};
+
+typedef struct {
+	enum {
+		FILE, LINK, FDES
+	} method;
+	union {
+		const char *path;
+		int filedes;
+	} param;
+} extattr_arg;
+
+
+
+static bool freebsd_in_jail(void) {
+	int val = 0;
+	size_t val_len = sizeof(val);
+
+	if((sysctlbyname("security.jail.jailed", &val, &val_len, NULL, 0) != -1) && val == 1) {
+		return true;
+	}
+	return false;
+}
+
+static uint16_t freebsd_map_attrname(const char *name)
+{
+	if(name == NULL || name[0] == '\0') {
+		return EXTATTR_EMPTY;
+	}
+
+	switch(name[0]) {
+		case 'u':
+			if(strncmp(name, "user.", 5) == 0)
+				return EXTATTR_USER;
+			break;
+		case 't':
+			if(strncmp(name, "trusted.", 8) == 0)
+				return EXTATTR_TRUSTED;
+			break;
+		case 's':
+			/* name[1] could be any character, including '\0' */
+			switch(name[1]) {
+				case 'e':
+					if(strncmp(name, "security.", 9) == 0)
+						return EXTATTR_SECURITY;
+					break;
+				case 'y':
+					if(strncmp(name, "system.", 7) == 0)
+						return EXTATTR_SYSTEM;
+					break;
+			}
+			break;
+	}
+	return EXTATTR_USER;
+}
+
+/* security, system, trusted or user */
+static extattr_attr* freebsd_map_xattr(const char *name, extattr_attr *attr)
+{
+	int attrnamespace = EXTATTR_NAMESPACE_EMPTY;
+	const char *attrname = name;
+
+	if(name == NULL || name[0] == '\0') {
+		return NULL;
+	}
+
+	if(attr == NULL) {
+		return NULL;
+	}
+
+	uint16_t flags = freebsd_map_attrname(name);
+
+	switch(flags) {
+		case EXTATTR_USER:
+			attrnamespace = EXTATTR_NAMESPACE_USER;
+			if(is_legacy)
+				attrname = name + 5;
+			break;
+		case EXTATTR_SECURITY:
+		case EXTATTR_TRUSTED:
+			attrnamespace = (is_secure) ?
+					EXTATTR_NAMESPACE_SYSTEM :
+					EXTATTR_NAMESPACE_USER;
+			break;
+		case EXTATTR_SYSTEM:
+			attrnamespace = (is_secure) ?
+					EXTATTR_NAMESPACE_SYSTEM :
+					EXTATTR_NAMESPACE_USER;
+			if (is_legacy)
+				attrname = name + 7;
+			break;
+		default:
+			/* Default to "user" namespace if nothing else was specified */
+			attrnamespace = EXTATTR_NAMESPACE_USER;
+			flags = EXTATTR_USER;
+	}
+
+	attr->namespace = attrnamespace;
+	attr->data.flags = flags;
+	strlcpy(attr->name, attrname, EXTATTR_MAXNAMELEN+1);
+
+	return attr;
+}
+
+static ssize_t extattr_size(extattr_arg arg, extattr_attr *attr)
+{
+	ssize_t result;
+
+	switch(arg.method) {
+#if defined(HAVE_EXTATTR_GET_FILE)
+		case FILE:
+			result = extattr_get_file(arg.param.path, attr->namespace, attr->name, NULL, 0);
+			break;
+#endif
+#if defined(HAVE_EXTATTR_GET_LINK)
+		case LINK:
+			result = extattr_get_link(arg.param.path, attr->namespace, attr->name, NULL, 0);
+			break;
+#endif
+#if defined(HAVE_EXTATTR_GET_FD)
+		case FDES:
+			result = extattr_get_fd(arg.param.filedes, attr->namespace, attr->name, NULL, 0);
+			break;
+#endif
+		default:
+			errno = ENOSYS;
+			return -1;
+	}
+
+	if(result < 0) {
+		errno = EINVAL;
+		return -1;
+	}
+
+	return result;
+}
+
+
+/*
+ * The list of names is returned as an unordered array of NULL-terminated
+ * character strings (attribute names are separated by NULL characters),
+ * like this:
+ *      user.name1\0system.name1\0user.name2\0
+ *
+ * Filesystems like ext2, ext3 and XFS which implement POSIX ACLs using
+ * extended attributes, might return a list like this:
+ *      system.posix_acl_access\0system.posix_acl_default\0
+ */
+/*
+ * The extattr_list_file() returns a list of attributes present in the
+ * requested namespace. Each list entry consists of a single byte containing
+ * the length of the attribute name, followed by the attribute name. The
+ * attribute name is not terminated by ASCII 0 (nul).
+*/
+
+static ssize_t freebsd_extattr_list(extattr_arg arg, char *list, size_t size)
+{
+	ssize_t list_size, total_size = 0;
+	char *p, *q, *list_end;
+	int len;
+	/*
+	 Ignore all but user namespace when we are not root or in jail
+	 See: https://bugzilla.samba.org/show_bug.cgi?id=10247
+	*/
+	bool as_root = (geteuid() == 0);
+
+	int ns = (is_secure && as_root) ? 1 : 2;
+
+	/* Iterate through extattr(2) namespaces */
+	for(; ns < ARRAY_SIZE(extattr); ns++) {
+		switch(arg.method) {
+#if defined(HAVE_EXTATTR_LIST_FILE)
+			case FILE:
+				list_size = extattr_list_file(arg.param.path, extattr[ns].namespace, list, size);
+				break;
+#endif
+#if defined(HAVE_EXTATTR_LIST_LINK)
+			case LINK:
+				list_size = extattr_list_link(arg.param.path, extattr[ns].namespace, list, size);
+				break;
+#endif
+#if defined(HAVE_EXTATTR_LIST_FD)
+			case FDES:
+				list_size = extattr_list_fd(arg.param.filedes, extattr[ns].namespace, list, size);
+				break;
+#endif
+			default:
+				errno = ENOSYS;
+				return -1;
+		}
+		/* Some error happend. Errno should be set by the previous call */
+		if(list_size < 0)
+			return -1;
+		/* No attributes in this namespace */
+		if(list_size == 0)
+			continue;
+		/*
+		 Call with an empty buffer may be used to calculate
+		 necessary buffer size.
+		*/
+		if(list == NULL) {
+			/*
+			 XXX: Unfortunately, we can't say, how many attributes were
+			 returned, so here is the potential problem with the emulation.
+			*/
+			if(is_legacy) {
+				/*
+				 Take the worse case of one char attribute names -
+				 two bytes per name plus one more for sanity.
+				*/
+				total_size += list_size + (list_size/2 + 1)*extattr[ns].data.len;
+			}
+			else {
+				total_size += list_size;
+			}
+			continue;
+		}
+
+		if(is_legacy) {
+			/* Count necessary offset to fit namespace prefixes */
+			int extra_len = 0;
+			uint16_t flags;
+			list_end = list + list_size;
+			for(list_size = 0, p = q = list; p < list_end; p += len) {
+				len = p[0] + 1;
+				(void)strlcpy(q, p + 1, len);
+				flags = freebsd_map_attrname(q);
+				/* Skip secure attributes for non-root user */
+				if(!is_secure && !as_root && flags > EXTATTR_USER) {
+					continue;
+				}
+				if(flags <= EXTATTR_USER) {
+					/* Don't count trailing '\0' */
+					extra_len += extattr[ns].data.len;
+				}
+				list_size += len;
+				q += len;
+			}
+			total_size += list_size + extra_len;
+			/* Buffer is too small to fit the results */
+			if(total_size > size) {
+				errno = ERANGE;
+				return -1;
+			}
+			/* Shift results backwards, so we can prepend prefixes */
+			list_end = list + extra_len;
+			p = (char*)memmove(list_end, list, list_size);
+			/*
+			 We enter the loop with `p` pointing to the shifted list and
+			 `extra_len` having the total margin between `list` and `p`
+			*/
+			for(list_end += list_size; p < list_end; p += len) {
+				len = strlen(p) + 1;
+				flags = freebsd_map_attrname(p);
+				if(flags <= EXTATTR_USER) {
+					/* Add namespace prefix */
+					(void)strncpy(list, extattr[ns].name, extattr[ns].data.len);
+					list += extattr[ns].data.len;
+				}
+				/* Append attribute name */
+				(void)strlcpy(list, p, len);
+				list += len;
+			}
+		}
+		else {
+			/* Convert UCSD strings into nul-terminated strings */
+			for(list_end = list + list_size; list < list_end; list += len) {
+				len = list[0] + 1;
+				(void)strlcpy(list, list + 1, len);
+			}
+			total_size += list_size;
+		}
+	}
+	return total_size;
+}
+
+/*
+static ssize_t freebsd_getxattr_size(vfs_handle_struct *handle,
+				const struct smb_filename *smb_fname,
+				const char *name)
+{
+	extattr_arg arg = { FILE, smb_fname->base_name };
+	extattr_attr attr;
+
+	if(!freebsd_map_xattr(name, &attr)) {
+		errno = EINVAL;
+		return -1;
+	}
+
+	if(!is_secure && geteuid() != 0 && attr.data.flags > EXTATTR_USER) {
+		errno = ENOATTR;
+		return -1;
+	}
+
+	return extattr_size(arg, &attr);
+}
+*/
+
+/* VFS entries */
+static ssize_t freebsd_getxattr(vfs_handle_struct *handle,
+				const struct smb_filename *smb_fname,
+				const char *name,
+				void *value,
+				size_t size)
+{
+#if defined(HAVE_EXTATTR_GET_FILE)
+	extattr_arg arg = { FILE, .param.path = smb_fname->base_name };
+	extattr_attr attr;
+	ssize_t res;
+
+	if(!freebsd_map_xattr(name, &attr)) {
+		errno = EINVAL;
+		return -1;
+	}
+
+	/* Filter out 'secure' entries */
+	if(!is_secure && geteuid() != 0 && attr.data.flags > EXTATTR_USER) {
+		errno = ENOATTR;
+		return -1;
+	}
+
+	/*
+	 * The BSD implementation has a nasty habit of silently truncating
+	 * the returned value to the size of the buffer, so we have to check
+	 * that the buffer is large enough to fit the returned value.
+	 */
+	if((res=extattr_size(arg, &attr)) < 0) {
+		return -1;
+	}
+
+	if (size == 0) {
+		return res;
+	}
+	else if (res > size) {
+		errno = ERANGE;
+		return -1;
+	}
+
+	if((res=extattr_get_file(smb_fname->base_name, attr.namespace, attr.name, value, size)) >= 0) {
+		return res;
+	}
+	return -1;
+#else
+	errno = ENOSYS;
+	return -1;
+#endif
+}
+
+
+static ssize_t freebsd_fgetxattr(vfs_handle_struct *handle,
+			      struct files_struct *fsp, const char *name,
+			      void *value, size_t size)
+{
+#if defined(HAVE_EXTATTR_GET_FD)
+	extattr_arg arg = { FDES, .param.filedes = fsp->fh->fd };
+	extattr_attr attr;
+	ssize_t res;
+
+	if(!freebsd_map_xattr(name, &attr)) {
+		errno = EINVAL;
+		return -1;
+	}
+
+	/* Filter out 'secure' entries */
+	if(!is_secure && geteuid() != 0 && attr.data.flags > EXTATTR_USER) {
+		errno = ENOATTR;
+		return -1;
+	}
+
+	/*
+	 * The BSD implementation has a nasty habit of silently truncating
+	 * the returned value to the size of the buffer, so we have to check
+	 * that the buffer is large enough to fit the returned value.
+	 */
+	if((res=extattr_size(arg, &attr)) < 0) {
+		return -1;
+	}
+
+	if (size == 0) {
+		return res;
+	}
+	else if (res > size) {
+		errno = ERANGE;
+		return -1;
+	}
+
+	if((res=extattr_get_fd(fsp->fh->fd, attr.namespace, attr.name, value, size)) >= 0) {
+		return res;
+	}
+	return -1;
+#else
+	errno = ENOSYS;
+	return -1;
+#endif
+}
+
+
+static ssize_t freebsd_listxattr(vfs_handle_struct *handle,
+				const struct smb_filename *smb_fname,
+				char *list,
+				size_t size)
+{
+#if defined(HAVE_EXTATTR_LIST_FILE)
+	extattr_arg arg = { FILE, .param.path = smb_fname->base_name };
+
+	return freebsd_extattr_list(arg, list, size);
+#else
+	errno = ENOSYS;
+	return -1;
+#endif
+}
+
+
+static ssize_t freebsd_flistxattr(vfs_handle_struct *handle,
+			       struct files_struct *fsp, char *list,
+			       size_t size)
+{
+#if defined(HAVE_EXTATTR_LIST_FD)
+	extattr_arg arg = { FDES, .param.filedes = fsp->fh->fd };
+
+	return freebsd_extattr_list(arg, list, size);
+#else
+	errno = ENOSYS;
+	return -1;
+#endif
+}
+
+static int freebsd_removexattr(vfs_handle_struct *handle,
+			const struct smb_filename *smb_fname,
+			const char *name)
+{
+#if defined(HAVE_EXTATTR_DELETE_FILE)
+	extattr_attr attr;
+
+	if(!freebsd_map_xattr(name, &attr)) {
+		errno = EINVAL;
+		return -1;
+	}
+
+	/* Filter out 'secure' entries */
+	if(!is_secure && geteuid() != 0 && attr.data.flags > EXTATTR_USER) {
+		errno = ENOATTR;
+		return -1;
+	}
+
+	return extattr_delete_file(smb_fname->base_name, attr.namespace, attr.name);
+#else
+	errno = ENOSYS;
+	return -1;
+#endif
+}
+
+
+static int freebsd_fremovexattr(vfs_handle_struct *handle,
+			     struct files_struct *fsp, const char *name)
+{
+#if defined(HAVE_EXTATTR_DELETE_FD)
+	extattr_attr attr;
+
+	if(!freebsd_map_xattr(name, &attr)) {
+		errno = EINVAL;
+		return -1;
+	}
+
+	/* Filter out 'secure' entries */
+	if(!is_secure && geteuid() != 0 && attr.data.flags > EXTATTR_USER) {
+		errno = ENOATTR;
+		return -1;
+	}
+
+	return extattr_delete_fd(fsp->fh->fd, attr.namespace, attr.name);
+#else
+	errno = ENOSYS;
+	return -1;
+#endif
+}
+
+
+static int freebsd_setxattr(vfs_handle_struct *handle,
+			const struct smb_filename *smb_fname,
+			const char *name,
+			const void *value,
+			size_t size,
+			int flags)
+{
+#if defined(HAVE_EXTATTR_SET_FILE)
+	extattr_attr attr;
+	ssize_t res;
+
+	if(!freebsd_map_xattr(name, &attr)) {
+		errno = EINVAL;
+		return -1;
+	}
+
+	/* Filter out 'secure' entries */
+	if(!is_secure && geteuid() != 0 && attr.data.flags > EXTATTR_USER) {
+		errno = ENOATTR;
+		return -1;
+	}
+
+	if (flags) {
+		extattr_arg arg = { FILE, .param.path = smb_fname->base_name };
+		/* Check attribute existence */
+		res = extattr_size(arg, &attr);
+		if (res < 0) {
+			/* REPLACE attribute, that doesn't exist */
+			if ((flags & XATTR_REPLACE) && errno == ENOATTR) {
+				errno = ENOATTR;
+				return -1;
+			}
+			/* Ignore other errors */
+		}
+		else {
+			/* CREATE attribute, that already exists */
+			if (flags & XATTR_CREATE) {
+				errno = EEXIST;
+				return -1;
+			}
+		}
+	}
+	res = extattr_set_file(smb_fname->base_name, attr.namespace, attr.name, value, size);
+
+	return (res >= 0) ? 0 : -1;
+#else
+	errno = ENOSYS;
+	return -1;
+#endif
+}
+
+
+static int freebsd_fsetxattr(vfs_handle_struct *handle, struct files_struct *fsp,
+			  const char *name, const void *value, size_t size,
+			  int flags)
+{
+#if defined(HAVE_EXTATTR_SET_FD)
+	extattr_attr attr;
+	ssize_t res;
+
+	if(!freebsd_map_xattr(name, &attr)) {
+		errno = EINVAL;
+		return -1;
+	}
+
+	/* Filter out 'secure' entries */
+	if(!is_secure && geteuid() != 0 && attr.data.flags > EXTATTR_USER) {
+		errno = ENOATTR;
+		return -1;
+	}
+
+	if (flags) {
+		extattr_arg arg = { FDES, .param.filedes = fsp->fh->fd };
+		/* Check attribute existence */
+		res = extattr_size(arg, &attr);
+		if (res < 0) {
+			/* REPLACE attribute, that doesn't exist */
+			if ((flags & XATTR_REPLACE) && errno == ENOATTR) {
+				errno = ENOATTR;
+				return -1;
+			}
+			/* Ignore other errors */
+		}
+		else {
+			/* CREATE attribute, that already exists */
+			if (flags & XATTR_CREATE) {
+				errno = EEXIST;
+				return -1;
+			}
+		}
+	}
+
+	res = extattr_set_fd(fsp->fh->fd, attr.namespace, attr.name, value, size);
+
+	return (res >= 0) ? 0 : -1;
+#else
+	errno = ENOSYS;
+	return -1;
+#endif
+}
+
+
+
+
+static int freebsd_connect(vfs_handle_struct *handle, const char *service,
+			const char *user)
+{
+	return SMB_VFS_NEXT_CONNECT(handle, service, user);
+}
+
+static void freebsd_disconnect(vfs_handle_struct *handle)
+{
+	SMB_VFS_NEXT_DISCONNECT(handle);
+}
+
+static uint64_t freebsd_disk_free(vfs_handle_struct *handle,
+				const struct smb_filename *smb_fname,
+				uint64_t *bsize,
+				uint64_t *dfree,
+				uint64_t *dsize)
+{
+	return SMB_VFS_NEXT_DISK_FREE(handle, smb_fname, bsize, dfree, dsize);
+}
+
+static int freebsd_get_quota(vfs_handle_struct *handle,
+				const struct smb_filename *smb_fname,
+				enum SMB_QUOTA_TYPE qtype,
+				unid_t id,
+				SMB_DISK_QUOTA *dq)
+{
+	return SMB_VFS_NEXT_GET_QUOTA(handle, smb_fname, qtype, id, dq);
+}
+
+static int freebsd_set_quota(vfs_handle_struct *handle, enum SMB_QUOTA_TYPE qtype,
+			  unid_t id, SMB_DISK_QUOTA *dq)
+{
+	return SMB_VFS_NEXT_SET_QUOTA(handle, qtype, id, dq);
+}
+
+static int freebsd_get_shadow_copy_data(vfs_handle_struct *handle,
+				     files_struct *fsp,
+				     struct shadow_copy_data *shadow_copy_data,
+				     bool labels)
+{
+	return SMB_VFS_NEXT_GET_SHADOW_COPY_DATA(handle, fsp, shadow_copy_data,
+						 labels);
+}
+
+static int freebsd_statvfs(struct vfs_handle_struct *handle,
+			const struct smb_filename *smb_fname,
+			struct vfs_statvfs_struct *statbuf)
+{
+	return SMB_VFS_NEXT_STATVFS(handle, smb_fname, statbuf);
+}
+
+static uint32_t freebsd_fs_capabilities(struct vfs_handle_struct *handle,
+				     enum timestamp_set_resolution *p_ts_res)
+{
+	return SMB_VFS_NEXT_FS_CAPABILITIES(handle, p_ts_res);
+}
+
+static NTSTATUS freebsd_get_dfs_referrals(struct vfs_handle_struct *handle,
+				       struct dfs_GetDFSReferral *r)
+{
+	return SMB_VFS_NEXT_GET_DFS_REFERRALS(handle, r);
+}
+
+static DIR *freebsd_opendir(vfs_handle_struct *handle,
+			const struct smb_filename *smb_fname,
+			const char *mask,
+			uint32_t attr)
+{
+	return SMB_VFS_NEXT_OPENDIR(handle, smb_fname, mask, attr);
+}
+
+static NTSTATUS freebsd_snap_check_path(struct vfs_handle_struct *handle,
+				     TALLOC_CTX *mem_ctx,
+				     const char *service_path,
+				     char **base_volume)
+{
+	return SMB_VFS_NEXT_SNAP_CHECK_PATH(handle, mem_ctx, service_path,
+					    base_volume);
+}
+
+static NTSTATUS freebsd_snap_create(struct vfs_handle_struct *handle,
+				 TALLOC_CTX *mem_ctx,
+				 const char *base_volume,
+				 time_t *tstamp,
+				 bool rw,
+				 char **base_path,
+				 char **snap_path)
+{
+	return SMB_VFS_NEXT_SNAP_CREATE(handle, mem_ctx, base_volume, tstamp,
+					rw, base_path, snap_path);
+}
+
+static NTSTATUS freebsd_snap_delete(struct vfs_handle_struct *handle,
+				 TALLOC_CTX *mem_ctx,
+				 char *base_path,
+				 char *snap_path)
+{
+	return SMB_VFS_NEXT_SNAP_DELETE(handle, mem_ctx, base_path, snap_path);
+}
+
+static DIR *freebsd_fdopendir(vfs_handle_struct *handle, files_struct *fsp,
+			   const char *mask, uint32_t attr)
+{
+	return SMB_VFS_NEXT_FDOPENDIR(handle, fsp, mask, attr);
+}
+
+static struct dirent *freebsd_readdir(vfs_handle_struct *handle,
+				   DIR *dirp, SMB_STRUCT_STAT *sbuf)
+{
+	return SMB_VFS_NEXT_READDIR(handle, dirp, sbuf);
+}
+
+static void freebsd_seekdir(vfs_handle_struct *handle, DIR *dirp, long offset)
+{
+	SMB_VFS_NEXT_SEEKDIR(handle, dirp, offset);
+}
+
+static long freebsd_telldir(vfs_handle_struct *handle, DIR *dirp)
+{
+	return SMB_VFS_NEXT_TELLDIR(handle, dirp);
+}
+
+static void freebsd_rewind_dir(vfs_handle_struct *handle, DIR *dirp)
+{
+	SMB_VFS_NEXT_REWINDDIR(handle, dirp);
+}
+
+static int freebsd_mkdir(vfs_handle_struct *handle,
+		const struct smb_filename *smb_fname,
+		mode_t mode)
+{
+	return SMB_VFS_NEXT_MKDIR(handle, smb_fname, mode);
+}
+
+static int freebsd_rmdir(vfs_handle_struct *handle,
+		const struct smb_filename *smb_fname)
+{
+	return SMB_VFS_NEXT_RMDIR(handle, smb_fname);
+}
+
+static int freebsd_closedir(vfs_handle_struct *handle, DIR *dir)
+{
+	return SMB_VFS_NEXT_CLOSEDIR(handle, dir);
+}
+
+static int freebsd_open(vfs_handle_struct *handle, struct smb_filename *smb_fname,
+		     files_struct *fsp, int flags, mode_t mode)
+{
+	return SMB_VFS_NEXT_OPEN(handle, smb_fname, fsp, flags, mode);
+}
+
+static NTSTATUS freebsd_create_file(struct vfs_handle_struct *handle,
+				 struct smb_request *req,
+				 uint16_t root_dir_fid,
+				 struct smb_filename *smb_fname,
+				 uint32_t access_mask,
+				 uint32_t share_access,
+				 uint32_t create_disposition,
+				 uint32_t create_options,
+				 uint32_t file_attributes,
+				 uint32_t oplock_request,
+				 struct smb2_lease *lease,
+				 uint64_t allocation_size,
+				 uint32_t private_flags,
+				 struct security_descriptor *sd,
+				 struct ea_list *ea_list,
+				 files_struct ** result, int *pinfo,
+				 const struct smb2_create_blobs *in_context_blobs,
+				 struct smb2_create_blobs *out_context_blobs)
+{
+	return SMB_VFS_NEXT_CREATE_FILE(handle,
+					req,
+					root_dir_fid,
+					smb_fname,
+					access_mask,
+					share_access,
+					create_disposition,
+					create_options,
+					file_attributes,
+					oplock_request,
+					lease,
+					allocation_size,
+					private_flags,
+					sd, ea_list, result, pinfo,
+					in_context_blobs, out_context_blobs);
+}
+
+static int freebsd_close_fn(vfs_handle_struct *handle, files_struct *fsp)
+{
+	return SMB_VFS_NEXT_CLOSE(handle, fsp);
+}
+
+static ssize_t freebsd_vfs_read(vfs_handle_struct *handle, files_struct *fsp,
+			     void *data, size_t n)
+{
+	return SMB_VFS_NEXT_READ(handle, fsp, data, n);
+}
+
+static ssize_t freebsd_pread(vfs_handle_struct *handle, files_struct *fsp,
+			  void *data, size_t n, off_t offset)
+{
+	return SMB_VFS_NEXT_PREAD(handle, fsp, data, n, offset);
+}
+
+struct freebsd_pread_state {
+	ssize_t ret;
+	struct vfs_aio_state vfs_aio_state;
+};
+
+static void freebsd_pread_done(struct tevent_req *subreq);
+
+static struct tevent_req *freebsd_pread_send(struct vfs_handle_struct *handle,
+					  TALLOC_CTX *mem_ctx,
+					  struct tevent_context *ev,
+					  struct files_struct *fsp,
+					  void *data, size_t n, off_t offset)
+{
+	struct tevent_req *req, *subreq;
+	struct freebsd_pread_state *state;
+
+	req = tevent_req_create(mem_ctx, &state, struct freebsd_pread_state);
+	if (req == NULL) {
+		return NULL;
+	}
+	subreq = SMB_VFS_NEXT_PREAD_SEND(state, ev, handle, fsp, data,
+					 n, offset);
+	if (tevent_req_nomem(subreq, req)) {
+		return tevent_req_post(req, ev);
+	}
+	tevent_req_set_callback(subreq, freebsd_pread_done, req);
+	return req;
+}
+
+static void freebsd_pread_done(struct tevent_req *subreq)
+{
+	struct tevent_req *req =
+	    tevent_req_callback_data(subreq, struct tevent_req);
+	struct freebsd_pread_state *state =
+	    tevent_req_data(req, struct freebsd_pread_state);
+
+	state->ret = SMB_VFS_PREAD_RECV(subreq, &state->vfs_aio_state);
+	TALLOC_FREE(subreq);
+	tevent_req_done(req);
+}
+
+static ssize_t freebsd_pread_recv(struct tevent_req *req,
+			       struct vfs_aio_state *vfs_aio_state)
+{
+	struct freebsd_pread_state *state =
+	    tevent_req_data(req, struct freebsd_pread_state);
+
+	if (tevent_req_is_unix_error(req, &vfs_aio_state->error)) {
+		return -1;
+	}
+	*vfs_aio_state = state->vfs_aio_state;
+	return state->ret;
+}
+
+static ssize_t freebsd_write(vfs_handle_struct *handle, files_struct *fsp,
+			  const void *data, size_t n)
+{
+	return SMB_VFS_NEXT_WRITE(handle, fsp, data, n);
+}
+
+static ssize_t freebsd_pwrite(vfs_handle_struct *handle, files_struct *fsp,
+			   const void *data, size_t n, off_t offset)
+{
+	return SMB_VFS_NEXT_PWRITE(handle, fsp, data, n, offset);
+}
+
+struct freebsd_pwrite_state {
+	ssize_t ret;
+	struct vfs_aio_state vfs_aio_state;
+};
+
+static void freebsd_pwrite_done(struct tevent_req *subreq);
+
+static struct tevent_req *freebsd_pwrite_send(struct vfs_handle_struct *handle,
+					   TALLOC_CTX *mem_ctx,
+					   struct tevent_context *ev,
+					   struct files_struct *fsp,
+					   const void *data,
+					   size_t n, off_t offset)
+{
+	struct tevent_req *req, *subreq;
+	struct freebsd_pwrite_state *state;
+
+	req = tevent_req_create(mem_ctx, &state, struct freebsd_pwrite_state);
+	if (req == NULL) {
+		return NULL;
+	}
+	subreq = SMB_VFS_NEXT_PWRITE_SEND(state, ev, handle, fsp, data,
+					  n, offset);
+	if (tevent_req_nomem(subreq, req)) {
+		return tevent_req_post(req, ev);
+	}
+	tevent_req_set_callback(subreq, freebsd_pwrite_done, req);
+	return req;
+}
+
+static void freebsd_pwrite_done(struct tevent_req *subreq)
+{
+	struct tevent_req *req =
+	    tevent_req_callback_data(subreq, struct tevent_req);
+	struct freebsd_pwrite_state *state =
+	    tevent_req_data(req, struct freebsd_pwrite_state);
+
+	state->ret = SMB_VFS_PWRITE_RECV(subreq, &state->vfs_aio_state);
+	TALLOC_FREE(subreq);
+	tevent_req_done(req);
+}
+
+static ssize_t freebsd_pwrite_recv(struct tevent_req *req,
+				struct vfs_aio_state *vfs_aio_state)
+{
+	struct freebsd_pwrite_state *state =
+	    tevent_req_data(req, struct freebsd_pwrite_state);
+
+	if (tevent_req_is_unix_error(req, &vfs_aio_state->error)) {
+		return -1;
+	}
+	*vfs_aio_state = state->vfs_aio_state;
+	return state->ret;
+}
+
+static off_t freebsd_lseek(vfs_handle_struct *handle, files_struct *fsp,
+			off_t offset, int whence)
+{
+	return SMB_VFS_NEXT_LSEEK(handle, fsp, offset, whence);
+}
+
+static ssize_t freebsd_sendfile(vfs_handle_struct *handle, int tofd,
+			     files_struct *fromfsp, const DATA_BLOB *hdr,
+			     off_t offset, size_t n)
+{
+	return SMB_VFS_NEXT_SENDFILE(handle, tofd, fromfsp, hdr, offset, n);
+}
+
+static ssize_t freebsd_recvfile(vfs_handle_struct *handle, int fromfd,
+			     files_struct *tofsp, off_t offset, size_t n)
+{
+	return SMB_VFS_NEXT_RECVFILE(handle, fromfd, tofsp, offset, n);
+}
+
+static int freebsd_rename(vfs_handle_struct *handle,
+		       const struct smb_filename *smb_fname_src,
+		       const struct smb_filename *smb_fname_dst)
+{
+	return SMB_VFS_NEXT_RENAME(handle, smb_fname_src, smb_fname_dst);
+}
+
+static int freebsd_fsync(vfs_handle_struct *handle, files_struct *fsp)
+{
+	return SMB_VFS_NEXT_FSYNC(handle, fsp);
+}
+
+struct freebsd_fsync_state {
+	int ret;
+	struct vfs_aio_state vfs_aio_state;
+};
+
+static void freebsd_fsync_done(struct tevent_req *subreq);
+
+static struct tevent_req *freebsd_fsync_send(struct vfs_handle_struct *handle,
+					  TALLOC_CTX *mem_ctx,
+					  struct tevent_context *ev,
+					  struct files_struct *fsp)
+{
+	struct tevent_req *req, *subreq;
+	struct freebsd_fsync_state *state;
+
+	req = tevent_req_create(mem_ctx, &state, struct freebsd_fsync_state);
+	if (req == NULL) {
+		return NULL;
+	}
+	subreq = SMB_VFS_NEXT_FSYNC_SEND(state, ev, handle, fsp);
+	if (tevent_req_nomem(subreq, req)) {
+		return tevent_req_post(req, ev);
+	}
+	tevent_req_set_callback(subreq, freebsd_fsync_done, req);
+	return req;
+}
+
+static void freebsd_fsync_done(struct tevent_req *subreq)
+{
+	struct tevent_req *req =
+	    tevent_req_callback_data(subreq, struct tevent_req);
+	struct freebsd_fsync_state *state =
+	    tevent_req_data(req, struct freebsd_fsync_state);
+
+	state->ret = SMB_VFS_FSYNC_RECV(subreq, &state->vfs_aio_state);
+	TALLOC_FREE(subreq);
+	tevent_req_done(req);
+}
+
+static int freebsd_fsync_recv(struct tevent_req *req,
+			   struct vfs_aio_state *vfs_aio_state)
+{
+	struct freebsd_fsync_state *state =
+	    tevent_req_data(req, struct freebsd_fsync_state);
+
+	if (tevent_req_is_unix_error(req, &vfs_aio_state->error)) {
+		return -1;
+	}
+	*vfs_aio_state = state->vfs_aio_state;
+	return state->ret;
+}
+
+static int freebsd_stat(vfs_handle_struct *handle, struct smb_filename *smb_fname)
+{
+	return SMB_VFS_NEXT_STAT(handle, smb_fname);
+}
+
+static int freebsd_fstat(vfs_handle_struct *handle, files_struct *fsp,
+		      SMB_STRUCT_STAT *sbuf)
+{
+	return SMB_VFS_NEXT_FSTAT(handle, fsp, sbuf);
+}
+
+static int freebsd_lstat(vfs_handle_struct *handle,
+		      struct smb_filename *smb_fname)
+{
+	return SMB_VFS_NEXT_LSTAT(handle, smb_fname);
+}
+
+static uint64_t freebsd_get_alloc_size(struct vfs_handle_struct *handle,
+				    struct files_struct *fsp,
+				    const SMB_STRUCT_STAT *sbuf)
+{
+	return SMB_VFS_NEXT_GET_ALLOC_SIZE(handle, fsp, sbuf);
+}
+
+static int freebsd_unlink(vfs_handle_struct *handle,
+		       const struct smb_filename *smb_fname)
+{
+	return SMB_VFS_NEXT_UNLINK(handle, smb_fname);
+}
+
+static int freebsd_chmod(vfs_handle_struct *handle,
+			const struct smb_filename *smb_fname,
+			mode_t mode)
+{
+	return SMB_VFS_NEXT_CHMOD(handle, smb_fname, mode);
+}
+
+static int freebsd_fchmod(vfs_handle_struct *handle, files_struct *fsp,
+		       mode_t mode)
+{
+	return SMB_VFS_NEXT_FCHMOD(handle, fsp, mode);
+}
+
+static int freebsd_chown(vfs_handle_struct *handle,
+			const struct smb_filename *smb_fname,
+			uid_t uid,
+			gid_t gid)
+{
+	return SMB_VFS_NEXT_CHOWN(handle, smb_fname, uid, gid);
+}
+
+static int freebsd_fchown(vfs_handle_struct *handle, files_struct *fsp,
+		       uid_t uid, gid_t gid)
+{
+	return SMB_VFS_NEXT_FCHOWN(handle, fsp, uid, gid);
+}
+
+static int freebsd_lchown(vfs_handle_struct *handle,
+			const struct smb_filename *smb_fname,
+			uid_t uid,
+			gid_t gid)
+{
+	return SMB_VFS_NEXT_LCHOWN(handle, smb_fname, uid, gid);
+}
+
+static int freebsd_chdir(vfs_handle_struct *handle,
+			const struct smb_filename *smb_fname)
+{
+	return SMB_VFS_NEXT_CHDIR(handle, smb_fname);
+}
+
+static struct smb_filename *freebsd_getwd(vfs_handle_struct *handle,
+					TALLOC_CTX *ctx)
+{
+	return SMB_VFS_NEXT_GETWD(handle, ctx);
+}
+
+static int freebsd_ntimes(vfs_handle_struct *handle,
+		       const struct smb_filename *smb_fname,
+		       struct smb_file_time *ft)
+{
+	return SMB_VFS_NEXT_NTIMES(handle, smb_fname, ft);
+}
+
+static int freebsd_ftruncate(vfs_handle_struct *handle, files_struct *fsp,
+			  off_t offset)
+{
+	return SMB_VFS_NEXT_FTRUNCATE(handle, fsp, offset);
+}
+
+static int freebsd_fallocate(vfs_handle_struct *handle, files_struct *fsp,
+			  uint32_t mode, off_t offset, off_t len)
+{
+	return SMB_VFS_NEXT_FALLOCATE(handle, fsp, mode, offset, len);
+}
+
+static bool freebsd_lock(vfs_handle_struct *handle, files_struct *fsp, int op,
+		      off_t offset, off_t count, int type)
+{
+	return SMB_VFS_NEXT_LOCK(handle, fsp, op, offset, count, type);
+}
+
+static int freebsd_kernel_flock(struct vfs_handle_struct *handle,
+			     struct files_struct *fsp, uint32_t share_mode,
+			     uint32_t access_mask)
+{
+	return SMB_VFS_NEXT_KERNEL_FLOCK(handle, fsp, share_mode, access_mask);
+}
+
+static int freebsd_linux_setlease(struct vfs_handle_struct *handle,
+			       struct files_struct *fsp, int leasetype)
+{
+	return SMB_VFS_NEXT_LINUX_SETLEASE(handle, fsp, leasetype);
+}
+
+static bool freebsd_getlock(vfs_handle_struct *handle, files_struct *fsp,
+			 off_t *poffset, off_t *pcount, int *ptype,
+			 pid_t *ppid)
+{
+	return SMB_VFS_NEXT_GETLOCK(handle, fsp, poffset, pcount, ptype, ppid);
+}
+
+static int freebsd_symlink(vfs_handle_struct *handle,
+			const char *link_contents,
+			const struct smb_filename *new_smb_fname)
+{
+	return SMB_VFS_NEXT_SYMLINK(handle, link_contents, new_smb_fname);
+}
+
+static int freebsd_vfs_readlink(vfs_handle_struct *handle,
+			const struct smb_filename *smb_fname,
+			char *buf,
+			size_t bufsiz)
+{
+	return SMB_VFS_NEXT_READLINK(handle, smb_fname, buf, bufsiz);
+}
+
+static int freebsd_link(vfs_handle_struct *handle,
+			const struct smb_filename *old_smb_fname,
+			const struct smb_filename *new_smb_fname)
+{
+	return SMB_VFS_NEXT_LINK(handle, old_smb_fname, new_smb_fname);
+}
+
+static int freebsd_mknod(vfs_handle_struct *handle,
+			const struct smb_filename *smb_fname,
+			mode_t mode,
+			SMB_DEV_T dev)
+{
+	return SMB_VFS_NEXT_MKNOD(handle, smb_fname, mode, dev);
+}
+
+static struct smb_filename *freebsd_realpath(vfs_handle_struct *handle,
+			TALLOC_CTX *ctx,
+			const struct smb_filename *smb_fname)
+{
+	return SMB_VFS_NEXT_REALPATH(handle, ctx, smb_fname);
+}
+
+static int freebsd_chflags(vfs_handle_struct *handle,
+			const struct smb_filename *smb_fname,
+			uint flags)
+{
+	return SMB_VFS_NEXT_CHFLAGS(handle, smb_fname, flags);
+}
+
+static struct file_id freebsd_file_id_create(vfs_handle_struct *handle,
+					  const SMB_STRUCT_STAT *sbuf)
+{
+	return SMB_VFS_NEXT_FILE_ID_CREATE(handle, sbuf);
+}
+
+struct freebsd_offload_read_state {
+	struct vfs_handle_struct *handle;
+	DATA_BLOB token;
+};
+
+static void freebsd_offload_read_done(struct tevent_req *subreq);
+
+static struct tevent_req *freebsd_offload_read_send(
+	TALLOC_CTX *mem_ctx,
+	struct tevent_context *ev,
+	struct vfs_handle_struct *handle,
+	struct files_struct *fsp,
+	uint32_t fsctl,
+	uint32_t ttl,
+	off_t offset,
+	size_t to_copy)
+{
+	struct tevent_req *req = NULL;
+	struct freebsd_offload_read_state *state = NULL;
+	struct tevent_req *subreq = NULL;
+
+	req = tevent_req_create(mem_ctx, &state, struct freebsd_offload_read_state);
+	if (req == NULL) {
+		return NULL;
+	}
+	*state = (struct freebsd_offload_read_state) {
+		.handle = handle,
+	};
+
+	subreq = SMB_VFS_NEXT_OFFLOAD_READ_SEND(mem_ctx, ev, handle, fsp,
+						fsctl, ttl, offset, to_copy);
+	if (tevent_req_nomem(subreq, req)) {
+		return tevent_req_post(req, ev);
+	}
+	tevent_req_set_callback(subreq, freebsd_offload_read_done, req);
+	return req;
+}
+
+static void freebsd_offload_read_done(struct tevent_req *subreq)
+{
+	struct tevent_req *req = tevent_req_callback_data(
+		subreq, struct tevent_req);
+	struct freebsd_offload_read_state *state = tevent_req_data(
+		req, struct freebsd_offload_read_state);
+	NTSTATUS status;
+
+	status = SMB_VFS_NEXT_OFFLOAD_READ_RECV(subreq,
+						state->handle,
+						state,
+						&state->token);
+	TALLOC_FREE(subreq);
+	if (tevent_req_nterror(req, status)) {
+		return;
+	}
+
+	tevent_req_done(req);
+	return;
+}
+
+static NTSTATUS freebsd_offload_read_recv(struct tevent_req *req,
+				       struct vfs_handle_struct *handle,
+				       TALLOC_CTX *mem_ctx,
+				       DATA_BLOB *_token)
+{
+	struct freebsd_offload_read_state *state = tevent_req_data(
+		req, struct freebsd_offload_read_state);
+	DATA_BLOB token;
+	NTSTATUS status;
+
+	if (tevent_req_is_nterror(req, &status)) {
+		tevent_req_received(req);
+		return status;
+	}
+
+	token = data_blob_talloc(mem_ctx,
+				 state->token.data,
+				 state->token.length);
+
+	tevent_req_received(req);
+
+	if (token.data == NULL) {
+		return NT_STATUS_NO_MEMORY;
+	}
+
+	*_token = token;
+	return NT_STATUS_OK;
+}
+
+struct freebsd_offload_write_state {
+	struct vfs_handle_struct *handle;
+	off_t copied;
+};
+static void freebsd_offload_write_done(struct tevent_req *subreq);
+
+static struct tevent_req *freebsd_offload_write_send(struct vfs_handle_struct *handle,
+					       TALLOC_CTX *mem_ctx,
+					       struct tevent_context *ev,
+					       uint32_t fsctl,
+					       DATA_BLOB *token,
+					       off_t transfer_offset,
+					       struct files_struct *dest_fsp,
+					       off_t dest_off,
+					       off_t num)
+{
+	struct tevent_req *req;
+	struct tevent_req *subreq;
+	struct freebsd_offload_write_state *state;
+
+	req = tevent_req_create(mem_ctx, &state, struct freebsd_offload_write_state);
+	if (req == NULL) {
+		return NULL;
+	}
+
+	state->handle = handle;
+	subreq = SMB_VFS_NEXT_OFFLOAD_WRITE_SEND(handle, state, ev,
+					      fsctl, token, transfer_offset,
+					      dest_fsp, dest_off, num);
+	if (tevent_req_nomem(subreq, req)) {
+		return tevent_req_post(req, ev);
+	}
+
+	tevent_req_set_callback(subreq, freebsd_offload_write_done, req);
+	return req;
+}
+
+static void freebsd_offload_write_done(struct tevent_req *subreq)
+{
+	struct tevent_req *req = tevent_req_callback_data(
+		subreq, struct tevent_req);
+	struct freebsd_offload_write_state *state
+			= tevent_req_data(req, struct freebsd_offload_write_state);
+	NTSTATUS status;
+
+	status = SMB_VFS_NEXT_OFFLOAD_WRITE_RECV(state->handle,
+					      subreq,
+					      &state->copied);
+	TALLOC_FREE(subreq);
+	if (tevent_req_nterror(req, status)) {
+		return;
+	}
+	tevent_req_done(req);
+}
+
+static NTSTATUS freebsd_offload_write_recv(struct vfs_handle_struct *handle,
+				     struct tevent_req *req,
+				     off_t *copied)
+{
+	struct freebsd_offload_write_state *state
+			= tevent_req_data(req, struct freebsd_offload_write_state);
+	NTSTATUS status;
+
+	*copied = state->copied;
+	if (tevent_req_is_nterror(req, &status)) {
+		tevent_req_received(req);
+		return status;
+	}
+
+	tevent_req_received(req);
+	return NT_STATUS_OK;
+}
+
+static NTSTATUS freebsd_get_compression(struct vfs_handle_struct *handle,
+				     TALLOC_CTX *mem_ctx,
+				     struct files_struct *fsp,
+				     struct smb_filename *smb_fname,
+				     uint16_t *_compression_fmt)
+{
+	return SMB_VFS_NEXT_GET_COMPRESSION(handle, mem_ctx, fsp, smb_fname,
+					    _compression_fmt);
+}
+
+static NTSTATUS freebsd_set_compression(struct vfs_handle_struct *handle,
+				     TALLOC_CTX *mem_ctx,
+				     struct files_struct *fsp,
+				     uint16_t compression_fmt)
+{
+	return SMB_VFS_NEXT_SET_COMPRESSION(handle, mem_ctx, fsp,
+					    compression_fmt);
+}
+
+static NTSTATUS freebsd_streaminfo(struct vfs_handle_struct *handle,
+				struct files_struct *fsp,
+				const struct smb_filename *smb_fname,
+				TALLOC_CTX *mem_ctx,
+				unsigned int *num_streams,
+				struct stream_struct **streams)
+{
+	return SMB_VFS_NEXT_STREAMINFO(handle,
+				fsp,
+				smb_fname,
+				mem_ctx,
+				num_streams,
+				streams);
+}
+
+static int freebsd_get_real_filename(struct vfs_handle_struct *handle,
+				  const char *path,
+				  const char *name,
+				  TALLOC_CTX *mem_ctx, char **found_name)
+{
+	return SMB_VFS_NEXT_GET_REAL_FILENAME(handle,
+					      path, name, mem_ctx, found_name);
+}
+
+static const char *freebsd_connectpath(struct vfs_handle_struct *handle,
+				const struct smb_filename *smb_fname)
+{
+	return SMB_VFS_NEXT_CONNECTPATH(handle, smb_fname);
+}
+
+static NTSTATUS freebsd_brl_lock_windows(struct vfs_handle_struct *handle,
+				      struct byte_range_lock *br_lck,
+				      struct lock_struct *plock,
+				      bool blocking_lock)
+{
+	return SMB_VFS_NEXT_BRL_LOCK_WINDOWS(handle,
+					     br_lck, plock, blocking_lock);
+}
+
+static bool freebsd_brl_unlock_windows(struct vfs_handle_struct *handle,
+				    struct messaging_context *msg_ctx,
+				    struct byte_range_lock *br_lck,
+				    const struct lock_struct *plock)
+{
+	return SMB_VFS_NEXT_BRL_UNLOCK_WINDOWS(handle, msg_ctx, br_lck, plock);
+}
+
+static bool freebsd_brl_cancel_windows(struct vfs_handle_struct *handle,
+				    struct byte_range_lock *br_lck,
+				    struct lock_struct *plock)
+{
+	return SMB_VFS_NEXT_BRL_CANCEL_WINDOWS(handle, br_lck, plock);
+}
+
+static bool freebsd_strict_lock_check(struct vfs_handle_struct *handle,
+				   struct files_struct *fsp,
+				   struct lock_struct *plock)
+{
+	return SMB_VFS_NEXT_STRICT_LOCK_CHECK(handle, fsp, plock);
+}
+
+static NTSTATUS freebsd_translate_name(struct vfs_handle_struct *handle,
+				    const char *mapped_name,
+				    enum vfs_translate_direction direction,
+				    TALLOC_CTX *mem_ctx, char **pmapped_name)
+{
+	return SMB_VFS_NEXT_TRANSLATE_NAME(handle, mapped_name, direction,
+					   mem_ctx, pmapped_name);
+}
+
+static NTSTATUS freebsd_fsctl(struct vfs_handle_struct *handle,
+			   struct files_struct *fsp,
+			   TALLOC_CTX *ctx,
+			   uint32_t function,
+			   uint16_t req_flags,	/* Needed for UNICODE ... */
+			   const uint8_t *_in_data,
+			   uint32_t in_len,
+			   uint8_t ** _out_data,
+			   uint32_t max_out_len, uint32_t *out_len)
+{
+	return SMB_VFS_NEXT_FSCTL(handle,
+				  fsp,
+				  ctx,
+				  function,
+				  req_flags,
+				  _in_data,
+				  in_len, _out_data, max_out_len, out_len);
+}
+
+static NTSTATUS freebsd_readdir_attr(struct vfs_handle_struct *handle,
+				  const struct smb_filename *fname,
+				  TALLOC_CTX *mem_ctx,
+				  struct readdir_attr_data **pattr_data)
+{
+	return SMB_VFS_NEXT_READDIR_ATTR(handle, fname, mem_ctx, pattr_data);
+}
+
+static NTSTATUS freebsd_get_dos_attributes(struct vfs_handle_struct *handle,
+				struct smb_filename *smb_fname,
+				uint32_t *dosmode)
+{
+	return SMB_VFS_NEXT_GET_DOS_ATTRIBUTES(handle,
+				smb_fname,
+				dosmode);
+}
+
+static NTSTATUS freebsd_fget_dos_attributes(struct vfs_handle_struct *handle,
+				struct files_struct *fsp,
+				uint32_t *dosmode)
+{
+	return SMB_VFS_NEXT_FGET_DOS_ATTRIBUTES(handle,
+				fsp,
+				dosmode);
+}
+
+static NTSTATUS freebsd_set_dos_attributes(struct vfs_handle_struct *handle,
+				const struct smb_filename *smb_fname,
+				uint32_t dosmode)
+{
+	return SMB_VFS_NEXT_SET_DOS_ATTRIBUTES(handle,
+				smb_fname,
+				dosmode);
+}
+
+static NTSTATUS freebsd_fset_dos_attributes(struct vfs_handle_struct *handle,
+				struct files_struct *fsp,
+				uint32_t dosmode)
+{
+	return SMB_VFS_NEXT_FSET_DOS_ATTRIBUTES(handle,
+				fsp,
+				dosmode);
+}
+
+static NTSTATUS freebsd_fget_nt_acl(vfs_handle_struct *handle, files_struct *fsp,
+				 uint32_t security_info,
+				 TALLOC_CTX *mem_ctx,
+				 struct security_descriptor **ppdesc)
+{
+	return SMB_VFS_NEXT_FGET_NT_ACL(handle, fsp, security_info, mem_ctx,
+					ppdesc);
+}
+
+static NTSTATUS freebsd_get_nt_acl(vfs_handle_struct *handle,
+				const struct smb_filename *smb_fname,
+				uint32_t security_info,
+				TALLOC_CTX *mem_ctx,
+				struct security_descriptor **ppdesc)
+{
+	return SMB_VFS_NEXT_GET_NT_ACL(handle,
+				smb_fname,
+				security_info,
+				mem_ctx,
+				ppdesc);
+}
+
+static NTSTATUS freebsd_fset_nt_acl(vfs_handle_struct *handle, files_struct *fsp,
+				 uint32_t security_info_sent,
+				 const struct security_descriptor *psd)
+{
+	return SMB_VFS_NEXT_FSET_NT_ACL(handle, fsp, security_info_sent, psd);
+}
+
+static int freebsd_chmod_acl(vfs_handle_struct *handle,
+			const struct smb_filename *smb_fname,
+			mode_t mode)
+{
+	return SMB_VFS_NEXT_CHMOD_ACL(handle, smb_fname, mode);
+}
+
+static int freebsd_fchmod_acl(vfs_handle_struct *handle, files_struct *fsp,
+			   mode_t mode)
+{
+	return SMB_VFS_NEXT_FCHMOD_ACL(handle, fsp, mode);
+}
+
+static SMB_ACL_T freebsd_sys_acl_get_file(vfs_handle_struct *handle,
+				       const struct smb_filename *smb_fname,
+				       SMB_ACL_TYPE_T type,
+				       TALLOC_CTX *mem_ctx)
+{
+	return SMB_VFS_NEXT_SYS_ACL_GET_FILE(handle, smb_fname, type, mem_ctx);
+}
+
+static SMB_ACL_T freebsd_sys_acl_get_fd(vfs_handle_struct *handle,
+				     files_struct *fsp, TALLOC_CTX *mem_ctx)
+{
+	return SMB_VFS_NEXT_SYS_ACL_GET_FD(handle, fsp, mem_ctx);
+}
+
+static int freebsd_sys_acl_blob_get_file(vfs_handle_struct *handle,
+				const struct smb_filename *smb_fname,
+				TALLOC_CTX *mem_ctx,
+				char **blob_description,
+				DATA_BLOB *blob)
+{
+	return SMB_VFS_NEXT_SYS_ACL_BLOB_GET_FILE(handle, smb_fname, mem_ctx,
+						  blob_description, blob);
+}
+
+static int freebsd_sys_acl_blob_get_fd(vfs_handle_struct *handle,
+				    files_struct *fsp, TALLOC_CTX *mem_ctx,
+				    char **blob_description, DATA_BLOB *blob)
+{
+	return SMB_VFS_NEXT_SYS_ACL_BLOB_GET_FD(handle, fsp, mem_ctx,
+						blob_description, blob);
+}
+
+static int freebsd_sys_acl_set_file(vfs_handle_struct *handle,
+				const struct smb_filename *smb_fname,
+				SMB_ACL_TYPE_T acltype,
+				SMB_ACL_T theacl)
+{
+	return SMB_VFS_NEXT_SYS_ACL_SET_FILE(handle, smb_fname,
+			acltype, theacl);
+}
+
+static int freebsd_sys_acl_set_fd(vfs_handle_struct *handle, files_struct *fsp,
+			       SMB_ACL_T theacl)
+{
+	return SMB_VFS_NEXT_SYS_ACL_SET_FD(handle, fsp, theacl);
+}
+
+static int freebsd_sys_acl_delete_def_file(vfs_handle_struct *handle,
+					const struct smb_filename *smb_fname)
+{
+	return SMB_VFS_NEXT_SYS_ACL_DELETE_DEF_FILE(handle, smb_fname);
+}
+
+
+static bool freebsd_aio_force(struct vfs_handle_struct *handle,
+			   struct files_struct *fsp)
+{
+	return SMB_VFS_NEXT_AIO_FORCE(handle, fsp);
+}
+
+/* VFS operations structure */
+
+struct vfs_fn_pointers freebsd_fns = {
+	/* Disk operations */
+
+	.connect_fn = freebsd_connect,
+	.disconnect_fn = freebsd_disconnect,
+	.disk_free_fn = freebsd_disk_free,
+	.get_quota_fn = freebsd_get_quota,
+	.set_quota_fn = freebsd_set_quota,
+	.get_shadow_copy_data_fn = freebsd_get_shadow_copy_data,
+	.statvfs_fn = freebsd_statvfs,
+	.fs_capabilities_fn = freebsd_fs_capabilities,
+	.get_dfs_referrals_fn = freebsd_get_dfs_referrals,
+	.snap_check_path_fn = freebsd_snap_check_path,
+	.snap_create_fn = freebsd_snap_create,
+	.snap_delete_fn = freebsd_snap_delete,
+
+	/* Directory operations */
+
+	.opendir_fn = freebsd_opendir,
+	.fdopendir_fn = freebsd_fdopendir,
+	.readdir_fn = freebsd_readdir,
+	.seekdir_fn = freebsd_seekdir,
+	.telldir_fn = freebsd_telldir,
+	.rewind_dir_fn = freebsd_rewind_dir,
+	.mkdir_fn = freebsd_mkdir,
+	.rmdir_fn = freebsd_rmdir,
+	.closedir_fn = freebsd_closedir,
+
+	/* File operations */
+
+	.open_fn = freebsd_open,
+	.create_file_fn = freebsd_create_file,
+	.close_fn = freebsd_close_fn,
+	.read_fn = freebsd_vfs_read,
+	.pread_fn = freebsd_pread,
+	.pread_send_fn = freebsd_pread_send,
+	.pread_recv_fn = freebsd_pread_recv,
+	.write_fn = freebsd_write,
+	.pwrite_fn = freebsd_pwrite,
+	.pwrite_send_fn = freebsd_pwrite_send,
+	.pwrite_recv_fn = freebsd_pwrite_recv,
+	.lseek_fn = freebsd_lseek,
+	.sendfile_fn = freebsd_sendfile,
+	.recvfile_fn = freebsd_recvfile,
+	.rename_fn = freebsd_rename,
+	.fsync_fn = freebsd_fsync,
+	.fsync_send_fn = freebsd_fsync_send,
+	.fsync_recv_fn = freebsd_fsync_recv,
+	.stat_fn = freebsd_stat,
+	.fstat_fn = freebsd_fstat,
+	.lstat_fn = freebsd_lstat,
+	.get_alloc_size_fn = freebsd_get_alloc_size,
+	.unlink_fn = freebsd_unlink,
+	.chmod_fn = freebsd_chmod,
+	.fchmod_fn = freebsd_fchmod,
+	.chown_fn = freebsd_chown,
+	.fchown_fn = freebsd_fchown,
+	.lchown_fn = freebsd_lchown,
+	.chdir_fn = freebsd_chdir,
+	.getwd_fn = freebsd_getwd,
+	.ntimes_fn = freebsd_ntimes,
+	.ftruncate_fn = freebsd_ftruncate,
+	.fallocate_fn = freebsd_fallocate,
+	.lock_fn = freebsd_lock,
+	.kernel_flock_fn = freebsd_kernel_flock,
+	.linux_setlease_fn = freebsd_linux_setlease,
+	.getlock_fn = freebsd_getlock,
+	.symlink_fn = freebsd_symlink,
+	.readlink_fn = freebsd_vfs_readlink,
+	.link_fn = freebsd_link,
+	.mknod_fn = freebsd_mknod,
+	.realpath_fn = freebsd_realpath,
+	.chflags_fn = freebsd_chflags,
+	.file_id_create_fn = freebsd_file_id_create,
+	.offload_read_send_fn = freebsd_offload_read_send,
+	.offload_read_recv_fn = freebsd_offload_read_recv,
+	.offload_write_send_fn = freebsd_offload_write_send,
+	.offload_write_recv_fn = freebsd_offload_write_recv,
+	.get_compression_fn = freebsd_get_compression,
+	.set_compression_fn = freebsd_set_compression,
+
+	.streaminfo_fn = freebsd_streaminfo,
+	.get_real_filename_fn = freebsd_get_real_filename,
+	.connectpath_fn = freebsd_connectpath,
+	.brl_lock_windows_fn = freebsd_brl_lock_windows,
+	.brl_unlock_windows_fn = freebsd_brl_unlock_windows,
+	.brl_cancel_windows_fn = freebsd_brl_cancel_windows,
+	.strict_lock_check_fn = freebsd_strict_lock_check,
+	.translate_name_fn = freebsd_translate_name,
+	.fsctl_fn = freebsd_fsctl,
+	.readdir_attr_fn = freebsd_readdir_attr,
+
+	/* DOS attributes. */
+	.get_dos_attributes_fn = freebsd_get_dos_attributes,
+	.fget_dos_attributes_fn = freebsd_fget_dos_attributes,
+	.set_dos_attributes_fn = freebsd_set_dos_attributes,
+	.fset_dos_attributes_fn = freebsd_fset_dos_attributes,
+
+	/* NT ACL operations. */
+
+	.fget_nt_acl_fn = freebsd_fget_nt_acl,
+	.get_nt_acl_fn = freebsd_get_nt_acl,
+	.fset_nt_acl_fn = freebsd_fset_nt_acl,
+
+	/* POSIX ACL operations. */
+
+	.chmod_acl_fn = freebsd_chmod_acl,
+	.fchmod_acl_fn = freebsd_fchmod_acl,
+
+	.sys_acl_get_file_fn = freebsd_sys_acl_get_file,
+	.sys_acl_get_fd_fn = freebsd_sys_acl_get_fd,
+	.sys_acl_blob_get_file_fn = freebsd_sys_acl_blob_get_file,
+	.sys_acl_blob_get_fd_fn = freebsd_sys_acl_blob_get_fd,
+	.sys_acl_set_file_fn = freebsd_sys_acl_set_file,
+	.sys_acl_set_fd_fn = freebsd_sys_acl_set_fd,
+	.sys_acl_delete_def_file_fn = freebsd_sys_acl_delete_def_file,
+
+	/* EA operations. */
+	.getxattr_fn = freebsd_getxattr,
+	.fgetxattr_fn = freebsd_fgetxattr,
+	.listxattr_fn = freebsd_listxattr,
+	.flistxattr_fn = freebsd_flistxattr,
+	.removexattr_fn = freebsd_removexattr,
+	.fremovexattr_fn = freebsd_fremovexattr,
+	.setxattr_fn = freebsd_setxattr,
+	.fsetxattr_fn = freebsd_fsetxattr,
+
+	/* aio operations */
+	.aio_force_fn = freebsd_aio_force,
+};
+
+static_decl_vfs;
+NTSTATUS vfs_freebsd_init(TALLOC_CTX *ctx)
+{
+
+	if(freebsd_in_jail())
+		is_secure = false;
+
+	return smb_register_vfs(SMB_VFS_INTERFACE_VERSION, "freebsd",
+				&freebsd_fns);
+}
