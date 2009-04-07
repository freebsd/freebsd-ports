--- encfs/FileUtils.cpp.orig	2008-04-14 03:13:23.000000000 +0400
+++ encfs/FileUtils.cpp	2009-03-21 04:33:29.000000000 +0300
@@ -61,6 +61,7 @@
 #include <boost/archive/xml_iarchive.hpp>
 #include <boost/archive/xml_oarchive.hpp>
 #include <boost/serialization/split_free.hpp>
+#include <boost/serialization/binary_object.hpp>
 
 using namespace rel;
 using namespace rlog;
