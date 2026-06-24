--- src/lib/dns/rdataclass.cc.orig	2026-03-13 15:55:30 UTC
+++ src/lib/dns/rdataclass.cc
@@ -41,6 +41,7 @@
 
 #include <boost/lexical_cast.hpp>
 #include <boost/shared_ptr.hpp>
+#include <boost/static_assert.hpp>
 
 using namespace isc::util;
 using namespace isc::util::encode;
