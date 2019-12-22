From e24890652e3674fe4677722aab8644e62da37348 Mon Sep 17 00:00:00 2001
From: Dima Panov <fluffy@FreeBSD.org>
Date: Fri, 20 Dec 2019 02:47:32 +1000
Subject: [PATCH] Fix calculate memory usage on FreeBSD

---
 freebsd/memory.cc | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git a/freebsd/memory.cc b/freebsd/memory.cc
index 5500032..687a0a8 100644
--- freebsd/memory.cc
+++ freebsd/memory.cc
@@ -63,8 +63,8 @@ void mem_status( MemoryStatus & status )
   //u_int unused = ( cache + inactive + free ) * page_size;
 
   // Used memory on FreeBSD is active + wired.
-  u_int used = ( active + wired ) * page_size;
+  u_int used = ( active + wired );
 
-  status.used_mem = convert_unit( static_cast< float >( used ), MEGABYTES );
+  status.used_mem = convert_unit( static_cast< float >( used * (page_size >> 10) ), MEGABYTES, KILOBYTES );
   status.total_mem = convert_unit( static_cast< float >( page_count * (page_size >> 10) ), MEGABYTES, KILOBYTES);
 }
