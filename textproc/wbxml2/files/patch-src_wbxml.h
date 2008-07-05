--- src/wbxml.h.orig	2006-07-11 21:47:44.000000000 +1000
+++ src/wbxml.h	2008-06-15 06:58:54.000000000 +1000
@@ -285,6 +285,7 @@
     WBXMLVersion wbxml_version; /**< WBXML Version */
     WB_BOOL keep_ignorable_ws;  /**< Keep Ignorable Whitespaces (Default: FALSE) */
     WB_BOOL use_strtbl;         /**< Generate String Table (Default: TRUE) */
+    WB_BOOL produce_anonymous;  /**< Produce an anonymous document (Default: FALSE) */
 } WBXMLGenWBXMLParams;
 
