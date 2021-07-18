
#include <sys/types.h>
#include <sys/extattr.h>

#include <assert.h>

///
/// xattr is a Linux kernel API that has to be mapped to the FreeBSD API
///

// code below is adopted and simplified from the 'xattr' python module https://github.com/xattr/xattr/blob/master/xattr/lib_build.c

static void convert_bsd_list(char *namebuf, size_t size) {
	size_t offset = 0;
	while(offset < size) {
		int length = (int) (unsigned char)namebuf[offset];
		memmove(namebuf+offset, namebuf+offset+1, length);
		namebuf[offset+length] = '\0';
		offset += length+1;
	}
}

int fsetxattr(int fd, const char *name, const void *value, size_t size, int flags) {
	int rv = 0;

	assert(flags == 0); // we do not handle flags here and the project currently doesn't use flags!=0

	rv = extattr_set_fd(fd, EXTATTR_NAMESPACE_USER, name, value, size);

	/* freebsd returns the written length on success, not zero. */
	if (rv >= 0)
		return 0;
	else
		return rv;
}

ssize_t flistxattr(int fd, char *namebuf, size_t size) {
	ssize_t rv = 0;

	rv = extattr_list_fd(fd, EXTATTR_NAMESPACE_USER, namebuf, size);

	if (rv > 0 && namebuf)
		convert_bsd_list(namebuf, rv);

	return rv;
}

ssize_t fgetxattr(int fd, const char *name, void *value, size_t size) {
	return extattr_get_fd(fd, EXTATTR_NAMESPACE_USER, name, value, size);
}

int fremovexattr(int fd, const char *name) {
	return extattr_delete_fd(fd, EXTATTR_NAMESPACE_USER, name);
}
