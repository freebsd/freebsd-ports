pthread_setname_np is implemented on top of PR_SET_NAME on Linux
and is also available on DragonFly, FreeBSD and Solaris

--- libavutil/thread.h.orig	2023-02-27 20:43:45 UTC
+++ libavutil/thread.h
@@ -196,6 +196,8 @@ static inline int ff_thread_setname(const char *name)
 {
 #if HAVE_PRCTL
     return AVERROR(prctl(PR_SET_NAME, name));
+#elif HAVE_PTHREADS
+    return AVERROR(pthread_setname_np(pthread_self(), name));
 #endif
 
     return AVERROR(ENOSYS);
