--- mod_index_rss.c.orig	Tue Jul 22 04:37:54 2003
+++ mod_index_rss.c	Tue Jul 22 04:39:22 2003
@@ -11,18 +11,18 @@
 
 #define TIME_FORMAT "%a %b %d %H:%M:%S %Y"
 /* This is the XML header file */
-#define HEADER "<?xml version=\"1.0\" encoding=\"UTF-8\"?>
-
-<!DOCTYPE rss PUBLIC \"-//Netscape Communications//DTD RSS 0.91//EN\"
-            \"http://www.scripting.com/dtd/rss-0_91.dtd\">
-
-<rss version=\"0.91\">
-
-<channel>
+#define HEADER "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\
+\n\
+<!DOCTYPE rss PUBLIC \"-//Netscape Communications//DTD RSS 0.91//EN\"\n\
+            \"http://www.scripting.com/dtd/rss-0_91.dtd\">\n\
+\n\
+<rss version=\"0.91\">\n\
+\n\
+<channel>\n\
 "
 
-#define FOOTER "</channel>
-</rss>
+#define FOOTER "</channel>\n\
+</rss>\n\
 "
 
 
