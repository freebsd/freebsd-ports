--- src/3rdparty/chromium/third_party/protobuf/src/google/protobuf/arenastring.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/third_party/protobuf/src/google/protobuf/arenastring.cc
@@ -64,7 +64,9 @@ constexpr size_t kStringAlign = alignof(std::string);
 #endif
 constexpr size_t kStringAlign = alignof(std::string);
 
+#if !(defined(__FreeBSD__) && defined(__i386__))
 static_assert((kStringAlign > kNewAlign ? kStringAlign : kNewAlign) >= 8, "");
+#endif
 static_assert(alignof(ExplicitlyConstructedArenaString) >= 8, "");
 
 }  // namespace
