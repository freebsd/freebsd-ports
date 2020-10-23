--- chrome/browser/profiles/profile_attributes_entry.cc.orig	2020-09-08 19:14:00 UTC
+++ chrome/browser/profiles/profile_attributes_entry.cc
@@ -137,7 +137,7 @@ void ProfileAttributesEntry::Initialize(ProfileInfoCac
   if (is_force_signin_enabled_) {
     if (!IsAuthenticated())
       is_force_signin_profile_locked_ = true;
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   } else if (IsSigninRequired()) {
     // Profiles that require signin in the absence of an enterprise policy are
     // left-overs from legacy supervised users. Just unlock them, so users can
