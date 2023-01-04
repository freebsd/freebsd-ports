- workaround for https://github.com/arminbiere/cadical/issues/48

--- src/mobical.cpp.orig	2022-08-17 10:12:36 UTC
+++ src/mobical.cpp
@@ -2611,7 +2611,12 @@ Mobical::Mobical ()
 {
   const int prot = PROT_READ | PROT_WRITE;
   const int flags = MAP_ANONYMOUS | MAP_SHARED;
-  shared = (Shared*) mmap (0, sizeof *shared, prot, flags, 0, 0);
+  void *m = mmap (0, sizeof *shared, prot, flags, -1, 0);
+  if (m == MAP_FAILED) {
+    perror("mmap failed");
+    exit(1);
+  }
+  shared = (Shared*)m;
 }
 
 Mobical::~Mobical () {
