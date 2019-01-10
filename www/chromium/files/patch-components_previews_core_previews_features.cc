--- components/previews/core/previews_features.cc.orig	2019-01-09 12:58:28.080581000 +0100
+++ components/previews/core/previews_features.cc	2019-01-09 12:58:43.775518000 +0100
@@ -14,7 +14,7 @@
 // are enabled are controlled by other features.
 const base::Feature kPreviews {
   "Previews",
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
       // Previews allowed for Android (but also allow on Linux for dev/debug).
       base::FEATURE_ENABLED_BY_DEFAULT
 #else   // !defined(OS_ANDROID) || defined(OS_LINUX)
