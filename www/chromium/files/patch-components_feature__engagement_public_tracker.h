--- components/feature_engagement/public/tracker.h.orig	2026-08-12 09:02:10 UTC
+++ components/feature_engagement/public/tracker.h
@@ -260,7 +260,7 @@ class Tracker : public KeyedService, public base::Supp
     Dismissed(feature);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(https://crbug.com/511194274): For now, allow calling the base API in
   // chromeos-only code; remove the exception for ChromeOS when we've migrated
   // those calls.
