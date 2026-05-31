--- src/redis_index.c.orig	2020-02-29 20:35:56 UTC
+++ src/redis_index.c
@@ -108,7 +108,7 @@ int InvertedIndex_RegisterType(RedisModuleCtx *ctx) {
                                .rdb_load = InvertedIndex_RdbLoad,
                                .rdb_save = InvertedIndex_RdbSave,
                                .aof_rewrite = GenericAofRewrite_DisabledHandler,
-                               .mem_usage = InvertedIndex_MemUsage,
+                               .mem_usage = (const void *)InvertedIndex_MemUsage,
                                .free = InvertedIndex_Free};
 
   InvertedIndexType = RedisModule_CreateDataType(ctx, "ft_invidx", INVERTED_INDEX_ENCVER, &tm);
