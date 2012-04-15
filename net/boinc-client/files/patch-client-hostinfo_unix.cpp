--- client/hostinfo_unix.cpp.orig	2012-04-09 14:00:43.000000000 +0300
+++ client/hostinfo_unix.cpp		2012-04-09 15:42:49.000000000 +0300
@@ -584,9 +584,10 @@
 
 void use_cpuid(HOST_INFO& host) {
     u_int p[4];
-    int hasMMX, hasSSE, hasSSE2, hasSSE3, has3DNow, has3DNowExt = 0;
+    int hasMMX, hasSSE, hasSSE2, hasSSE3, has3DNow, has3DNowExt;
     char capabilities[256];
 
+    hasMMX = hasSSE = hasSSE2 = hasSSE3 = has3DNow = has3DNowExt = 0;
     do_cpuid(0x0, p);
 
     if (p[0] >= 0x1) {
@@ -1285,7 +1286,7 @@
     m_nbytes = (double)sysconf(_SC_PAGESIZE) * (double)sysconf(_SC_PHYS_PAGES);
     if (m_nbytes < 0) {
         msg_printf(NULL, MSG_INTERNAL_ERROR,
-            "RAM size not measured correctly: page size %d, #pages %d",
+            "RAM size not measured correctly: page size %ld, #pages %ld",
             sysconf(_SC_PAGESIZE), sysconf(_SC_PHYS_PAGES)
         );
     }
@@ -1311,7 +1312,7 @@
     int mem_size;
     getsysinfo( GSI_PHYSMEM, (caddr_t) &mem_size, sizeof( mem_size));
     m_nbytes = 1024.* (double)mem_size;
-#elif defined(HW_PHYSMEM) 
+#elif defined(__OpenBSD__) 
     // for OpenBSD
     mib[0] = CTL_HW; 
     int mem_size; 
