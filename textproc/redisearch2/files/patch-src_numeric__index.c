--- src/numeric_index.c.orig	2024-04-16 14:20:46 UTC
+++ src/numeric_index.c
@@ -714,7 +714,7 @@ int NumericIndexType_Register(RedisModuleCtx *ctx) {
                                .rdb_save = NumericIndexType_RdbSave,
                                .aof_rewrite = GenericAofRewrite_DisabledHandler,
                                .free = NumericIndexType_Free,
-                               .mem_usage = NumericIndexType_MemUsage};
+                               .mem_usage = (const void *)NumericIndexType_MemUsage};
 
   NumericIndexType = RedisModule_CreateDataType(ctx, "numericdx", NUMERIC_INDEX_ENCVER, &tm);
   if (NumericIndexType == NULL) {
