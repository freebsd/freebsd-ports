--- lib/utilities.h.orig	2021-02-09 17:20:43 UTC
+++ lib/utilities.h
@@ -127,6 +127,10 @@ static inline void rm_sys_close(int fd) {
     }
 }
 
+#ifndef HAVE_LSEEK64
+#define lseek64 lseek
+#endif
+
 static inline gint64 rm_sys_preadv(int fd, const struct iovec *iov, int iovcnt,
                                    RmOff offset) {
 #if RM_IS_APPLE || RM_IS_CYGWIN
