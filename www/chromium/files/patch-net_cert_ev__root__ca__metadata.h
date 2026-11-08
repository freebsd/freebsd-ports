--- net/cert/ev_root_ca_metadata.h.orig	2026-10-18 13:29:39 UTC
+++ net/cert/ev_root_ca_metadata.h
@@ -17,7 +17,7 @@
 #include "net/cert/x509_certificate.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // When not defined, the EVRootCAMetadata singleton is a dumb placeholder
 // implementation that will fail all EV lookup operations.
 #define PLATFORM_USES_CHROMIUM_EV_METADATA
