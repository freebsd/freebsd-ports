--- ui/gfx/surface/transport_dib_linux.cc.orig	2011-09-14 11:02:00.000000000 +0300
+++ ui/gfx/surface/transport_dib_linux.cc	2011-09-21 13:59:55.000000000 +0300
@@ -31,6 +31,11 @@
     address_ = kInvalidAddress;
   }
 
+#if defined(OS_FREEBSD)
+  if(is_valid_id(key_))
+    shmctl(key_.shmkey, IPC_RMID, 0);
+#endif
+
   if (x_shm_) {
     DCHECK(display_);
     ui::DetachSharedMemory(display_, x_shm_);
@@ -50,10 +55,13 @@
   }
 
   void* address = shmat(shmkey, NULL /* desired address */, 0 /* flags */);
+  // On BSD we can't access the shared memory after is marked for deletion.
+#if !defined(OS_FREEBSD)
   // Here we mark the shared memory for deletion. Since we attached it in the
   // line above, it doesn't actually get deleted but, if we crash, this means
   // that the kernel will automatically clean it up for us.
   shmctl(shmkey, IPC_RMID, 0);
+#endif
   if (address == kInvalidAddress)
     return NULL;
 
