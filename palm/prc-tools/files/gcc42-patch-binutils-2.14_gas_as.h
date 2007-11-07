--- binutils-2.14/gas/as.h.ORIG	2007-10-17 11:36:16.000000000 -0400
+++ binutils-2.14/gas/as.h	2007-10-17 11:44:10.000000000 -0400
@@ -595,7 +595,19 @@
 struct expressionS;
 struct fix;
 typedef struct symbol symbolS;
-struct relax_type;
+struct relax_type
+{
+  /* Forward reach. Signed number. > 0.  */
+  long rlx_forward;
+  /* Backward reach. Signed number. < 0.  */
+  long rlx_backward;
+ 
+  /* Bytes length of this address.  */
+  unsigned char rlx_length;
+ 
+  /* Next longer relax-state.  0 means there is no 'next' relax-state.  */
+  relax_substateT rlx_more;
+};
 typedef struct frag fragS;
 
 #ifdef BFD_ASSEMBLER
