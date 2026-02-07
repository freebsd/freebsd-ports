--- scanroutines.c.orig	2017-10-13 21:53:16 UTC
+++ scanroutines.c
@@ -369,7 +369,7 @@ extern inline unsigned int scan_routine_BYTEARRAY_EQUA
 {
     const uint8_t *bytes_array = user_value->bytearray_value;
     const wildcard_t *wildcards_array = user_value->wildcard_value;
-    uint length = user_value->flags;
+    unsigned int length = user_value->flags;
     if (memlength < length ||
         *((uint64_t*)bytes_array) != (memory_ptr->uint64_value & *((uint64_t*)wildcards_array)))
     {
@@ -470,7 +470,7 @@ DEFINE_BYTEARRAY_SMALLOOP_EQUALTO_ROUTINE(56)
 extern inline unsigned int scan_routine_STRING_EQUALTO SCAN_ROUTINE_ARGUMENTS
 {
     const char *scan_string = user_value->string_value;
-    uint length = user_value->flags;
+    unsigned int length = user_value->flags;
     if(memlength < length ||
        memory_ptr->int64_value != *((int64_t*)scan_string))
     {
