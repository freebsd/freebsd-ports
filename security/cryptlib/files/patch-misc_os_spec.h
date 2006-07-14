--- misc/os_spec.h.orig	Fri Jul 14 08:31:41 2006
+++ misc/os_spec.h	Fri Jul 14 08:31:18 2006
@@ -481,7 +481,7 @@
 
 #if defined( __WINDOWS__ ) || \
 	( defined( __UNIX__ ) && \
-	  ( ( defined( sun ) && OSVERSION > 4 ) || defined( __linux__ ) || \
+	  ( ( defined( sun ) && OSVERSION > 4 ) || defined( __linux__ ) || defined(__FreeBSD__) || \
 		defined( _AIX ) || ( defined( __APPLE__ ) && !defined( __MAC__ ) ) ) )
   #define DYNAMIC_LOAD
 
