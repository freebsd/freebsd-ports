Adapt to local symbols from multimedia/pipewire

PR: 284719

--- src/multimedia/pipewire/qpipewire_instance.cpp.orig	2025-02-20 14:13:07 UTC
+++ src/multimedia/pipewire/qpipewire_instance.cpp
@@ -43,7 +43,7 @@ QPipeWireInstance::QPipeWireInstance()
 
 QPipeWireInstance::QPipeWireInstance()
 {
-    pw_init(nullptr, nullptr);
+    pipewire_init(nullptr, nullptr);
 
     qCDebug(lcPipewire) << "PipeWire initialized: compiled against" << pw_get_headers_version()
                         << " running " << pw_get_library_version();
@@ -52,7 +52,7 @@ QPipeWireInstance::~QPipeWireInstance()
 QPipeWireInstance::~QPipeWireInstance()
 {
     if (pw_check_library_version(0, 3, 49))
-        pw_deinit();
+        pipewire_deinit();
 }
 
 } // namespace QtPipeWire
