Index: dspam/src/libdspam.c
===================================================================
RCS file: /usr/local/cvsroot/dspam/src/libdspam.c,v
retrieving revision 1.144
retrieving revision 1.145
diff -u -r1.144 -r1.145
--- src/libdspam.c	24 Nov 2005 14:09:12 -0000	1.144
+++ src/libdspam.c	13 Dec 2005 16:59:45 -0000	1.145
@@ -1,4 +1,4 @@
-/* $Id: libdspam.c,v 1.144 2005/11/24 14:09:12 jonz Exp $ */
+/* $Id: libdspam.c,v 1.145 2005/12/13 16:59:45 jonz Exp $ */
 
 /*
  DSPAM
@@ -892,7 +892,9 @@
   /* Apply Bayesian Noise Reduction */
   if (CTX->flags & DSF_NOISE)
   {
-    _ds_apply_bnr(CTX, diction);
+    ds_diction_t p = _ds_apply_bnr(CTX, diction);
+    if (p) 
+      ds_diction_destroy(p);
   }
 
   if (CTX->flags & DSF_WHITELIST)
