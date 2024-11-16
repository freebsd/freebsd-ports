--- components/media_router/common/providers/cast/channel/enum_table.h.orig	2024-11-14 07:57:23 UTC
+++ components/media_router/common/providers/cast/channel/enum_table.h
@@ -368,7 +368,12 @@ class EnumTable {
 
  private:
 #ifdef ARCH_CPU_64_BITS
+#ifdef __cpp_lib_hardware_interference_size
   alignas(std::hardware_destructive_interference_size)
+#else
+  static constexpr std::size_t hardware_destructive_interference_size = 64;
+  alignas(hardware_destructive_interference_size)
+#endif
 #endif
       std::initializer_list<Entry> data_;
   bool is_sorted_;
