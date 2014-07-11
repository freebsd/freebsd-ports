--- src/base/mscommon.c.orig	2014-02-19 12:07:16.569961000 +0100
+++ src/base/mscommon.c	2014-07-11 10:07:30.000000000 +0200
@@ -512,7 +512,7 @@
 	GetSystemInfo( &sysinfo );
 
 	num_cpu = sysinfo.dwNumberOfProcessors;
-#elif __APPLE__ || __linux
+#elif __APPLE__ || __linux || __FreeBSD__
 	num_cpu = sysconf( _SC_NPROCESSORS_ONLN );
 #elif __QNX__
 	num_cpu = _syspage_ptr->num_cpu;
