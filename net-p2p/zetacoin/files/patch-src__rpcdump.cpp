--- src/rpcdump.cpp.orig	2014-01-16 19:35:10.000000000 +0000
+++ src/rpcdump.cpp	2014-01-16 19:35:24.000000000 +0000
@@ -27,7 +27,7 @@
 }
 
 int64 static DecodeDumpTime(const std::string &str) {
-    static const boost::posix_time::time_input_facet facet("%Y-%m-%dT%H:%M:%SZ");
+    static boost::posix_time::time_input_facet facet("%Y-%m-%dT%H:%M:%SZ");
     static const boost::posix_time::ptime epoch = boost::posix_time::from_time_t(0);
     const std::locale loc(std::locale::classic(), &facet);
     std::istringstream iss(str);
