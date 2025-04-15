--- chrome/browser/component_updater/wasm_tts_engine_component_installer.cc.orig	2025-04-15 08:30:07 UTC
+++ chrome/browser/component_updater/wasm_tts_engine_component_installer.cc
@@ -8,7 +8,7 @@
 #include "base/functional/callback.h"
 #include "base/logging.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/accessibility/embedded_a11y_extension_loader.h"
 #include "chrome/common/extensions/extension_constants.h"
 #include "components/crx_file/id_util.h"
@@ -70,7 +70,7 @@ void WasmTtsEngineComponentInstallerPolicy::ComponentR
   VLOG(1) << "Component ready, version " << version.GetString() << " in "
           << install_dir.value();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (features::IsWasmTtsComponentUpdaterEnabled() &&
       !features::IsWasmTtsEngineAutoInstallDisabled()) {
     EmbeddedA11yExtensionLoader::GetInstance()->Init();
@@ -121,7 +121,7 @@ void RegisterWasmTtsEngineComponent(ComponentUpdateSer
   installer->Register(cus, base::OnceClosure());
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string WasmTtsEngineComponentInstallerPolicy::GetId() {
   return crx_file::id_util::GenerateIdFromHash((kWasmTtsEnginePublicKeySHA256));
 }
