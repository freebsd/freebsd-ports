--- libjs/jsprf.c.orig	Sun Feb  1 01:57:53 2004
+++ libjs/jsprf.c	Sun Feb  1 01:58:04 2004
@@ -613,8 +613,6 @@
             continue;
         }
 
-        VARARGS_ASSIGN(nas[cn].ap, ap);
-
         switch( nas[cn].type ){
         case TYPE_INT16:
         case TYPE_UINT16:
