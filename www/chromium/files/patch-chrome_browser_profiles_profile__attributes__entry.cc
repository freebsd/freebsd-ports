--- chrome/browser/profiles/profile_attributes_entry.cc.orig	2019-02-06 22:32:27.013965000 +0100
+++ chrome/browser/profiles/profile_attributes_entry.cc	2019-02-06 22:32:49.969336000 +0100
@@ -57,7 +57,7 @@
   if (is_force_signin_enabled_) {
     if (!IsAuthenticated())
       is_force_signin_profile_locked_ = true;
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   } else if (IsSigninRequired()) {
     // Profiles that require signin in the absence of an enterprise policy are
     // left-overs from legacy supervised users. Just unlock them, so users can
