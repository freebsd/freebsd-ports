--- src/mozilla/GaleonWrapper.cpp.orig	Mon Sep 16 12:42:40 2002
+++ src/mozilla/GaleonWrapper.cpp	Mon Sep 16 12:42:47 2002
@@ -182,7 +182,7 @@
 	}
 	else
 	{
-#if MOZILLA_SNAPSHOT > 1
+#if MOZILLA_SNAPSHOT > 0
 		result = print->PrintPreview(options, nsnull, nsnull);
 #else
 		result = print->PrintPreview(options);
