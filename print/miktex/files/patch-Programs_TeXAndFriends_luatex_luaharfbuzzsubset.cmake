--- Programs/TeXAndFriends/luatex/luaharfbuzzsubset.cmake.orig	2026-10-11 18:56:17 UTC
+++ Programs/TeXAndFriends/luatex/luaharfbuzzsubset.cmake
@@ -24,6 +24,7 @@ if(USE_SYSTEM_HARFBUZZ_ICU)
 if(USE_SYSTEM_HARFBUZZ_ICU)
     target_link_libraries(luahbtex-luaharfbuzzsubset-objects PUBLIC MiKTeX::Imported::HARFBUZZ_ICU)
     target_link_libraries(luahbtex-luaharfbuzzsubset-objects PUBLIC MiKTeX::Imported::HARFBUZZ)
+    target_link_libraries(luahbtex-luaharfbuzzsubset-objects PUBLIC MiKTeX::Imported::HARFBUZZ_SUBSET)
 else()
     target_link_libraries(luahbtex-luaharfbuzzsubset-objects PUBLIC ${harfbuzz_dll_name})
 endif()
