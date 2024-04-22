--- components/policy/core/common/policy_utils.cc.orig	2024-02-03 15:42:55 UTC
+++ components/policy/core/common/policy_utils.cc
@@ -28,7 +28,7 @@ bool IsPolicyTestingEnabled(PrefService* pref_service,
     return true;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (channel == version_info::Channel::DEV) {
     return true;
   }
