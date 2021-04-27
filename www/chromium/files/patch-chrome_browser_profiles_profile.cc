--- chrome/browser/profiles/profile.cc.orig	2021-04-14 18:40:54 UTC
+++ chrome/browser/profiles/profile.cc
@@ -356,7 +356,7 @@ bool Profile::IsIncognitoProfile() const {
 bool Profile::IsEphemeralGuestProfileEnabled() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC)
   return base::FeatureList::IsEnabled(
       features::kEnableEphemeralGuestProfilesOnDesktop);
