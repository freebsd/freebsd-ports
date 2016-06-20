--- src/tspi/rpc/hosttable.c.orig	2016-06-20 15:21:26 UTC
+++ src/tspi/rpc/hosttable.c
@@ -51,6 +51,8 @@ host_table_final()
 {
 	struct host_table_entry *hte, *next = NULL;
 
+	if( ht == NULL ) return;
+
 	MUTEX_LOCK(ht->lock);
 
 	for (hte = ht->entries; hte; hte = next) {
@@ -84,6 +86,8 @@ __tspi_add_table_entry(TSS_HCONTEXT tspC
 {
 	struct host_table_entry *entry, *tmp;
 
+	if( ht == NULL ) return TSPERR(TSS_E_OUTOFMEMORY);
+
         entry = calloc(1, sizeof(struct host_table_entry));
         if (entry == NULL) {
                 LogError("malloc of %zd bytes failed.", sizeof(struct host_table_entry));
@@ -134,6 +138,8 @@ remove_table_entry(TSS_HCONTEXT tspConte
 {
 	struct host_table_entry *hte, *prev = NULL;
 
+	if( ht == NULL ) return;
+
 	MUTEX_LOCK(ht->lock);
 
 	for (hte = ht->entries; hte; prev = hte, hte = hte->next) {
@@ -158,6 +164,8 @@ get_table_entry(TSS_HCONTEXT tspContext)
 {
 	struct host_table_entry *index = NULL;
 
+	if( ht == NULL ) return NULL;
+
 	MUTEX_LOCK(ht->lock);
 
 	for (index = ht->entries; index; index = index->next) {
