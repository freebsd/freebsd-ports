--- lib/xmlparse.c.orig	2007-05-08 11:25:35.000000000 +0900
+++ lib/xmlparse.c	2011-08-29 23:22:09.007745673 +0900
@@ -3703,6 +3703,9 @@
         return XML_ERROR_UNCLOSED_TOKEN;
       case XML_TOK_PARTIAL_CHAR:
         return XML_ERROR_PARTIAL_CHAR;
+      case -XML_TOK_PROLOG_S:
+        tok = -tok;
+        break;
       case XML_TOK_NONE:
 #ifdef XML_DTD
         /* for internal PE NOT referenced between declarations */
