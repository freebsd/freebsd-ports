--- ../../work/HandBrake/libhb/ports.c	2008-02-19 19:28:17.000000000 +0100
+++ libhb/ports.c	2008-06-17 13:20:42.000000000 +0200
@@ -30,6 +30,11 @@
 #include <netinet/in.h>
 //#endif
 
+#if defined( SYS_FREEBSD )
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 #include "hb.h"
 
 /************************************************************************
@@ -107,7 +112,7 @@
         cpu_count = info.cpu_count;
     }
 
-#elif defined( SYS_DARWIN ) || defined( SYS_FREEBSD )
+#elif defined( SYS_DARWIN )
     FILE * info;
     char   buffer[16];
 
@@ -124,6 +129,19 @@
         fclose( info );
     }
 
+#elif defined( SYS_FREEBSD )
+    {
+        int mib[2];
+        size_t len;
+
+        mib[0] = CTL_HW;
+        mib[1] = HW_NCPU;
+        len = sizeof(cpu_count);
+
+        if(sysctl(mib, 2, &cpu_count, &len, NULL, 0) != 0)
+          cpu_count = 1;
+    }
+
 #elif defined( SYS_LINUX )
     {
         FILE * info;
