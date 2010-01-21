--- mDNSShared/CommonServices.h.orig	2009-03-31 04:51:29.000000000 +0900
+++ mDNSShared/CommonServices.h	2010-01-21 16:07:24.000000000 +0900
@@ -92,6 +92,15 @@
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
@@ -128,7 +137,7 @@
 	
 	// No predefined macro for VxWorks so just assume VxWorks if nothing else is set.
 	
-	#if( !macintosh && !__MACH__  && !defined( __linux__ ) && !defined ( __SVR4 ) && !defined ( __sun ) && !defined( __PALMOS_TRAPS__ ) && !defined( __PALMOS_ARMLET__ ) && !defined( _WIN32 ) )
+	#if( !macintosh && !__MACH__  && !defined( __FreeBSD__ ) && !defined( __linux__ ) && !defined ( __SVR4 ) && !defined ( __sun ) && !defined( __PALMOS_TRAPS__ ) && !defined( __PALMOS_ARMLET__ ) && !defined( _WIN32 ) )
 		#define	TARGET_OS_VXWORKS		1
 	#else
 		#define	TARGET_OS_VXWORKS		0
@@ -217,6 +226,15 @@
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
@@ -493,7 +511,7 @@
 // - Windows
 
 #if( TARGET_LANGUAGE_C_LIKE )
-	#if( !defined(_SSIZE_T) && ( TARGET_OS_WIN32 || !defined( _BSD_SSIZE_T_DEFINED_ ) ) && !TARGET_OS_LINUX && !TARGET_OS_VXWORKS && !TARGET_OS_MAC)
+	#if( !defined(_SSIZE_T) && ( TARGET_OS_WIN32 || !defined( _BSD_SSIZE_T_DEFINED_ ) ) && !TARGET_OS_FREEBSD && !TARGET_OS_LINUX && !TARGET_OS_VXWORKS && !TARGET_OS_MAC)
 		typedef int						ssize_t;
 	#endif
 #endif
