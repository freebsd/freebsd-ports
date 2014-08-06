--- src/tspi/rpc/hosttable.c.orig	2012-09-20 02:35:07.000000000 +0900
+++ src/tspi/rpc/hosttable.c	2014-08-06 15:35:22.000000000 +0900
@@ -36,10 +36,10 @@
 }
 
 #ifdef SOLARIS
-#pragma init(_init)
-void _init(void)
+#pragma init(_init_hosttable)
+void _init_hosttable(void)
 #else
-void __attribute__ ((constructor)) my_init(void)
+static void __attribute__ ((constructor)) my_init(void)
 #endif
 {
 	host_table_init();
@@ -51,6 +51,8 @@
 {
 	struct host_table_entry *hte, *next = NULL;
 
+	if( ht == NULL ) return;
+
 	MUTEX_LOCK(ht->lock);
 
 	for (hte = ht->entries; hte; hte = next) {
@@ -70,10 +72,10 @@
 }
 
 #ifdef SOLARIS
-#pragma fini(_fini)
-void _fini(void)
+#pragma fini(_fini_hosttable)
+void _fini_hosttable(void)
 #else
-void __attribute__ ((destructor)) my_fini(void)
+static void __attribute__ ((destructor)) my_fini(void)
 #endif
 {
 	host_table_final();
@@ -84,6 +86,8 @@
 {
 	struct host_table_entry *entry, *tmp;
 
+	if( ht == NULL ) return TSPERR(TSS_E_OUTOFMEMORY);
+
         entry = calloc(1, sizeof(struct host_table_entry));
         if (entry == NULL) {
                 LogError("malloc of %zd bytes failed.", sizeof(struct host_table_entry));
@@ -134,6 +138,8 @@
 {
 	struct host_table_entry *hte, *prev = NULL;
 
+	if( ht == NULL ) return;
+
 	MUTEX_LOCK(ht->lock);
 
 	for (hte = ht->entries; hte; prev = hte, hte = hte->next) {
@@ -158,6 +164,8 @@
 {
 	struct host_table_entry *index = NULL;
 
+	if( ht == NULL ) return NULL;
+
 	MUTEX_LOCK(ht->lock);
 
 	for (index = ht->entries; index; index = index->next) {
