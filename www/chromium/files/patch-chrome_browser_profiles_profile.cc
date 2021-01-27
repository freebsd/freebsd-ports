--- chrome/browser/profiles/profile.cc.orig	2021-01-19 11:26:11 UTC
+++ chrome/browser/profiles/profile.cc
@@ -387,7 +387,7 @@ bool Profile::IsIncognitoProfile() const {
 
 // static
 bool Profile::IsEphemeralGuestProfileEnabled() {
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD) || \
     defined(OS_MAC)
   return base::FeatureList::IsEnabled(
       features::kEnableEphemeralGuestProfilesOnDesktop);
