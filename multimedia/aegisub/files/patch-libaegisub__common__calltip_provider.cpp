--- libaegisub/common/calltip_provider.cpp.orig	2014-08-05 20:40:25.000000000 +0900
+++ libaegisub/common/calltip_provider.cpp	2014-08-05 20:40:42.000000000 +0900
@@ -19,6 +19,7 @@
 #include "libaegisub/ass/dialogue_parser.h"
 
 #include <algorithm>
+#include <cstring>
 
 namespace {
 struct proto_lit {
