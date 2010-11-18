--- libinstaller/syslxopt.h.orig	2010-11-16 14:53:01.569209804 +0100
+++ libinstaller/syslxopt.h	2010-11-16 14:53:08.769406093 +0100
@@ -18,6 +18,8 @@
     int install_mbr;
     int activate_partition;
     const char *bootsecfile;
+    int verbose;
+    const char *bimage;
 };
 
 enum long_only_opt {
