--- components/password_manager/core/browser/password_manager_switches.cc.orig	2024-06-22 08:49:42 UTC
+++ components/password_manager/core/browser/password_manager_switches.cc
@@ -6,7 +6,7 @@
 
 namespace password_manager {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Specifies which encryption storage backend to use. Possible values are
 // kwallet, kwallet5, kwallet6, gnome-libsecret, basic.
 // Any other value will lead to Chrome detecting the best backend automatically.
