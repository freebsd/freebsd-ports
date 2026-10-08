-- ftxui-7.x compatibility

--- source/view/ftxui_ext/extended_containers.cpp.orig	2026-10-08 03:47:24 UTC
+++ source/view/ftxui_ext/extended_containers.cpp
@@ -8,6 +8,8 @@
 
 #include <memory>
 
+#define children_ children()
+
 namespace caps_log::view::ftxui_ext {
 using namespace ftxui;
 
