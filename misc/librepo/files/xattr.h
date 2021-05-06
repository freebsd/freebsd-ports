
int fsetxattr(int fd, const char *name, const void *value, size_t size, int flags);
ssize_t flistxattr(int fd, char *namebuf, size_t size);
ssize_t fgetxattr(int fd, const char *name, void *value, size_t size);
int fremovexattr(int fd, const char *name);
