--- src/plugins/select/cons_tres/job_test.c.orig	2020-03-26 21:44:05 UTC
+++ src/plugins/select/cons_tres/job_test.c
@@ -41,23 +41,6 @@
 
 #define _DEBUG 0	/* Enables module specific debugging */
 
-/*
- * These symbols are defined here so when we link with something other
- * than the slurmctld we will have these symbols defined. They will get
- * overwritten when linking with the slurmctld.
- */
-#if defined (__APPLE__)
-extern slurmctld_config_t slurmctld_config __attribute__((weak_import));
-extern bitstr_t *idle_node_bitmap __attribute__((weak_import));
-extern node_record_t *node_record_table_ptr __attribute__((weak_import));
-extern List job_list __attribute__((weak_import));
-#else
-slurmctld_config_t slurmctld_config;
-bitstr_t *idle_node_bitmap;
-node_record_t *node_record_table_ptr;
-List job_list;
-#endif
-
 typedef struct node_weight_struct {
 	bitstr_t *node_bitmap;	/* bitmap of nodes with this weight */
 	uint32_t weight;	/* priority of node for scheduling work on */
