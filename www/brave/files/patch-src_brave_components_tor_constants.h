--- src/brave/components/tor/constants.h.orig	2026-06-01 00:00:00 UTC
+++ src/brave/components/tor/constants.h
@@ -39,7 +39,11 @@
     "jKVAy1hc9mApZSyt4oGvUu4SJZnxlYMrY4Ze+OWbDesi2JGy+6dA1ddL9IdnwCb3"
     "9CBOMNjaHeCVz0MKxdCWGPieQM0R7S1KvDCVqAkss6NAbLB6AVM0JulqxC9b+hr/"
     "xwIDAQAB";
-#elif BUILDFLAG(IS_LINUX)
+// The Tor client component is not published for FreeBSD.  Nothing here
+// selects a fallback, so without a branch the three names below are
+// undeclared and every user of them fails to compile; the Linux component
+// is the one a FreeBSD build would ask for.
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kTorClientComponentName[] =
     "Brave Tor Client Updater (Linux)";
 #if defined(ARCH_CPU_ARM64)
