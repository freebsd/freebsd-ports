--- arclite/src/Patch7zCP.cpp.orig	2025-10-26 08:39:52 UTC
+++ arclite/src/Patch7zCP.cpp
@@ -641,7 +641,7 @@ FAR_ALIGNED(16) void CItem::GetUnicodeString(UString &
 //{
 //	return NULL;
 //}
-#else
+#elif 0 // unused, incomplete 64-bit-only linux-specific code
 void **find_plt_entry_for_symbol(struct link_map *map, void *target_addr)
 {
 //	ElfW(Dyn) *dynamic = map->l_ld;
@@ -776,6 +776,7 @@ bool get_faddrs(void *handle)
 	return true;
 }
 
+#if 0 // unused, incomplete 64-bit-only linux-specific code
 static bool patch_plt(void *handle)
 {
 #if defined(__APPLE__) || defined(__UCLIBC__)
@@ -812,6 +813,7 @@ static bool patch_plt(void *handle)
 	return true;
 #endif
 }
+#endif
 
 static bool patch_addr(void *handle)
 {
