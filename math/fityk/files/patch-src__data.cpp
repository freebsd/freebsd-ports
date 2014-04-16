--- ./src/data.cpp.orig	2011-06-04 02:07:28.000000000 +0200
+++ ./src/data.cpp	2014-04-08 14:55:51.806605797 +0200
@@ -299,7 +299,7 @@
 int Data::count_blocks(const string& fn,
                        const string& format, const string& options)
 {
-    shared_ptr<const xylib::DataSet> xyds(
+    boost::shared_ptr<const xylib::DataSet> xyds(
                         xylib::cached_load_file(fn, format, tr_opt(options)));
     return xyds->get_block_count();
 }
@@ -308,7 +308,7 @@
                         const string& format, const string& options,
                         int first_block)
 {
-    shared_ptr<const xylib::DataSet> xyds(
+    boost::shared_ptr<const xylib::DataSet> xyds(
                         xylib::cached_load_file(fn, format, tr_opt(options)));
     return xyds->get_block(first_block)->get_column_count();
 }
@@ -324,7 +324,7 @@
 
     string block_name;
     try {
-        shared_ptr<const xylib::DataSet> xyds(
+        boost::shared_ptr<const xylib::DataSet> xyds(
                         xylib::cached_load_file(fn, format, tr_opt(options)));
         clear(); //removing previous file
         vector<int> bb = blocks.empty() ? vector1(0) : blocks;
