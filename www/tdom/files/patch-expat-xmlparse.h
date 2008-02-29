--- ../expat/xmlparse.c	2007-07-30 20:16:28.000000000 -0400
+++ ../expat/xmlparse.c	2008-02-14 14:20:27.000000000 -0500
@@ -1476,5 +1476,5 @@
     const char *end;
     int nLeftOver;
-    enum XML_Error result;
+    enum XML_Error result = XML_STATUS_ERROR;
     parseEndByteIndex += len;
     positionPtr = s;
@@ -1500,4 +1500,6 @@
           return result;
         }
+      case XML_FINISHED:
+	/* nothing */;
       }
     }
