--- components/policy/core/common/policy_utils.cc.orig	2024-10-01 07:26:23 UTC
+++ components/policy/core/common/policy_utils.cc
@@ -22,7 +22,7 @@ bool IsPolicyTestingEnabled(PrefService* pref_service,
     return true;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (channel == version_info::Channel::DEV) {
     return true;
   }
