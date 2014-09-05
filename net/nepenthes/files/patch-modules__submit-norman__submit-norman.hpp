--- modules/submit-norman/submit-norman.hpp.orig
+++ modules/submit-norman/submit-norman.hpp
@@ -28,6 +28,8 @@
  /* $Id: submit-norman.hpp 674 2006-10-23 01:31:53Z common $ */
 
 
+#include <cstring>
+
 #include <curl/curl.h>
 #include <curl/types.h> /* new for v7 */
 #include <curl/easy.h> /* new for v7 */
