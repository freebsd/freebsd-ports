--- chrome/browser/devtools/devtools_policy_dialog.cc.orig	2026-11-17 11:49:09 UTC
+++ chrome/browser/devtools/devtools_policy_dialog.cc
@@ -38,7 +38,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr int kIconPadding = 4;
 #else
 constexpr int kIconPadding = 2;
