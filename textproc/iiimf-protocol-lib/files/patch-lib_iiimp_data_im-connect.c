--- lib/iiimp/data/im-connect.c	Fri Jun 20 12:06:33 2003
+++ lib/iiimp/data/im-connect.c	Wed Feb 16 22:43:17 2005
@@ -41,10 +41,15 @@
 void
 iiimp_connect_delete(IIIMP_data_s * data_s, IIIMP_message * m)
 {
-    if (NULL == m) return;
-    iiimp_string_delete(data_s, m->v.connect.user_name);
-    iiimp_string_list_delete(data_s, m->v.connect.auth);
-    free(m);
+    if (m) {
+        if (m->v.connect.user_name) 
+            iiimp_string_delete(data_s, m->v.connect.user_name);
+        m->v.connect.user_name = NULL;
+        if (m->v.connect.auth)
+            iiimp_string_list_delete(data_s, m->v.connect.auth);
+        m->v.connect.auth = NULL;
+        free(m);
+    }
     return;
 }
 
