--- tensor.h.orig	2022-05-15 02:44:06 UTC
+++ tensor.h
@@ -3,6 +3,7 @@
 #pragma once
 
 #include <ostream>
+#include <memory>
 #include <vector>
 
 typedef std::vector<unsigned> TensorShape;
