--- src/3rdparty/chromium/components/supervised_user/core/browser/list_family_members_service.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/supervised_user/core/browser/list_family_members_service.h
@@ -33,7 +33,7 @@ constexpr bool FetchListFamilyMembersWithCapability() 
 // If true, this fetcher is active for all users with CanFetchFamilyMemberInfo
 // capability. Otherwise, it is only used by supervised users.
 constexpr bool FetchListFamilyMembersWithCapability() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
