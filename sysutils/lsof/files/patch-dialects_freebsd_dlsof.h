--- dialects/freebsd/dlsof.h.orig	2018-06-03 13:24:20 UTC
+++ dialects/freebsd/dlsof.h
@@ -498,6 +498,12 @@ struct vop_advlock_args { int dummy; };	/* to pacify l
 
 #undef	bcopy		/* avoid _KERNEL conflict */
 #undef	bzero		/* avoid _KERNEL conflict */
+#undef  bcmp
+#undef  bcopy
+#undef  memcmp
+#undef  memmove
+#undef  memcpy
+#undef  memset
 #include <string.h>
 
 
