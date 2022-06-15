--- src/base/msfactory.c.orig	2022-06-10 12:50:07 UTC
+++ src/base/msfactory.c
@@ -20,11 +20,10 @@
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
@@ -194,7 +193,7 @@ void ms_factory_init(MSFactory *obj){
 	GetNativeSystemInfo( &sysinfo );
 
 	num_cpu = sysinfo.dwNumberOfProcessors;
-#elif __APPLE__ || __linux__
+#elif __APPLE__ || __linux || __DragonFly__ || __FreeBSD__
 	num_cpu = sysconf( _SC_NPROCESSORS_CONF); /*check the number of processors configured, not just the one that are currently active.*/
 #elif __QNX__
 	num_cpu = _syspage_ptr->num_cpu;
@@ -1156,4 +1155,3 @@ const MSList *ms_factory_get_filter_decs(const MSFacto
 const MSList *ms_factory_get_filter_decs(const MSFactory *factory) {
 	return factory->desc_list;
 }
-
