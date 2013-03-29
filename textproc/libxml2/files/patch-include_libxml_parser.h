--- include/libxml/parser.h.orig	2012-05-15 03:09:43.000000000 +0000
+++ include/libxml/parser.h	2013-03-13 09:42:57.000000000 +0000
@@ -310,6 +310,7 @@
     xmlParserNodeInfo *nodeInfoTab;   /* array of nodeInfos */
 
     int                input_id;      /* we need to label inputs */
+    unsigned long      sizeentcopy;  /* volume of entity copy */
 };
 
 /**
