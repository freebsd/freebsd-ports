--- chrome/browser/component_updater/wasm_tts_engine_component_installer.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/component_updater/wasm_tts_engine_component_installer.cc
@@ -11,7 +11,7 @@
 #include "components/prefs/pref_registry_simple.h"
 #include "content/public/browser/browser_thread.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/accessibility/embedded_a11y_extension_loader.h"
 #include "chrome/common/extensions/extension_constants.h"
 #include "ui/accessibility/accessibility_features.h"
@@ -31,7 +31,7 @@ const base::FilePath::CharType kWorkletProcessorJsFile
     FILE_PATH_LITERAL("streaming_worklet_processor.js");
 const base::FilePath::CharType kVoicesJsonFileName[] =
     FILE_PATH_LITERAL("voices.json");
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const base::FilePath::CharType kManifestV3FileName[] =
     FILE_PATH_LITERAL("wasm_tts_manifest_v3.json");
 const base::FilePath::CharType kOffscreenHtmlFileName[] =
@@ -51,7 +51,7 @@ constexpr std::array<uint8_t, 32> kWasmTtsEnginePublic
 
 const char kWasmTtsEngineManifestName[] = "WASM TTS Engine";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class WasmTTSEngineDirectory {
  public:
   static WasmTTSEngineDirectory* Get() {
@@ -103,7 +103,7 @@ WasmTtsEngineComponentInstallerPolicy::WasmTtsEngineCo
 // static
 void WasmTtsEngineComponentInstallerPolicy::RegisterPrefs(
     PrefRegistrySimple* registry) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterTimePref(prefs::kAccessibilityReadAnythingDateLastOpened,
                              base::Time());
   registry->RegisterBooleanPref(
@@ -136,7 +136,7 @@ void WasmTtsEngineComponentInstallerPolicy::ComponentR
   VLOG(1) << "Component ready, version " << version.GetString() << " in "
           << install_dir.value();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!features::IsWasmTtsEngineAutoInstallDisabled()) {
     // Instead of installing the component extension as soon as it is ready,
     // store the install directory, so that the install can be triggered
@@ -160,7 +160,7 @@ void WasmTtsEngineComponentInstallerPolicy::ComponentR
 // be removed the next time Chrome is restarted.
 void WasmTtsEngineComponentInstallerPolicy::MaybeReinstallTtsEngine(
     const base::FilePath& install_dir) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const base::Time current_time = base::Time::Now();
   const base::Time date_last_opened =
       pref_service_->GetTime(prefs::kAccessibilityReadAnythingDateLastOpened);
@@ -222,7 +222,7 @@ void WasmTtsEngineComponentInstallerPolicy::MaybeReins
 bool WasmTtsEngineComponentInstallerPolicy::VerifyInstallation(
     const base::Value::Dict& /* manifest */,
     const base::FilePath& install_dir) const {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (features::IsWasmTtsComponentUpdaterV3Enabled()) {
     return base::PathExists(install_dir.Append(kManifestV3FileName)) &&
            base::PathExists(install_dir.Append(kBindingsMainWasmFileName)) &&
@@ -272,7 +272,7 @@ void RegisterWasmTtsEngineComponent(ComponentUpdateSer
 
 void WasmTtsEngineComponentInstallerPolicy::GetWasmTTSEngineDirectory(
     base::OnceCallback<void(const base::FilePath&)> callback) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   WasmTTSEngineDirectory* wasm_directory = WasmTTSEngineDirectory::Get();
   wasm_directory->Get(std::move(callback));
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
