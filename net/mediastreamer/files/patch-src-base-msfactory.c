--- src/base/msfactory.c.orig	2023-07-27 14:00:34 UTC
+++ src/base/msfactory.c
@@ -23,11 +23,10 @@
 #ifdef HAVE_CONFIG_H
 #include "mediastreamer-config.h"
 #include "gitversion.h"
-#else
+#endif
 #   ifndef MEDIASTREAMER_VERSION
 #   define MEDIASTREAMER_VERSION "unknown"
 #   endif
-#endif
 
 #ifndef MS2_GIT_VERSION
 #define MS2_GIT_VERSION "unknown"
@@ -197,7 +196,7 @@ void ms_factory_init(MSFactory *obj){
 	GetNativeSystemInfo( &sysinfo );
 
 	num_cpu = sysinfo.dwNumberOfProcessors;
-#elif __APPLE__ || __linux__
+#elif __APPLE__ || __linux || __DragonFly__ || __FreeBSD__
 	num_cpu = sysconf( _SC_NPROCESSORS_CONF); /*check the number of processors configured, not just the one that are currently active.*/
 #elif __QNX__
 	num_cpu = _syspage_ptr->num_cpu;
@@ -1166,4 +1165,3 @@ const MSList *ms_factory_get_filter_decs(const MSFacto
 const MSList *ms_factory_get_filter_decs(const MSFactory *factory) {
 	return factory->desc_list;
 }
-
