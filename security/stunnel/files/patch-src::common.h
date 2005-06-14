--- src/common.h.orig	Sat Apr 23 13:40:10 2005
+++ src/common.h	Tue Jun 14 08:27:11 2005
@@ -38,17 +38,44 @@
 #endif
 
 /* threads model */
+#if defined(FORCE_THREADING_MODEL)
+
+#undef USE_UCONTEXT
+#undef USE_PTHREAD
+#undef USE_FORK
+
+#ifdef FORCE_UCONTEXT
+#define USE_UCONTEXT
+#else
+#ifdef FORCE_PTHREAD
+#define USE_PTHREAD
+#else
+#define USE_FORK
+#endif	/* FORCE_PTHREAD */
+#endif	/* FORCE_UCONTEXT */
+
+#else	/* FORCE_THREADING_MODEL */
+
 #if HAVE_UCONTEXT_H && HAVE_GETCONTEXT && HAVE_POLL
 #define USE_UCONTEXT
-#include <ucontext.h>
 #elif HAVE_PTHREAD_H && HAVE_LIBPTHREAD
 #define USE_PTHREAD
+#else
+#define USE_FORK
+#endif
+
+#endif	/* FORCE_THREADING_MODEL */
+
+#ifdef USE_UCONTEXT
+#include <sys/types.h>
+#include <ucontext.h>
+#endif
+
+#ifdef USE_PTHREAD
 #include <pthread.h>
 #define THREADS
 #define _REENTRANT
 #define _THREAD_SAFE
-#else
-#define USE_FORK
 #endif
 
 /* TCP wrapper */
