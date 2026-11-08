--- common/cpu.c.orig	2026-08-13 20:46:48 UTC
+++ common/cpu.c
@@ -658,10 +658,10 @@ int x264_cpu_num_processors( void )
     get_system_info( &info );
     return info.cpu_count;
 
-#elif SYS_MACOSX
+#elif SYS_MACOSX || SYS_FREEBSD
     int ncpu;
     size_t length = sizeof( ncpu );
-    if( sysctlbyname("hw.logicalcpu", &ncpu, &length, NULL, 0) )
+    if( sysctlbyname("hw.ncpu", &ncpu, &length, NULL, 0) )
     {
         ncpu = 1;
     }
