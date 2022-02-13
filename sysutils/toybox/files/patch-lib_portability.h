--- lib/portability.h.orig	2021-12-02 04:45:52 UTC
+++ lib/portability.h
@@ -229,7 +229,7 @@ int posix_fallocate(int, off_t, off_t);
 #include <xlocale.h>
 #endif
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 static inline long statfs_bsize(struct statfs *sf) { return sf->f_iosize; }
 static inline long statfs_frsize(struct statfs *sf) { return sf->f_bsize; }
 #else
@@ -394,7 +394,7 @@ struct itimerspec {
 int timer_create(clock_t c, struct sigevent *se, timer_t *t);
 int timer_settime(timer_t t, int flags, struct itimerspec *new, void *old);
 #elif !CFG_TOYBOX_HASTIMERS
-#include <syscall.h>
+#include <sys/syscall.h>
 #include <signal.h>
 #include <time.h>
 int timer_create_wrap(clockid_t c, struct sigevent *se, timer_t *t);
