--- src/platform-freebsd.cc.orig	2014-06-03 04:52:11.000000000 -0400
+++ src/platform-freebsd.cc	2014-10-08 11:16:08.000000000 -0400
@@ -189,7 +189,7 @@ VirtualMemory::VirtualMemory(size_t size
   void* reservation = mmap(OS::GetRandomMmapAddr(),
                            request_size,
                            PROT_NONE,
-                           MAP_PRIVATE | MAP_ANON | MAP_NORESERVE,
+                           MAP_PRIVATE | MAP_ANON,
                            kMmapFd,
                            kMmapFdOffset);
   if (reservation == MAP_FAILED) return;
@@ -261,7 +261,7 @@ void* VirtualMemory::ReserveRegion(size_
   void* result = mmap(OS::GetRandomMmapAddr(),
                       size,
                       PROT_NONE,
-                      MAP_PRIVATE | MAP_ANON | MAP_NORESERVE,
+                      MAP_PRIVATE | MAP_ANON,
                       kMmapFd,
                       kMmapFdOffset);
 
@@ -289,7 +289,7 @@ bool VirtualMemory::UncommitRegion(void*
   return mmap(base,
               size,
               PROT_NONE,
-              MAP_PRIVATE | MAP_ANON | MAP_NORESERVE | MAP_FIXED,
+              MAP_PRIVATE | MAP_ANON | MAP_FIXED,
               kMmapFd,
               kMmapFdOffset) != MAP_FAILED;
 }
