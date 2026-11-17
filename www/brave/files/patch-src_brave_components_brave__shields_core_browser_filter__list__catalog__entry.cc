--- src/brave/components/brave_shields/core/browser/filter_list_catalog_entry.cc.orig	2026-10-18 18:43:23 UTC
+++ src/brave/components/brave_shields/core/browser/filter_list_catalog_entry.cc
@@ -85,7 +85,12 @@ bool GetUint8(const base::Value* value,
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+// FreeBSD has no platform of its own in the adblock-resources catalog and
+// wants none: it runs the same desktop Linux build the LINUX entries are
+// written for.  Falling through to "OTHER" instead matches no catalog entry
+// at all, which leaves SupportsCurrentPlatform() false for every list that
+// names a platform -- ad blocking off, and the filter list settings empty.
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kCurrentPlatform[] = "LINUX";
 #elif BUILDFLAG(IS_WIN)
 constexpr char kCurrentPlatform[] = "WINDOWS";
