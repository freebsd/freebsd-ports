--- src/base/msfactory.c.orig	2015-03-02 11:36:25 UTC
+++ src/base/msfactory.c
@@ -157,7 +157,7 @@ void ms_factory_init(MSFactory *obj){
 	GetNativeSystemInfo( &sysinfo );
 
 	num_cpu = sysinfo.dwNumberOfProcessors;
-#elif __APPLE__ || __linux
+#elif __APPLE__ || __linux || __DragonFly__ || __FreeBSD__
 	num_cpu = sysconf( _SC_NPROCESSORS_CONF); /*check the number of processors configured, not just the one that are currently active.*/
 #elif __QNX__
 	num_cpu = _syspage_ptr->num_cpu;
