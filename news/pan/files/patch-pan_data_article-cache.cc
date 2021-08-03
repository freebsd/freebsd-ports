--- pan/data/article-cache.cc.orig	2021-08-03 02:00:16 UTC
+++ pan/data/article-cache.cc
@@ -19,18 +19,15 @@
 
 #include <config.h>
 
-extern "C"
-{
-  #include <errno.h>
-  #include <sys/types.h>
-  #include <sys/stat.h>
-  #include <unistd.h>
-  #include <dirent.h>
+#include <errno.h>
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <unistd.h>
+#include <dirent.h>
 
-  #include <glib.h>
-  #include <glib/gi18n.h>
-  #include <gmime/gmime.h>
-}
+#include <glib.h>
+#include <glib/gi18n.h>
+#include <gmime/gmime.h>
 
 #include <pan/general/debug.h>
 #include <pan/general/file-util.h>
