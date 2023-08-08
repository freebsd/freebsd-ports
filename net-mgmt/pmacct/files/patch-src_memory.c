--- src/memory.c.orig	2022-12-31 19:17:17 UTC
+++ src/memory.c
@@ -27,7 +27,7 @@
    first pool descriptor id is 1 */
 
 /* functions */
-void init_memory_pool_table()
+void init_memory_pool_table(struct configuration config)
 {
   if (config.num_memory_pools) {
     mpd = (unsigned char *) map_shared(0, (config.num_memory_pools+1)*sizeof(struct memory_pool_desc),
