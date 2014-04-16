--- ./src/wxgui/dload.cpp.orig	2011-06-03 20:36:28.000000000 +0200
+++ ./src/wxgui/dload.cpp	2014-04-08 14:56:41.794602545 +0200
@@ -53,11 +53,11 @@
     virtual void draw(wxDC &dc, bool);
     void load_dataset(string const& filename, string const& filetype,
                       string const& options);
-    shared_ptr<const xylib::DataSet> get_data() const { return data_; }
+    boost::shared_ptr<const xylib::DataSet> get_data() const { return data_; }
     void make_outdated() { data_updated_ = false; }
 
 private:
-    shared_ptr<const xylib::DataSet> data_;
+    boost::shared_ptr<const xylib::DataSet> data_;
     bool data_updated_; // if false, draw() doesn't do anything (plot is clear)
 };
 
