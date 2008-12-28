--- client/hostinfo_unix.cpp.orig	2008-12-28 11:11:26.000000000 +0100
+++ client/hostinfo_unix.cpp	2008-12-29 00:51:32.000000000 +0100
@@ -809,14 +809,6 @@
     int mem_size;
     getsysinfo( GSI_PHYSMEM, (caddr_t) &mem_size, sizeof( mem_size));
     m_nbytes = 1024.* (double)mem_size;
-#elif defined(HW_PHYSMEM) 
-    // for OpenBSD
-    mib[0] = CTL_HW; 
-    int mem_size; 
-    mib[1] = HW_PHYSMEM; 
-    len = sizeof(mem_size); 
-    sysctl(mib, 2, &mem_size, &len, NULL, 0); 
-    m_nbytes = mem_size; 
 #elif defined(__FreeBSD__)
     unsigned int mem_size;
     mib[0] = CTL_HW;
