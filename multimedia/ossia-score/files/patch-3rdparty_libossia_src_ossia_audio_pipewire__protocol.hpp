--- 3rdparty/libossia/src/ossia/audio/pipewire_protocol.hpp.orig	2026-03-01 08:55:10 UTC
+++ 3rdparty/libossia/src/ossia/audio/pipewire_protocol.hpp
@@ -75,8 +75,8 @@ class libpipewire (private)
     // in terms of regex:
     // decltype\(&::([a-z_]+)\) [a-z_]+{};
     // \1 = library.symbol<decltype(&::\1)>("\1");
-    init = library.symbol<decltype(&::pw_init)>("pw_init");
-    deinit = library.symbol<decltype(&::pw_deinit)>("pw_deinit");
+    init = library.symbol<decltype(&::pw_init)>("pipewire_init");
+    deinit = library.symbol<decltype(&::pw_deinit)>("pipewire_deinit");
 
     context_new = library.symbol<decltype(&::pw_context_new)>("pw_context_new");
     context_connect
