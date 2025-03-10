Adapt to local symbols from multimedia/pipewire

PR: 284719

--- src/multimedia/pipewire/qpipewire_screencapturehelper.cpp.orig	2025-01-24 11:58:42 UTC
+++ src/multimedia/pipewire/qpipewire_screencapturehelper.cpp
@@ -54,10 +54,10 @@ class Pipewire (public)
 {
 public:
     Pipewire() {
-        pw_init(nullptr, nullptr);
+        pipewire_init(nullptr, nullptr);
     };
     ~Pipewire() {
-        pw_deinit();
+        pipewire_deinit();
     }
 
     Q_DISABLE_COPY(Pipewire)
