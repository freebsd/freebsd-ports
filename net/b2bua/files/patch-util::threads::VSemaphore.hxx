
$FreeBSD$

--- util/threads/VSemaphore.hxx.orig	Tue Jun 25 20:01:25 2002
+++ util/threads/VSemaphore.hxx	Fri Apr  4 13:06:17 2003
@@ -54,7 +54,7 @@
 static const char* const VSemaphore_hxx_version =
     "$Id: VSemaphore.hxx,v 1.4 2002/06/25 17:01:25 bko Exp $";
 
-#ifdef WIN32
+#if defined(WIN32) || defined(__FreeBSD__)
 #include <pthread.h>
 #endif
 
