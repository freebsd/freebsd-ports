--- src/platform-freebsd.cc.orig	2014-10-08 11:14:11.000000000 -0400
+++ src/platform-freebsd.cc	2014-10-08 11:14:30.000000000 -0400
@@ -371,7 +371,7 @@ VirtualMemory::VirtualMemory(size_t size
   void* reservation = mmap(OS::GetRandomMmapAddr(),
                            request_size,
                            PROT_NONE,
-                           MAP_PRIVATE | MAP_ANON | MAP_NORESERVE,
+                           MAP_PRIVATE | MAP_ANON,
                            kMmapFd,
                            kMmapFdOffset);
   if (reservation == MAP_FAILED) return;
@@ -443,7 +443,7 @@ void* VirtualMemory::ReserveRegion(size_
   void* result = mmap(OS::GetRandomMmapAddr(),
                       size,
                       PROT_NONE,
-                      MAP_PRIVATE | MAP_ANON | MAP_NORESERVE,
+                      MAP_PRIVATE | MAP_ANON,
                       kMmapFd,
                       kMmapFdOffset);
 
@@ -473,7 +473,7 @@ bool VirtualMemory::UncommitRegion(void*
   return mmap(base,
               size,
               PROT_NONE,
-              MAP_PRIVATE | MAP_ANON | MAP_NORESERVE | MAP_FIXED,
+              MAP_PRIVATE | MAP_ANON | MAP_FIXED,
               kMmapFd,
               kMmapFdOffset) != MAP_FAILED;
 }
