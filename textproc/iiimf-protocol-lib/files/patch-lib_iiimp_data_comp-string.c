--- lib/iiimp/data/comp-string.c	Fri Nov  1 14:32:45 2002
+++ lib/iiimp/data/comp-string.c	Wed Feb 16 22:48:21 2005
@@ -63,9 +63,12 @@
 #if defined(lint) && defined(HAVE_NOTE_H)
     NOTE(ARGUNUSED(data_s))
 #endif /* lint && HAVE_NOTE_H */
-    if (NULL == str) return;
-    free(str->ptr);
-    free(str);
+    if (str) {
+        if (str->ptr)
+            free(str->ptr);
+        str->ptr = NULL;
+        free(str);
+    }
     return;
 }
 
@@ -79,7 +82,9 @@
     IIIMP_string *	str_next;
     for (; NULL != str; str = str_next) {
 	str_next = str->next;
-	free(str->ptr);
+	if (str->ptr)
+            free(str->ptr);
+        str->ptr = NULL;
 	free(str);
     }
     return;
