--- sfsmisc/afsnode.h.orig	Mon Oct 11 16:43:34 2004
+++ sfsmisc/afsnode.h	Mon Oct 11 16:39:35 2004
@@ -168,7 +168,7 @@
   void mkfattr3 (fattr3 *, sfs_aid aid);
   void setres (nfsstat err);
   void setres (nfspath path);
-  str readlink () const { return res.status ? str (NULL) : *res.data; }
+  str readlink () const { return res.status ? str (NULL) : str (*res.data); }
   bool resset () { return resok; }
 
   void nfs_readlink (svccb *sbp);
