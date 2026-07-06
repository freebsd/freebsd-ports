--- src/redis_index.c.orig	2023-01-30 16:15:52 UTC
+++ src/redis_index.c
@@ -114,7 +114,7 @@ int InvertedIndex_RegisterType(RedisModuleCtx *ctx) {
                                .rdb_load = InvertedIndex_RdbLoad,
                                .rdb_save = InvertedIndex_RdbSave,
                                .aof_rewrite = GenericAofRewrite_DisabledHandler,
-                               .mem_usage = InvertedIndex_MemUsage,
+                               .mem_usage = (const void *)InvertedIndex_MemUsage,
                                .free = InvertedIndex_Free};
 
   InvertedIndexType = RedisModule_CreateDataType(ctx, "ft_invidx", INVERTED_INDEX_ENCVER, &tm);
