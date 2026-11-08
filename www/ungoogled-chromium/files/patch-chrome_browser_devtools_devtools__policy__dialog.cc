--- chrome/browser/devtools/devtools_policy_dialog.cc.orig	2026-08-13 07:41:05 UTC
+++ chrome/browser/devtools/devtools_policy_dialog.cc
@@ -33,7 +33,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr int kIconPadding = 4;
 #else
 constexpr int kIconPadding = 2;
