--- ArticleDownloader.cpp.orig	Fri Apr  2 18:55:19 2004
+++ ArticleDownloader.cpp	Sat Apr 17 22:57:09 2004
@@ -27,6 +27,8 @@
 #include <config.h>
 #endif
 
+#include <unistd.h>
+
 #include "ArticleDownloader.h"
 #include "Decoder.h"
 #include "global.h"
