--- include/salt/vtypes.h.orig	Fri Jul  2 00:42:34 2004
+++ include/salt/vtypes.h	Fri Jul  2 00:50:40 2004
@@ -56,7 +56,7 @@
 typedef short					sw_short;
 typedef unsigned short		sw_ushort;
 typedef long					sw_long;
-typedef unsigned long		sw_ulong;
+typedef unsigned int		sw_ulong;
 typedef unsigned char	*	sw_octets;
 typedef char				*	sw_string;
 #if !defined(__VXWORKS__) || defined(__cplusplus)
@@ -139,8 +139,11 @@
 
 #elif defined(__FreeBSD__) || defined(__NetBSD__)
 
-#	if defined(i386)
+#include <machine/endian.h>
+#if BYTE_ORDER == LITTLE_ENDIAN
 #		define SW_ENDIAN		1
+#elif BYTE_ORDER == BIG_ENDIAN
+#		define SW_ENDIAN		0
 #	else
 #		error "CPU unknown"
 #	endif
