--- tensor.h.orig	2020-08-13 20:43:40 UTC
+++ tensor.h
@@ -1,5 +1,6 @@
 // Copyright (C) 2020 by Yuri Victorovich. All rights reserved.
 
+#include <memory>
 #include <vector>
 
 typedef std::vector<unsigned> TensorShape;
