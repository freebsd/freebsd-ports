--- src/common/mcl_osdep.h.orig	Tue Jul 22 19:37:39 2003
+++ src/common/mcl_osdep.h	Wed Oct 15 16:11:46 2003
@@ -30,7 +30,7 @@
 /*
  * bit field order is compiler/OS dependant
  */
-#if defined(LINUX) || defined(WIN32)
+#if defined(LINUX) || defined(WIN32) || defined(FREEBSD)
 #define _BIT_FIELDS_LTOH
 #undef _BIT_FIELDS_HTOL
 
@@ -44,7 +44,7 @@
 /*
  * sighandler
  */
-#if defined(LINUX)
+#if defined(LINUX) || defined(FREEBSD)
 	/* On Linux systems, signal handlers must be of __sighandler_t type */
 #define	sighandler_t	__sighandler_t
 
@@ -63,9 +63,9 @@
 #define u_int16_t	ushort_t	/* or uint16_t */
 #define u_int32_t	uint_t		/* or uint32_t */
 
-#elif defined (WIN32) 
+#elif defined (WIN32) || defined (FREEBSD)
 
-/* u_xxx absent from WIN32! */
+/* u_xxx absent from WIN32 and ulong absent from FreeBSD! */
 #define u_int8_t	unsigned char		/* or uint8_t */
 #define u_int16_t	unsigned short		/* or uint16_t */
 #define u_int32_t	unsigned int		/* or uint32_t */
