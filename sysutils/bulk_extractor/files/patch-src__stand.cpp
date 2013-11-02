--- ./src/stand.cpp.orig	2012-12-12 15:36:14.000000000 +0000
+++ ./src/stand.cpp	2013-10-19 13:09:32.000000000 +0000
@@ -91,7 +91,7 @@
 
     if(argc!=1) usage();
 
-    opt_scan_bulk_block_size = stoi(be_config["bulk_block_size"]);
+    opt_scan_bulk_block_size = be13stoi(be_config["bulk_block_size"]);
 
     feature_file_names_t feature_file_names;
     enable_feature_recorders(feature_file_names);
