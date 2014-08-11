--- libaegisub/common/color.cpp.orig	2014-08-05 20:04:54.000000000 +0900
+++ libaegisub/common/color.cpp	2014-08-05 20:06:27.000000000 +0900
@@ -18,6 +18,13 @@
 
 #include "libaegisub/format.h"
 
+#ifdef _LIBCPP_VERSION
+#define TO_STRING(x) std::to_string(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_STRING(x) boost::lexical_cast<std::string>(x)
+#endif
+
 namespace agi {
 
 Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
@@ -37,7 +44,7 @@
 }
 
 std::string Color::GetSsaFormatted() const {
-	return std::to_string((a << 24) + (b << 16) + (g << 8) + r);
+	return TO_STRING((a << 24) + (b << 16) + (g << 8) + r);
 }
 
 std::string Color::GetHexFormatted(bool rgba) const {
