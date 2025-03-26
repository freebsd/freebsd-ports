--- src/base/msfactory.c.orig	2025-03-26 19:56:49 UTC
+++ src/base/msfactory.c
@@ -23,11 +23,10 @@
 #ifdef HAVE_CONFIG_H
 #include "gitversion.h"
 #include "mediastreamer-config.h"
-#else
+#endif
 #ifndef MEDIASTREAMER_VERSION
 #define MEDIASTREAMER_VERSION "unknown"
 #endif
-#endif
 
 #ifndef MS2_GIT_VERSION
 #define MS2_GIT_VERSION "unknown"
@@ -198,7 +197,7 @@ void ms_factory_init(MSFactory *obj) {
 	GetNativeSystemInfo(&sysinfo);
 
 	num_cpu = sysinfo.dwNumberOfProcessors;
-#elif __APPLE__ || __linux__
+#elif __APPLE__ || __linux__ || __DragonFly__ || __FreeBSD__
 	num_cpu = sysconf(_SC_NPROCESSORS_CONF); /*check the number of processors configured, not just the one that are
 	                                            currently active.*/
 #elif __QNX__
