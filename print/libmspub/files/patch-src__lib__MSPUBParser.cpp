--- ./src/lib/MSPUBParser.cpp.orig	2012-08-21 11:40:41.000000000 +0200
+++ ./src/lib/MSPUBParser.cpp	2012-12-18 13:01:33.120360905 +0100
@@ -1151,7 +1151,7 @@
   ParagraphStyle ret;
 
   bool isList = false;
-  uint32_t bulletChar = '\u0000';
+  uint32_t bulletChar = 0;
   NumberingType numberingType = STANDARD_WESTERN;
   NumberingDelimiter numberingDelimiter = NO_DELIMITER;
   boost::optional<unsigned> numberIfRestarted;
@@ -1256,7 +1256,7 @@
   }
   if (isList)
   {
-    if (bulletChar != '\u0000')
+    if (bulletChar)
     {
       ret.m_listInfo = ListInfo(bulletChar);
     }
