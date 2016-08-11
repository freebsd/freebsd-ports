--- src/ipc/mem/Segment.cc.orig	2015-11-01 10:44:25 UTC
+++ src/ipc/mem/Segment.cc
@@ -150,7 +150,7 @@ Ipc::Mem::Segment::attach()
     assert(theSize == static_cast<off_t>(static_cast<size_t>(theSize)));
 
     void *const p =
-        mmap(NULL, theSize, PROT_READ | PROT_WRITE, MAP_SHARED, theFD, 0);
+        mmap(NULL, theSize, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_NOSYNC, theFD, 0);
     if (p == MAP_FAILED) {
         debugs(54, 5, HERE << "mmap " << theName << ": " << xstrerror());
         fatalf("Ipc::Mem::Segment::attach failed to mmap(%s): %s\n",
