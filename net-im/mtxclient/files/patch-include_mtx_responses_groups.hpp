--- include/mtx/responses/groups.hpp.orig	2019-03-24 20:45:03 UTC
+++ include/mtx/responses/groups.hpp
@@ -1,6 +1,6 @@
 #pragma once
 
-#include "json.hpp"
+#include <nlohmann/json.hpp>
 
 namespace mtx {
 namespace responses {
