--- ./svc.c.orig	2010-02-02 11:49:02.000000000 +0000
+++ ./svc.c	2012-02-11 22:51:28.222833621 +0000
@@ -27,12 +27,17 @@
 
 #include    "pound.h"
 
+#ifndef LHASH_OF
+#define LHASH_OF(x) LHASH
+#define CHECKED_LHASH_OF(type, h) h
+#endif
+
 /*
  * Add a new key/content pair to a hash table
  * the table should be already locked
  */
 static void
-t_add(LHASH *const tab, const char *key, const void *content, const size_t cont_len)
+t_add(LHASH_OF(TABNODE) *const tab, const char *key, const void *content, const size_t cont_len)
 {
     TABNODE *t, *old;
 
@@ -53,7 +58,11 @@
     }
     memcpy(t->content, content, cont_len);
     t->last_acc = time(NULL);
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+    if((old = LHM_lh_insert(TABNODE, tab, t)) != NULL) {
+#else
     if((old = (TABNODE *)lh_insert(tab, t)) != NULL) {
+#endif
         free(old->key);
         free(old->content);
         free(old);
@@ -68,12 +77,16 @@
  * side-effect: update the time of last access
  */
 static void *
-t_find(LHASH *const tab, char *const key)
+t_find(LHASH_OF(TABNODE) *const tab, char *const key)
 {
     TABNODE t, *res;
 
     t.key = key;
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+    if((res = LHM_lh_retrieve(TABNODE, tab, &t)) != NULL) {
+#else
     if((res = (TABNODE *)lh_retrieve(tab, &t)) != NULL) {
+#endif
         res->last_acc = time(NULL);
         return res->content;
     }
@@ -84,12 +97,16 @@
  * Delete a key
  */
 static void
-t_remove(LHASH *const tab, char *const key)
+t_remove(LHASH_OF(TABNODE) *const tab, char *const key)
 {
     TABNODE t, *res;
 
     t.key = key;
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+    if((res = LHM_lh_delete(TABNODE, tab, &t)) != NULL) {
+#else
     if((res = (TABNODE *)lh_delete(tab, &t)) != NULL) {
+#endif
         free(res->key);
         free(res->content);
         free(res);
@@ -98,59 +115,75 @@
 }
 
 typedef struct  {
-    LHASH   *tab;
+    LHASH_OF(TABNODE) *tab;
     time_t  lim;
     void    *content;
     int     cont_len;
 }   ALL_ARG;
 
 static void
-t_old(TABNODE *t, void *arg)
+t_old_doall_arg(TABNODE *t, ALL_ARG *a)
 {
-    ALL_ARG *a;
-
-    a = (ALL_ARG *)arg;
     if(t->last_acc < a->lim)
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+        LHM_lh_delete(TABNODE, a->tab, t);
+#else
         lh_delete(a->tab, t);
+#endif
     return;
 }
-IMPLEMENT_LHASH_DOALL_ARG_FN(t_old, TABNODE *, void *)
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+IMPLEMENT_LHASH_DOALL_ARG_FN(t_old, TABNODE, ALL_ARG)
+#else
+#define t_old t_old_doall_arg
+IMPLEMENT_LHASH_DOALL_ARG_FN(t_old, TABNODE *, ALL_ARG *)
+#endif
 
 /*
  * Expire all old nodes
  */
 static void
-t_expire(LHASH *const tab, const time_t lim)
+t_expire(LHASH_OF(TABNODE) *const tab, const time_t lim)
 {
     ALL_ARG a;
     int down_load;
 
     a.tab = tab;
     a.lim = lim;
-    down_load = tab->down_load;
-    tab->down_load = 0;
+    down_load = CHECKED_LHASH_OF(TABNODE, tab)->down_load;
+    CHECKED_LHASH_OF(TABNODE, tab)->down_load = 0;
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+    LHM_lh_doall_arg(TABNODE, tab, LHASH_DOALL_ARG_FN(t_old), ALL_ARG, &a);
+#else
     lh_doall_arg(tab, LHASH_DOALL_ARG_FN(t_old), &a);
-    tab->down_load = down_load;
+#endif
+    CHECKED_LHASH_OF(TABNODE, tab)->down_load = down_load;
     return;
 }
 
 static void
-t_cont(TABNODE *t, void *arg)
+t_cont_doall_arg(TABNODE *t, ALL_ARG *a)
 {
-    ALL_ARG *a;
-
-    a = (ALL_ARG *)arg;
     if(memcmp(t->content, a->content, a->cont_len) == 0)
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+        LHM_lh_delete(TABNODE, a->tab, t);
+#else
         lh_delete(a->tab, t);
+#endif
     return;
 }
-IMPLEMENT_LHASH_DOALL_ARG_FN(t_cont, TABNODE *, void *)
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+IMPLEMENT_LHASH_DOALL_ARG_FN(t_cont, TABNODE, ALL_ARG)
+#else
+#define t_cont t_cont_doall_arg
+IMPLEMENT_LHASH_DOALL_ARG_FN(t_cont, TABNODE *, ALL_ARG *)
+#endif
 
 /*
  * Remove all nodes with the given content
  */
 static void
-t_clean(LHASH *const tab, void *const content, const size_t cont_len)
+t_clean(LHASH_OF(TABNODE) *const tab, void *const content, const size_t cont_len)
 {
     ALL_ARG a;
     int down_load;
@@ -158,10 +191,14 @@
     a.tab = tab;
     a.content = content;
     a.cont_len = cont_len;
-    down_load = tab->down_load;
-    tab->down_load = 0;
+    down_load = CHECKED_LHASH_OF(TABNODE, tab)->down_load;
+    CHECKED_LHASH_OF(TABNODE, tab)->down_load = 0;
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+    LHM_lh_doall_arg(TABNODE, tab, LHASH_DOALL_ARG_FN(t_cont), ALL_ARG, &a);
+#else
     lh_doall_arg(tab, LHASH_DOALL_ARG_FN(t_cont), &a);
-    tab->down_load = down_load;
+#endif
+    CHECKED_LHASH_OF(TABNODE, tab)->down_load = down_load;
     return;
 }
 
@@ -1410,13 +1447,11 @@
 }   DUMP_ARG;
 
 static void
-t_dump(TABNODE *t, void *arg)
+t_dump_doall_arg(TABNODE *t, DUMP_ARG *a)
 {
-    DUMP_ARG    *a;
     BACKEND     *be, *bep;
     int         n_be, sz;
 
-    a = (DUMP_ARG *)arg;
     memcpy(&bep, t->content, sizeof(bep));
     for(n_be = 0, be = a->backends; be; be = be->next, n_be++)
         if(be == bep)
@@ -1432,19 +1467,28 @@
     return;
 }
 
-IMPLEMENT_LHASH_DOALL_ARG_FN(t_dump, TABNODE *, void *)
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+IMPLEMENT_LHASH_DOALL_ARG_FN(t_dump, TABNODE, DUMP_ARG)
+#else
+#define t_dump t_dump_doall_arg
+IMPLEMENT_LHASH_DOALL_ARG_FN(t_dump, TABNODE *, DUMP_ARG *)
+#endif
 
 /*
  * write sessions to the control socket
  */
 static void
-dump_sess(const int control_sock, LHASH *const sess, BACKEND *const backends)
+dump_sess(const int control_sock, LHASH_OF(TABNODE) *const sess, BACKEND *const backends)
 {
     DUMP_ARG a;
 
     a.control_sock = control_sock;
     a.backends = backends;
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+    LHM_lh_doall_arg(TABNODE, sess, LHASH_DOALL_ARG_FN(t_dump), DUMP_ARG, &a);
+#else
     lh_doall_arg(sess, LHASH_DOALL_ARG_FN(t_dump), &a);
+#endif
     return;
 }
 
