--- ui/base/x/x11_util.cc.orig	2011-09-21 11:09:03.000000000 +0300
+++ ui/base/x/x11_util.cc	2011-09-21 11:10:13.000000000 +0300
@@ -112,8 +112,6 @@
   if (shmkey == -1)
     return SHARED_MEMORY_NONE;
   void* address = shmat(shmkey, NULL, 0);
-  // Mark the shared memory region for deletion
-  shmctl(shmkey, IPC_RMID, NULL);
 
   XShmSegmentInfo shminfo;
   memset(&shminfo, 0, sizeof(shminfo));
@@ -125,6 +123,7 @@
   if (gdk_error_trap_pop())
     result = false;
   shmdt(address);
+  shmctl(shmkey, IPC_RMID, NULL);
   if (!result)
     return SHARED_MEMORY_NONE;
 
