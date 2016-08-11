--- expat/xmlparse.c.orig	2007-07-31 00:16:28 UTC
+++ expat/xmlparse.c
@@ -1475,7 +1475,7 @@ XML_Parse(XML_Parser parser, const char 
   else if (bufferPtr == bufferEnd) {
     const char *end;
     int nLeftOver;
-    enum XML_Error result;
+    enum XML_Error result = XML_STATUS_ERROR;
     parseEndByteIndex += len;
     positionPtr = s;
     ps_finalBuffer = (XML_Bool)isFinal;
@@ -1499,6 +1499,8 @@ XML_Parse(XML_Parser parser, const char 
           ps_parsing = XML_FINISHED;
           return result;
         }
+      case XML_FINISHED:
+	/* nothing */;
       }
     }
 
