Adapt to local symbols from multimedia/pipewire

PR: 284719

--- src/multimedia/pipewire/qpipewire_instance.cpp.orig	2025-08-15 19:16:13 UTC
+++ src/multimedia/pipewire/qpipewire_instance.cpp
@@ -45,7 +45,7 @@ QPipeWireInstance::QPipeWireInstance()
 
 QPipeWireInstance::QPipeWireInstance()
 {
-    pw_init(nullptr, nullptr);
+    pipewire_init(nullptr, nullptr);
 
     qCDebug(lcPipewire) << "PipeWire initialized: compiled against" << pw_get_headers_version()
                         << " running " << pw_get_library_version();
@@ -54,7 +54,7 @@ QPipeWireInstance::~QPipeWireInstance()
 QPipeWireInstance::~QPipeWireInstance()
 {
     if (pw_check_library_version(0, 3, 49))
-        pw_deinit();
+        pipewire_deinit();
 }
 
 } // namespace QtPipeWire
