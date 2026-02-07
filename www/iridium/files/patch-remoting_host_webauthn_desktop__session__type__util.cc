--- remoting/host/webauthn/desktop_session_type_util.cc.orig	2025-12-10 15:04:57 UTC
+++ remoting/host/webauthn/desktop_session_type_util.cc
@@ -11,7 +11,7 @@
 namespace remoting {
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 DesktopSessionType GetDesktopSessionTypeInternal(
     std::unique_ptr<base::Environment> environment) {
   // Currently on Linux, a desktop session is either remote-only or local-only.
@@ -29,7 +29,7 @@ DesktopSessionType GetDesktopSessionTypeInternal(
 }  // namespace
 
 DesktopSessionType GetDesktopSessionType() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static const DesktopSessionType desktop_session_type =
       GetDesktopSessionTypeInternal(base::Environment::Create());
   return desktop_session_type;
