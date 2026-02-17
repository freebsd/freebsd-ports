--- chrome/browser/devtools/devtools_policy_dialog.cc.orig	2026-02-16 10:45:29 UTC
+++ chrome/browser/devtools/devtools_policy_dialog.cc
@@ -32,7 +32,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr int kIconPadding = 4;
 #else
 constexpr int kIconPadding = 2;
