--- src/vmime/platforms/posix/posixHandler.cpp.orig	2017-01-03 20:00:08 UTC
+++ src/vmime/platforms/posix/posixHandler.cpp
@@ -41,6 +41,7 @@
 #include <errno.h>
 
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/stat.h>
 
 #if VMIME_HAVE_SYSCALL
@@ -240,7 +241,9 @@ unsigned int posixHandler::getThreadId()
 #elif VMIME_HAVE_SYSCALL && VMIME_HAVE_SYSCALL_GETTID
 	return static_cast <unsigned int>(::syscall(SYS_gettid));
 #else
-	#error We have no implementation of getThreadId() for this platform!
+	long id;
+	::syscall(SYS_thr_self, &id);
+	return static_cast <unsigned int>(id);
 #endif
 }
 
