--- pjsip/src/pjsip/sip_transport.c.orig	2017-11-08 02:58:18 UTC
+++ pjsip/src/pjsip/sip_transport.c
@@ -974,7 +974,21 @@ static pj_bool_t is_transport_valid(pjsip_transport *t
 				    const pjsip_transport_key *key,
 				    int key_len)
 {
-    return (pj_hash_get(tpmgr->table, key, key_len, NULL) == (void*)tp);
+    transport *tp_iter;
+
+    if (pj_hash_get(tpmgr->table, key, key_len, NULL) == (void*)tp) {
+        return PJ_TRUE;
+    }
+
+    tp_iter = tpmgr->tp_list.next;
+    while (tp_iter != &tpmgr->tp_list) {
+        if (tp_iter->tp == tp) {
+            return PJ_TRUE;
+        }
+        tp_iter = tp_iter->next;
+    }
+
+    return PJ_FALSE;
 }
 
 /*
