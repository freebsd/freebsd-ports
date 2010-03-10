--- common/cpu.c.orig	2010-02-28 10:49:54.000000000 -0800
+++ common/cpu.c	2010-02-28 10:56:06.000000000 -0800
@@ -211,6 +211,27 @@
     return cpu;
 }
 
+#elif defined(SYS_FREEBSD)
+#include <sys/sysctl.h>
+uint32_t x264_cpu_detect( void )
+{
+    uint32_t cpu;
+    int has_altivec, error;
+    size_t length;
+
+    cpu = 0;
+    has_altivec = 0;
+    length = sizeof( has_altivec );
+    error = sysctlbyname("hw.altivec", &has_altivec, &length, NULL, 0 );
+
+    if( error == 0 && has_altivec != 0 )
+    {
+        cpu |= X264_CPU_ALTIVEC;
+    }
+
+    return cpu;
+}
+
 #elif defined( SYS_LINUX )
 #include <signal.h>
 #include <setjmp.h>
