--- chrome/browser/component_updater/wasm_tts_engine_component_installer.h.orig	2025-05-07 06:48:23 UTC
+++ chrome/browser/component_updater/wasm_tts_engine_component_installer.h
@@ -27,7 +27,7 @@ class WasmTtsEngineComponentInstallerPolicy : public C
   WasmTtsEngineComponentInstallerPolicy& operator=(
       const WasmTtsEngineComponentInstallerPolicy&) = delete;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static std::string GetId();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
