--- personality.c.orig	Thu Apr 14 16:07:26 2005
+++ personality.c	Thu Apr 14 12:57:11 2005
@@ -64,6 +64,8 @@
 #include "xprobe_assoc.h"
 #include "template.h"
 
+//#define DEBUG_XPROBE_STRUCT
+
 /* ET - Moved SPLAY_HEAD to personality.h so xprobe_assoc.c could use it. */
 int npersons;
 
@@ -1633,6 +1635,7 @@
 
 /* !!!DEBUG FUNCTION!!! */
 
+#ifdef DEBUG_XPROBE_STRUCT
 static void
 print_xprobe_struct(struct xp_fingerprint *pers)
 {
@@ -1693,6 +1696,7 @@
 	printf ("icmp_unreach_echoed_3bit_flags:    %d\n",
             pers->flags.icmp_unreach_echoed_3bit_flags);
 }
+#endif  /* DEBUG_XPROBE_STRUCT */
 
 void
 print_perstree(void)
@@ -1727,7 +1731,9 @@
 		/* Get a single fingerprint */
 		new_print = get_fprint (fp); 
 		if (new_print != NULL) {
-			/* print_xprobe_struct (new_print); */
+#ifdef DEBUG_XPROBE_STRUCT
+			print_xprobe_struct (new_print);
+#endif  /* DEBUG_XPROBE_STRUCT */
 			SPLAY_INSERT(xp_fprint_tree, &xp_fprints, new_print);
 			new_print = NULL;
 		}
