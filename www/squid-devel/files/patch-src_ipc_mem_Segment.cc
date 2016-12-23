--- src/ipc/mem/Segment.cc.orig	2016-12-16 10:06:20 UTC
+++ src/ipc/mem/Segment.cc
@@ -173,7 +173,7 @@ Ipc::Mem::Segment::attach()
     assert(theSize == static_cast<off_t>(static_cast<size_t>(theSize)));
 
     void *const p =
-        mmap(NULL, theSize, PROT_READ | PROT_WRITE, MAP_SHARED, theFD, 0);
+        mmap(NULL, theSize, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_NOSYNC, theFD, 0);
     if (p == MAP_FAILED) {
         int xerrno = errno;
         debugs(54, 5, "mmap " << theName << ": " << xstrerr(xerrno));
