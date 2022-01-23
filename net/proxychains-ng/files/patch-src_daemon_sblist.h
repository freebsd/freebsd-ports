--- src/daemon/sblist.h.orig	2022-01-23 14:16:56 UTC
+++ src/daemon/sblist.h
@@ -87,6 +87,8 @@ size_t sblist_insert_sorted(sblist* l, void* o, int (*
 }
 #endif
 
+/*
 #pragma RcB2 DEP "sblist.c" "sblist_delete.c"
+*/
 
 #endif
