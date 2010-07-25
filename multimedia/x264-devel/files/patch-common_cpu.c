--- common/cpu.c.orig	2010-06-24 22:45:07.000000000 +0200
+++ common/cpu.c	2010-07-18 22:55:49.324572565 +0200
@@ -234,7 +234,7 @@
 
 #elif ARCH_PPC
 
-#if SYS_MACOSX || SYS_OPENBSD
+#if SYS_MACOSX || SYS_OPENBSD || SYS_FREEBSD
 #include <sys/sysctl.h>
 uint32_t x264_cpu_detect( void )
 {
@@ -242,12 +242,16 @@
     uint32_t cpu = 0;
 #if SYS_OPENBSD
     int      selectors[2] = { CTL_MACHDEP, CPU_ALTIVEC };
-#else
+#elif SYS_MACOSX
     int      selectors[2] = { CTL_HW, HW_VECTORUNIT };
 #endif
     int      has_altivec = 0;
     size_t   length = sizeof( has_altivec );
+#if SYS_MACOSX || SYS_OPENBSD
     int      error = sysctl( selectors, 2, &has_altivec, &length, NULL, 0 );
+#else
+    int      error = sysctlbyname("hw.altivec", &has_altivec, &length, NULL, 0 );
+#endif
 
     if( error == 0 && has_altivec != 0 )
         cpu |= X264_CPU_ALTIVEC;
