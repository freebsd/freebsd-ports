--- ./src/wxgui/frame.cpp.orig	2011-06-08 16:26:42.000000000 +0200
+++ ./src/wxgui/frame.cpp	2014-04-08 14:56:30.967604263 +0200
@@ -966,7 +966,7 @@
     string cmd;
     if (count == 1) {
         string f = wx2s(paths[0]);
-        shared_ptr<const xylib::DataSet> d = xylib::cached_load_file(f, "", "");
+        boost::shared_ptr<const xylib::DataSet> d = xylib::cached_load_file(f, "", "");
         if (d->get_block_count() > 1) {
             wxArrayString choices;
             for (int i = 0; i < d->get_block_count(); ++i) {
