--- lib/iiimcf/iiimcf.c	Tue Sep 14 13:19:47 2004
+++ lib/iiimcf/iiimcf.c	Wed Feb 16 22:59:51 2005
@@ -440,7 +440,7 @@
 )
 {
     IIIMF_status st;
-    IIIMP_message *pmes;
+    IIIMP_message *pmes = NULL;
 
     if (!ph->data_s) ph->data_s = iiimp_data_s_new();
     if (!ph->data_s) return IIIMF_STATUS_MALLOC;
@@ -501,6 +501,7 @@
     iiimp_message_delete(ph->data_s, pmes);
     if (st != IIIMF_STATUS_SUCCESS) goto reconnect;
 
+    pmes = NULL;
     st = iiimcf_wait_message(ph, NULL, IM_CONNECT_REPLY, &pmes);
     if (st != IIIMF_STATUS_SUCCESS) {
         if (pmes) iiimp_message_delete(ph->data_s, pmes);
