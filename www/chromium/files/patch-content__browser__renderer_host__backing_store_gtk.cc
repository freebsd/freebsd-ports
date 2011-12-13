--- content/browser/renderer_host/backing_store_gtk.cc.orig	2011-09-14 11:01:10.000000000 +0300
+++ content/browser/renderer_host/backing_store_gtk.cc	2011-09-22 00:21:16.000000000 +0300
@@ -57,6 +57,9 @@
   XShmDetach(display, shminfo);
   XDestroyImage(image);
   shmdt(shminfo->shmaddr);
+#if defined(OS_FREEBSD)
+  shmctl(shminfo->shmid, IPC_RMID, 0);
+#endif
 }
 
 BackingStoreX::BackingStoreGtk(RenderWidgetHost* widget,
@@ -339,7 +342,9 @@
     }
 
     void* mapped_memory = shmat(shminfo.shmid, NULL, SHM_RDONLY);
+#if !defined(OS_FREEBSD)
     shmctl(shminfo.shmid, IPC_RMID, 0);
+#endif
     if (mapped_memory == (void*)-1) {
       XDestroyImage(image);
       return false;
