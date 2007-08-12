--- src/xmlpull/XmlPullParser.h.orig	2007-08-12 13:31:16.000000000 +0200
+++ src/xmlpull/XmlPullParser.h	2007-08-12 13:32:11.000000000 +0200
@@ -110,7 +110,7 @@
   int next ();
   int nextToken ();
   int nextTag ();
-  void XmlPullParser::prevTag();
+  void prevTag();
 
   //----------------------------------------------------------------------
   // utility methods to make XML parsing easier ...
