--- mozilla/GlobalHistory.cpp.orig	Sun Oct 12 00:25:20 2003
+++ mozilla/GlobalHistory.cpp	Sun Oct 12 00:25:27 2003
@@ -99,7 +99,7 @@
 	return NS_OK;
 }
 
-#if MOZILLA_SNAPSHOT > 9
+#if MOZILLA_SNAPSHOT >= 9
 NS_IMETHODIMP MozGlobalHistory::SetLastPageVisited(const char *aLastPageVisited)
 {
 	mLastPageVisited.Assign(aLastPageVisited);
