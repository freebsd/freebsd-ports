--- misc/os_spec.h.orig	2010-10-13 23:58:52.000000000 +0200
+++ misc/os_spec.h	2011-03-04 15:31:57.000000000 +0100
@@ -601,7 +601,7 @@ typedef unsigned char		BYTE;
 
 #if defined( __WINDOWS__ ) || \
 	( defined( __UNIX__ ) && \
-	  ( ( defined( sun ) && OSVERSION > 4 ) || defined( __linux__ ) || \
+	  ( ( defined( sun ) && OSVERSION > 4 ) || defined( __linux__ ) || defined(__FreeBSD__) || \
 		defined( _AIX ) || ( defined( __APPLE__ ) && !defined( __MAC__ ) ) ) )
   #define DYNAMIC_LOAD
 
