--- lib/xmlparse.c.orig	2009-12-08 10:20:08.866482591 +0900
+++ lib/xmlparse.c	2009-12-08 10:20:23.038667874 +0900
@@ -3725,7 +3725,6 @@
         return XML_ERROR_NO_ELEMENTS;
       default:
         tok = -tok;
-        next = end;
         break;
       }
     }
