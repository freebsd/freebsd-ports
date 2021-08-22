--- chrome/browser/profiles/profile_attributes_entry.cc.orig	2021-07-19 18:45:09 UTC
+++ chrome/browser/profiles/profile_attributes_entry.cc
@@ -163,7 +163,7 @@ void ProfileAttributesEntry::Initialize(ProfileInfoCac
          base::FeatureList::IsEnabled(features::kForceSignInReauth))) {
       is_force_signin_profile_locked_ = true;
     }
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_WIN)
   } else if (IsSigninRequired()) {
     // Profiles that require signin in the absence of an enterprise policy are
