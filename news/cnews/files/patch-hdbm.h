--- include/hdbm.h.orig	1991-11-07 21:44:14.000000000 +0100
+++ include/hdbm.h	2011-05-12 16:16:36.000000000 +0200
@@ -13,6 +13,6 @@
 #endif
 
 extern HASHTABLE *hdbmcreate();
-extern hdbmdestroy(), hdbmwalk();
+extern void hdbmdestroy(), hdbmwalk();
 extern int hdbmstore(), hdbmdelete();
 extern HDBMDATUM hdbmfetch(), hdbmentry();
