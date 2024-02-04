--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/strings/safe_sprintf.h.orig	2024-02-04 14:46:08 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/strings/safe_sprintf.h
@@ -184,7 +184,7 @@ struct Arg {
   //
   // Warning: don't just do Arg(NULL) here because in some libcs, NULL is an
   // alias for nullptr!
-  Arg(std::nullptr_t p) : type(INT) {
+  Arg(nullptr_t p) : type(INT) {
     integer.i = 0;
     // Internally, SafeSprintf expects to represent nulls as integers whose
     // width is equal to sizeof(NULL), which is not necessarily equal to
