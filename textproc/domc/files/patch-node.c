--- src/node.c.orig	Tue Aug 17 13:26:21 2004
+++ src/node.c	Tue Aug 17 13:27:55 2004
@@ -381,6 +381,7 @@
         case DOM_DOCUMENT_NODE:
         case DOM_DOCUMENT_TYPE_NODE:
         case DOM_NOTATION_NODE:
+	    break;
     }
     free(node);
 }
