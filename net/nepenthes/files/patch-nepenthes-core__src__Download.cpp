--- nepenthes-core/src/Download.cpp.orig
+++ nepenthes-core/src/Download.cpp
@@ -27,6 +27,7 @@
 
 /* $Id: Download.cpp 2099 2005-10-23 22:12:52Z common $ */
 
+#include <cstring>
 #include "Download.hpp"
 #include "DownloadUrl.hpp"
 #include "DownloadBuffer.hpp"
