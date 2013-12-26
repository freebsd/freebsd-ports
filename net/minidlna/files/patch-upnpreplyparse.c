--- upnpreplyparse.c.orig	2013-11-02 02:06:41.000000000 +0100
+++ upnpreplyparse.c	2013-12-16 20:12:25.595454171 +0100
@@ -122,7 +122,7 @@
 {
     struct NameValueParserData pdata;
     struct NameValue * nv;
-    ParseNameValue(buffer, bufsize, &pdata);
+    ParseNameValue(buffer, bufsize, &pdata, XML_STORE_EMPTY_FL);
     for(nv = pdata.head.lh_first;
         nv != NULL;
         nv = nv->entries.le_next)
