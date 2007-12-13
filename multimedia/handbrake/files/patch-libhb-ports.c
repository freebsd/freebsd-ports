--- HandBrake_old/libhb/ports.c	2007-10-08 22:57:08.000000000 +0200
+++ libhb/ports.c	2007-12-04 07:48:47.000000000 +0100
@@ -28,6 +28,11 @@
 #include <netinet/in.h>
 //#endif
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 #include "hb.h"
 
 /************************************************************************
@@ -105,21 +110,17 @@
         cpu_count = info.cpu_count;
     }
 
-#elif defined( SYS_DARWIN ) || defined( SYS_FREEBSD )
-    FILE * info;
-    char   buffer[16];
-
-    if( ( info = popen( "/usr/sbin/sysctl hw.ncpu", "r" ) ) )
+#elif defined(__FreeBSD__)
     {
-        memset( buffer, 0, 16 );
-        if( fgets( buffer, 15, info ) )
-        {
-            if( sscanf( buffer, "hw.ncpu: %d", &cpu_count ) != 1 )
-            {
-                cpu_count = 1;
-            }
-        }
-        fclose( info );
+        int mib[2];
+        size_t len;
+
+        mib[0] = CTL_HW;
+        mib[1] = HW_NCPU;
+        len = sizeof(cpu_count);
+
+        if(sysctl(mib, 2, &cpu_count, &len, NULL, 0) != 0)
+          cpu_count = 1;
     }
 
 #elif defined( SYS_LINUX )
