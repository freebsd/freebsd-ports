--- ea_restore.c.orig	Sat Feb 10 16:15:31 2007
+++ ea_restore.c	Sat Feb 10 16:16:12 2007
@@ -715,6 +715,9 @@
     to->doc_comment = NULL;
 #endif
 #endif
+#ifdef ZEND_ENGINE_2_2
+    to->ce = EAG(class_entry);
+#endif
 	return to;
 }
 #endif
