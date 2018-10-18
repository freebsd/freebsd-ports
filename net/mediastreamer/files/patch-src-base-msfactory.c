--- src/base/msfactory.c.orig	2017-07-20 13:56:05 UTC
+++ src/base/msfactory.c
@@ -20,14 +20,13 @@ Foundation, Inc., 51 Franklin Street, Fifth Floor, Bos
 #ifdef HAVE_CONFIG_H
 #include "mediastreamer-config.h"
 #include "gitversion.h"
-#else
+#endif
 #   ifndef MEDIASTREAMER_VERSION
 #   define MEDIASTREAMER_VERSION "unknown"
 #   endif
 #	ifndef MS2_GIT_VERSION
 #	define MS2_GIT_VERSION "unknown"
 #	endif
-#endif
 
 #include "mediastreamer2/msfilter.h"
 #include "mediastreamer2/mseventqueue.h"
@@ -184,7 +183,7 @@ void ms_factory_init(MSFactory *obj){
 	GetNativeSystemInfo( &sysinfo );
 
 	num_cpu = sysinfo.dwNumberOfProcessors;
-#elif __APPLE__ || __linux
+#elif __APPLE__ || __linux || __DragonFly__ || __FreeBSD__
 	num_cpu = sysconf( _SC_NPROCESSORS_CONF); /*check the number of processors configured, not just the one that are currently active.*/
 #elif __QNX__
 	num_cpu = _syspage_ptr->num_cpu;
