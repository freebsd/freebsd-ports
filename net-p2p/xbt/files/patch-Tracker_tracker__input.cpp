--- Tracker/tracker_input.cpp.orig	2023-01-10 00:32:43 UTC
+++ Tracker/tracker_input.cpp
@@ -1,9 +1,9 @@
 #include "stdafx.h"
 #include "tracker_input.h"
 
-static std::array<char, 16> to_ipv6(uint32_t v)
+static std::array<signed char, 16> to_ipv6(uint32_t v)
 {
-	std::array<char, 16> res = { 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0 };
+	std::array<signed char, 16> res = { 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0 };
 	memcpy(&res[12], &v, 4);
 	return res;
 }
