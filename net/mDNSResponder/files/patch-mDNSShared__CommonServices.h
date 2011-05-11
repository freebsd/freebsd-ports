--- mDNSShared/CommonServices.h.orig	2009-08-11 09:13:47.000000000 +0800
+++ mDNSShared/CommonServices.h	2011-01-11 11:51:28.000000000 +0800
@@ -54,6 +54,15 @@
 	#endif
 #endif
 
+// FreeBSD
+
+#if( !defined( TARGET_OS_FREEBSD ) )
+	#if( defined( __FreeBSD__ ) )
+		#define	TARGET_OS_FREEBSD		1
+	#else
+		#define	TARGET_OS_FREEBSD		0
+	#endif
+#endif
 // Linux
 
 #if( !defined( TARGET_OS_LINUX ) )
@@ -90,7 +99,7 @@
 	
 	// No predefined macro for VxWorks so just assume VxWorks if nothing else is set.
 	
-	#if( !macintosh && !__MACH__  && !defined( __linux__ ) && !defined ( __SVR4 ) && !defined ( __sun ) && !defined( __PALMOS_TRAPS__ ) && !defined( __PALMOS_ARMLET__ ) && !defined( _WIN32 ) )
+	#if( !macintosh && !__MACH__  && !defined( __FreeBSD__ ) && !defined( __linux__ ) && !defined ( __SVR4 ) && !defined ( __sun ) && !defined( __PALMOS_TRAPS__ ) && !defined( __PALMOS_ARMLET__ ) && !defined( _WIN32 ) )
 		#define	TARGET_OS_VXWORKS		1
 	#else
 		#define	TARGET_OS_VXWORKS		0
@@ -179,6 +188,15 @@
 	#include	<libkern/OSTypes.h>
 	#include	<sys/types.h>
 	
+#elif( TARGET_OS_FREEBSD )
+
+	// FreeBSD
+	#include	<stdint.h>
+	#include	<pthread.h>
+	#include	<netinet/in.h>
+	#include	<arpa/inet.h>
+	#include	<sys/socket.h>
+
 #elif( TARGET_OS_LINUX )
 	
 	// Linux
@@ -455,7 +473,7 @@
 // - Windows
 
 #if( TARGET_LANGUAGE_C_LIKE )
-	#if( !defined(_SSIZE_T) && ( TARGET_OS_WIN32 || !defined( _BSD_SSIZE_T_DEFINED_ ) ) && !TARGET_OS_LINUX && !TARGET_OS_VXWORKS && !TARGET_OS_MAC)
+	#if( !defined(_SSIZE_T) && ( TARGET_OS_WIN32 || !defined( _BSD_SSIZE_T_DEFINED_ ) ) && !TARGET_OS_FREEBSD && !TARGET_OS_LINUX && !TARGET_OS_VXWORKS && !TARGET_OS_MAC)
 		typedef int						ssize_t;
 	#endif
 #endif
