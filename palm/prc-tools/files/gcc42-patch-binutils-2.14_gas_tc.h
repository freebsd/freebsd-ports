--- binutils-2.14/gas/tc.h.ORIG	2007-10-17 11:36:37.000000000 -0400
+++ binutils-2.14/gas/tc.h	2007-10-17 11:37:19.000000000 -0400
@@ -24,23 +24,6 @@
 
 extern const pseudo_typeS md_pseudo_table[];
 
-/* JF moved this here from as.h under the theory that nobody except MACHINE.c
-   and write.c care about it anyway.  */
-
-struct relax_type
-{
-  /* Forward reach. Signed number. > 0.  */
-  long rlx_forward;
-  /* Backward reach. Signed number. < 0.  */
-  long rlx_backward;
-
-  /* Bytes length of this address.  */
-  unsigned char rlx_length;
-
-  /* Next longer relax-state.  0 means there is no 'next' relax-state.  */
-  relax_substateT rlx_more;
-};
-
 typedef struct relax_type relax_typeS;
 
 extern const int md_reloc_size;	/* Size of a relocation record */
