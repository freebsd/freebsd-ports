--- src/tspi/rpc/hosttable.c.orig	2016-11-19 03:09:49 UTC
+++ src/tspi/rpc/hosttable.c
@@ -51,6 +51,8 @@ host_table_final()
 {
 	struct host_table_entry *hte, *next = NULL;
 
+	if( ht == NULL ) return;
+
 	MUTEX_LOCK(ht->lock);
 
 	for (hte = ht->entries; hte; hte = next) {
@@ -85,6 +87,8 @@ __tspi_add_table_entry(TSS_HCONTEXT tspC
     struct host_table_entry *entry, *tmp;
     int hostlen;
 
+    if( ht == NULL ) return TSPERR(TSS_E_OUTOFMEMORY);
+
     entry = calloc(1, sizeof(struct host_table_entry));
     if (entry == NULL) {
             LogError("malloc of %zd bytes failed.", sizeof(struct host_table_entry));
@@ -144,6 +148,8 @@ remove_table_entry(TSS_HCONTEXT tspConte
 {
 	struct host_table_entry *hte, *prev = NULL;
 
+	if( ht == NULL ) return;
+
 	MUTEX_LOCK(ht->lock);
 
 	for (hte = ht->entries; hte; prev = hte, hte = hte->next) {
@@ -168,6 +174,8 @@ get_table_entry(TSS_HCONTEXT tspContext)
 {
 	struct host_table_entry *index = NULL;
 
+	if( ht == NULL ) return NULL;
+
 	MUTEX_LOCK(ht->lock);
 
 	for (index = ht->entries; index; index = index->next) {
