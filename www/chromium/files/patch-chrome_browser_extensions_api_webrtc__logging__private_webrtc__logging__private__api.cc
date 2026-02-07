--- chrome/browser/extensions/api/webrtc_logging_private/webrtc_logging_private_api.cc.orig	2025-08-07 06:57:29 UTC
+++ chrome/browser/extensions/api/webrtc_logging_private/webrtc_logging_private_api.cc
@@ -28,7 +28,7 @@
 #include "extensions/browser/process_manager.h"
 #include "extensions/common/error_utils.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "extensions/common/permissions/permissions_data.h"
 #endif
 
@@ -41,7 +41,7 @@ namespace {
 bool CanEnableAudioDebugRecordingsFromExtension(
     const extensions::Extension* extension) {
   bool enabled_by_permissions = false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (extension) {
     enabled_by_permissions =
         extension->permissions_data()->active_permissions().HasAPIPermission(
@@ -580,7 +580,7 @@ void WebrtcLoggingPrivateStartEventLoggingFunction::Fi
 
 ExtensionFunction::ResponseAction
 WebrtcLoggingPrivateGetLogsDirectoryFunction::Run() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Unlike other WebrtcLoggingPrivate functions that take a RequestInfo object,
   // this function shouldn't be called by a component extension on behalf of
   // some web code. It returns a DirectoryEntry for use directly in the calling
