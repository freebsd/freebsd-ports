--- embed/mozilla/mozilla-embed-single.cpp.orig	Sun Jul 18 20:12:02 2004
+++ embed/mozilla/mozilla-embed-single.cpp	Sun Jul 18 20:22:34 2004
@@ -557,7 +557,11 @@
                 do_GetService ("@mozilla.org/network/protocol-proxy-service;1");
 	if (!pps) return;
 
+#if MOZILLA_SNAPSHOT >= 19
+	pps->ConfigureFromPAC (NS_LITERAL_CSTRING (url));
+#else
 	pps->ConfigureFromPAC (url);
+#endif
 }
 
 static GList *
