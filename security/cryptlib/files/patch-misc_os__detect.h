--- misc/os_detect.h.orig	2023-03-20 10:08:54 UTC
+++ misc/os_detect.h
@@ -629,7 +629,7 @@
 
 #if defined( __WINDOWS__ ) || \
 	( defined( __UNIX__ ) && \
-	  ( ( defined( sun ) && OSVERSION > 4 ) || defined( __linux__ ) || \
+	  ( ( defined( sun ) && OSVERSION > 4 ) || defined( __linux__ ) || defined( __FreeBSD__ ) || \
 		defined( _AIX ) || ( defined( __APPLE__ ) && !defined( __MAC__ ) ) ) ) || \
 	defined( __ANDROID__ )
   #define DYNAMIC_LOAD
