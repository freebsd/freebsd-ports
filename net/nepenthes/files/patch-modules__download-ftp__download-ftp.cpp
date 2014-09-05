--- modules/download-ftp/download-ftp.cpp.orig
+++ modules/download-ftp/download-ftp.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: download-ftp.cpp 550 2006-05-04 10:25:35Z common $ */
 
-#include <ctype.h>
+#include <cstdlib>
+#include <cctype>
 
 #include "download-ftp.hpp"
 #include "CTRLDialogue.hpp"
