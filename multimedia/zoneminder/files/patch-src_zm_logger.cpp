--- src/zm_logger.cpp.orig	2011-06-28 15:07:35.000000000 +0400
+++ src/zm_logger.cpp	2012-02-03 01:42:44.626851425 +0400
@@ -33,6 +33,7 @@
 #include <signal.h>
 #include <stdarg.h>
 #include <errno.h>
+#include <sys/thr.h>
 
 bool Logger::smInitialised = false;
 Logger *Logger::smInstance = 0;
@@ -515,8 +516,12 @@
     #endif
 
         pid_t tid;
+	long lwpid;
+	thr_self(&lwpid);
+	tid = lwpid;
+
 #ifdef HAVE_SYSCALL
-        if ( (tid = syscall(SYS_gettid)) < 0 ) // Thread/Process id
+        if (tid < 0 ) // Thread/Process id
 #endif // HAVE_SYSCALL
         tid = getpid(); // Process id
 
