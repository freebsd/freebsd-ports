--- chrome/browser/component_updater/wasm_tts_engine_component_installer.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/component_updater/wasm_tts_engine_component_installer.cc
@@ -21,7 +21,7 @@
 #include "components/prefs/pref_registry_simple.h"
 #include "content/public/browser/browser_thread.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/no_destructor.h"
 #include "chrome/browser/accessibility/embedded_a11y_extension_loader.h"
 #include "chrome/common/extensions/extension_constants.h"
@@ -30,7 +30,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const base::FilePath::CharType kBindingsMainWasmFileName[] =
     FILE_PATH_LITERAL("bindings_main.wasm");
 const base::FilePath::CharType kBindingsMainJsFileName[] =
@@ -58,7 +58,7 @@ constexpr std::array<uint8_t, 32> kWasmTtsEnginePublic
 
 const char kWasmTtsEngineManifestName[] = "WASM TTS Engine";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class WasmTTSEngineDirectory {
  public:
   static WasmTTSEngineDirectory* Get() {
@@ -115,7 +115,7 @@ WasmTtsEngineComponentInstallerPolicy::WasmTtsEngineCo
 // static
 void WasmTtsEngineComponentInstallerPolicy::RegisterPrefs(
     PrefRegistrySimple* registry) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterTimePref(prefs::kAccessibilityReadAnythingDateLastOpened,
                              base::Time());
   registry->RegisterBooleanPref(
@@ -148,7 +148,7 @@ void WasmTtsEngineComponentInstallerPolicy::ComponentR
   VLOG(1) << "Component ready, version " << version.GetString() << " in "
           << install_dir.value();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!features::IsWasmTtsEngineAutoInstallDisabled()) {
     // Instead of installing the component extension as soon as it is ready,
     // store the install directory, so that the install can be triggered
@@ -172,7 +172,7 @@ void WasmTtsEngineComponentInstallerPolicy::ComponentR
 // be removed the next time Chrome is restarted.
 void WasmTtsEngineComponentInstallerPolicy::MaybeReinstallTtsEngine(
     const base::FilePath& install_dir) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const base::Time current_time = base::Time::Now();
   const base::Time date_last_opened =
       pref_service_->GetTime(prefs::kAccessibilityReadAnythingDateLastOpened);
@@ -232,7 +232,7 @@ void WasmTtsEngineComponentInstallerPolicy::MaybeReins
 bool WasmTtsEngineComponentInstallerPolicy::VerifyInstallation(
     const base::DictValue& /* manifest */,
     const base::FilePath& install_dir) const {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::PathExists(install_dir.Append(kManifestV3FileName)) &&
          base::PathExists(install_dir.Append(kBindingsMainWasmFileName)) &&
          base::PathExists(install_dir.Append(kBindingsMainJsFileName)) &&
@@ -297,7 +297,7 @@ void RegisterWasmTtsEngineComponent(ComponentUpdateSer
 
 void WasmTtsEngineComponentInstallerPolicy::GetWasmTTSEngineDirectory(
     base::OnceCallback<void(const base::FilePath&)> callback) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   WasmTTSEngineDirectory* wasm_directory = WasmTTSEngineDirectory::Get();
   wasm_directory->Get(std::move(callback));
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -305,7 +305,7 @@ void WasmTtsEngineComponentInstallerPolicy::GetWasmTTS
 
 // static
 bool WasmTtsEngineComponentInstallerPolicy::IsWasmTTSEngineDirectorySet() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return WasmTTSEngineDirectory::Get()->IsSet();
 #else
   return false;
