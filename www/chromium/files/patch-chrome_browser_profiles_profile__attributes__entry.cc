--- chrome/browser/profiles/profile_attributes_entry.cc.orig	2021-01-18 21:28:50 UTC
+++ chrome/browser/profiles/profile_attributes_entry.cc
@@ -158,7 +158,7 @@ void ProfileAttributesEntry::Initialize(ProfileInfoCac
   if (is_force_signin_enabled_) {
     if (!IsAuthenticated())
       is_force_signin_profile_locked_ = true;
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_WIN)
   } else if (IsSigninRequired()) {
     // Profiles that require signin in the absence of an enterprise policy are
