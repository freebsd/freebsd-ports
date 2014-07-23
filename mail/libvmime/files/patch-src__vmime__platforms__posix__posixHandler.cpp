--- src/vmime/platforms/posix/posixHandler.cpp.orig	2014-07-22 15:24:26.000000000 +0200
+++ src/vmime/platforms/posix/posixHandler.cpp	2014-07-22 15:59:33.000000000 +0200
@@ -41,6 +41,7 @@
 #include <errno.h>
 
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/stat.h>
 
 #if VMIME_HAVE_SYSCALL
@@ -238,7 +239,9 @@
 #elif VMIME_HAVE_SYSCALL && VMIME_HAVE_SYSCALL_GETTID
 	return static_cast <unsigned int>(::syscall(SYS_gettid));
 #else
-	#error We have no implementation of getThreadId() for this platform!
+	long id;
+	::syscall(SYS_thr_self, &id);
+	return static_cast <unsigned int>(id);
 #endif
 }
 
