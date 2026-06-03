--- opennn/pch.h.orig	2026-04-08 05:32:16 UTC
+++ opennn/pch.h
@@ -55,7 +55,7 @@
 #include "../eigen/unsupported/Eigen/CXX11/Tensor"
 #include "../eigen/Eigen/src/Core/util/DisableStupidWarnings.h"
 
-#define OPENNN_CUDA // Comment this line to disable cuda files
+//#define OPENNN_CUDA // Comment this line to disable cuda files
 
 #ifdef OPENNN_CUDA
 
