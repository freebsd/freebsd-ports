--- components/feature_engagement/public/tracker.h.orig	2026-07-01 06:24:19 UTC
+++ components/feature_engagement/public/tracker.h
@@ -249,7 +249,7 @@ class Tracker : public KeyedService, public base::Supp
     Dismissed(feature);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(https://crbug.com/511194274): For now, allow calling the base API in
   // chromeos-only code; remove the exception for ChromeOS when we've migrated
   // those calls.
