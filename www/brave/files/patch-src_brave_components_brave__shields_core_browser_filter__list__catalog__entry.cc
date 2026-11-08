--- src/brave/components/brave_shields/core/browser/filter_list_catalog_entry.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/components/brave_shields/core/browser/filter_list_catalog_entry.cc
@@ -85,7 +85,12 @@
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
