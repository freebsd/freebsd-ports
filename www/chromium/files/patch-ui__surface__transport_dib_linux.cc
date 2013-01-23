--- ui/surface/transport_dib_linux.cc.orig	2013-01-08 04:46:06.000000000 +0200
+++ ui/surface/transport_dib_linux.cc	2013-01-17 23:27:10.221168481 +0200
@@ -37,6 +37,14 @@
     DCHECK(display_);
     ui::DetachSharedMemory(display_, x_shm_);
   }
+
+#if defined(OS_FREEBSD)
+  if (is_valid_id(key_)) {
+    struct shmid_ds shmst;
+    if (shmctl(key_.shmkey, IPC_STAT, &shmst) == 0 && shmst.shm_nattch == 0)
+      shmctl(key_.shmkey, IPC_RMID, 0);
+  }
+#endif
 }
 
 // static
@@ -51,10 +59,13 @@
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
 
