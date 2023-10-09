-- src/ipc/mem/Segment.cc.orig	2023-03-08 18:21:44.707065000 -0700
--- src/ipc/mem/Segment.cc.orig	2023-02-28 09:10:25 UTC
+++ src/ipc/mem/Segment.cc
@@ -174,7 +174,7 @@ Ipc::Mem::Segment::attach()
     assert(theSize == static_cast<off_t>(static_cast<size_t>(theSize)));
 
     void *const p =
-        mmap(nullptr, theSize, PROT_READ | PROT_WRITE, MAP_SHARED, theFD, 0);
+        mmap(nullptr, theSize, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_NOSYNC, theFD, 0);
     if (p == MAP_FAILED) {
         int xerrno = errno;
         debugs(54, 5, "mmap " << theName << ": " << xstrerr(xerrno));
