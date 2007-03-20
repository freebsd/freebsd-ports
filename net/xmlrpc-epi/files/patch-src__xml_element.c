--- src/xml_element.c.orig	Thu May 23 19:46:51 2002
+++ src/xml_element.c	Tue Mar 20 23:15:55 2007
@@ -170,7 +170,7 @@
 
       Q_Destroy(&root->children);
       Q_Destroy(&root->attrs);
-      my_free((char*)root->name);
+      my_free(root->name);
       simplestring_free(&root->text);
       my_free(root);
    }
