--- src/remoting/base/security_key_socket_name.cc.orig	2026-10-18 18:43:23 UTC
+++ src/remoting/base/security_key_socket_name.cc
@@ -25,7 +25,7 @@ base::FilePath GetDefaultSecurityKeySock
   if (!GetSocketNameOverride().empty()) {
     return GetSocketNameOverride();
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // LINT.IfChange(ssh_auth_sock_name)
   const char* xdg_runtime_dir = getenv("XDG_RUNTIME_DIR");
   if (xdg_runtime_dir) {
