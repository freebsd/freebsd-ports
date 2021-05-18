--- src/os/bluestore/KernelDevice.cc.orig	2021-05-13 17:23:08 UTC
+++ src/os/bluestore/KernelDevice.cc
@@ -67,7 +67,7 @@ int KernelDevice::_lock()
   for (;;) {
     struct flock fl = { F_WRLCK,
                         SEEK_SET };
-    int r = ::fcntl(fd, F_OFD_SETLK, &fl);
+    int r = ::fcntl(fd, F_SETLK, &fl);
     if (r < 0) {
       if (errno == EINVAL) {
         r = ::flock(fd, LOCK_EX | LOCK_NB);
