--- bidwatcher.cpp.orig	Mon Aug 30 18:03:34 2004
+++ bidwatcher.cpp	Sat Oct 30 20:00:20 2004
@@ -2972,2 +2972,2 @@
-	else if (strstr(browserPATH, "mozilla") != NULL) {
-		// Try to find mozilla.
+	else if (strcasestr(browserPATH, "mozilla") != NULL || strcasestr(browserPATH, "fire") != NULL) {
+		// Try to find mozilla, firefox, or firebird.
