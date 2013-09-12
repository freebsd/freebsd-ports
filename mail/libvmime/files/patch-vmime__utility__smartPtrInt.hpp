--- ./vmime/utility/smartPtrInt.hpp.orig	2009-09-06 05:10:27.000000000 -0700
+++ ./vmime/utility/smartPtrInt.hpp	2013-09-12 11:22:28.695743913 -0700
@@ -28,6 +28,8 @@
 #include "vmime/config.hpp"
 #include "vmime/utility/smartPtr.hpp"
 
+#include <pthread.h>
+
 
 namespace vmime {
 namespace utility {
