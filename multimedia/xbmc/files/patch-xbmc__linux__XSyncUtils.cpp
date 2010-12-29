--- ./xbmc/linux/XSyncUtils.cpp.orig	2010-06-25 13:02:35.000000000 +0200
+++ ./xbmc/linux/XSyncUtils.cpp	2010-12-01 12:17:34.263963880 +0100
@@ -105,7 +105,7 @@
   return bOk;
 }
 
-#if defined(_LINUX) && !defined(__APPLE__)
+#if defined(_LINUX) && !defined(__APPLE__) && !defined(__FreeBSD__)
 static FILE* procMeminfoFP = NULL;
 #endif
 
@@ -117,7 +117,7 @@
   memset(lpBuffer, 0, sizeof(MEMORYSTATUS));
   lpBuffer->dwLength = sizeof(MEMORYSTATUS);
 
-#ifdef __APPLE__
+#if defined(__APPLE__)
   uint64_t physmem;
   size_t len = sizeof physmem;
   int mib[2] = { CTL_HW, HW_MEMSIZE };
@@ -155,6 +155,40 @@
           lpBuffer->dwAvailVirtual  = lpBuffer->dwAvailPhys; // FIXME.
       }
   }
+#elif defined(__FreeBSD__)  
+  /* sysctl hw.physmem */
+  size_t physmem = 0, mem_free = 0, pagesize = 0, swap_free = 0;                                                              
+  size_t mem_avail = 0, mem_inactive = 0, mem_cache = 0, len = 0;    
+
+  /* physmem */
+  len = sizeof(physmem);
+  if (sysctlbyname("hw.physmem", &physmem, &len, NULL, 0) == 0) {
+    lpBuffer->dwTotalPhys = physmem;
+    lpBuffer->dwTotalVirtual = physmem;
+  }
+  /* pagesize */
+  len = sizeof(pagesize);
+  if (sysctlbyname("hw.pagesize", &pagesize, &len, NULL, 0) != 0)
+  	pagesize = 4096;
+  /* mem_inactive */
+  len = sizeof(mem_inactive);
+  if (sysctlbyname("vm.stats.vm.v_inactive_count", &mem_inactive, &len, NULL, 0) == 0)
+  	mem_inactive *= pagesize;
+  /* mem_cache */
+  len = sizeof(mem_cache);
+  if (sysctlbyname("vm.stats.vm.v_cache_count", &mem_cache, &len, NULL, 0) == 0)
+  	mem_cache *= pagesize;
+  /* mem_free */
+  len = sizeof(mem_free);
+  if (sysctlbyname("vm.stats.vm.v_free_count", &mem_free, &len, NULL, 0) == 0)
+  	mem_free *= pagesize;
+
+  /* mem_avail = mem_inactive + mem_cache + mem_free */
+  lpBuffer->dwAvailPhys = mem_inactive + mem_cache + mem_free;
+  lpBuffer->dwAvailVirtual = mem_inactive + mem_cache + mem_free;
+
+  if (sysctlbyname("vm.stats.vm.v_swappgsout", &swap_free, &len, NULL, 0) == 0)
+	  lpBuffer->dwAvailPageFile = swap_free * pagesize; 
 #else
   struct sysinfo info;
   char name[32];
