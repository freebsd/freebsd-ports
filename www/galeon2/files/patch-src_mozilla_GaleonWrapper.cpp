--- src/mozilla/GaleonWrapper.cpp.orig	Wed Sep 11 16:59:41 2002
+++ src/mozilla/GaleonWrapper.cpp	Wed Sep 11 17:00:49 2002
@@ -182,7 +182,7 @@
 	}
 	else
 	{
-#if MOZILLA_SNAPSHOT > 1
+#if MOZILLA_SNAPSHOT >= 1
 		result = print->PrintPreview(options, nsnull, nsnull);
 #else
 		result = print->PrintPreview(options);
