--- opensshlib/openbsd-compat.h.orig	2019-08-24 22:25:32 UTC
+++ opensshlib/openbsd-compat.h
@@ -95,7 +95,7 @@ void *recallocarray(void *, size_t, size_t, size_t);
 #  define realpath(x, y) _ssh_compat_realpath(x, y)
 # endif
 
-char *realpath(const char *path, char *resolved);
+static char *realpath(const char *path, char *resolved);
 #endif
 
 #ifndef HAVE_RRESVPORT_AF
