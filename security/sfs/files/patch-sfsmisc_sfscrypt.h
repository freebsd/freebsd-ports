--- sfsmisc/sfscrypt.h.orig	Mon Oct 11 16:43:34 2004
+++ sfsmisc/sfscrypt.h	Mon Oct 11 16:39:35 2004
@@ -89,7 +89,6 @@
   virtual u_char get_bad_opts () const { return (SFS_DECRYPT | SFS_SIGN); }
   bool get_opt (u_char o) const { return (opts & o); }
   const sfs_keytype ktype;
-  const int eksb_id;
   const u_char opts;
 };
 
