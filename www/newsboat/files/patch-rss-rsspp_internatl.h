--- rss/rsspp_internal.h.orig	2014-02-02 15:53:54.000000000 +0100
+++ rss/rsspp_internal.h	2014-02-02 15:52:36.000000000 +0100
@@ -9,6 +9,10 @@
 #include <rsspp.h>
 #include <tr1/memory>
 
+#ifdef _LIBCPP_VERSION
+namespace std { namespace tr1 = std; }
+#endif
+
 #define CONTENT_URI		"http://purl.org/rss/1.0/modules/content/"
 #define RDF_URI			"http://www.w3.org/1999/02/22-rdf-syntax-ns#"
 #define ITUNES_URI		"http://www.itunes.com/dtds/podcast-1.0.dtd"
