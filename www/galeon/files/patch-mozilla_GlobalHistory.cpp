--- src/mozilla/GlobalHistory.cpp.orig	Tue Oct 14 17:43:42 2003
+++ src/mozilla/GlobalHistory.cpp	Tue Oct 14 17:44:08 2003
@@ -108,7 +108,7 @@
 	return NS_OK;
 }
 
-#if MOZILLA_SNAPSHOT > 9
+#if MOZILLA_SNAPSHOT >= 9
 NS_IMETHODIMP GlobalHistory::SetLastPageVisited(const char * aLastPageVisited)
 {
 	mLastPageVisited.Assign(aLastPageVisited);
