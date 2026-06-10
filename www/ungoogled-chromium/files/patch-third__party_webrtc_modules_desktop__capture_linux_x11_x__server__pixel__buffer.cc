--- third_party/webrtc/modules/desktop_capture/linux/x11/x_server_pixel_buffer.cc.orig	2026-06-05 13:45:06 UTC
+++ third_party/webrtc/modules/desktop_capture/linux/x11/x_server_pixel_buffer.cc
@@ -17,6 +17,13 @@
 #include <sys/ipc.h>
 #include <sys/shm.h>
 
+#if defined(__OpenBSD__)
+#include <X11/Xlib-xcb.h>
+#include <xcb/shm.h>
+#include <sys/mman.h>
+#include <unistd.h>
+#endif
+
 #include <cstdint>
 #include <vector>
 
@@ -170,13 +177,25 @@ void XServerPixelBuffer::ReleaseSharedMemorySegment() 
   if (!shm_segment_info_)
     return;
   if (xshm_attached_) {
+#if defined(__OpenBSD__)
+    xcb_shm_detach(xcb_connection_, shm_segment_info_->shmseg);
+#else
     XShmDetach(display_, shm_segment_info_);
+#endif
     xshm_attached_ = false;
   }
   if (shm_segment_info_->shmaddr != nullptr)
+#if defined(__OpenBSD__)
+    munmap(shm_segment_info_->shmaddr, shm_size_);
+#else
     shmdt(shm_segment_info_->shmaddr);
+#endif
   if (shm_segment_info_->shmid != -1)
+#if defined(__OpenBSD__)
+    xcb_shm_detach(xcb_connection_, shm_segment_info_->shmseg);
+#else
     shmctl(shm_segment_info_->shmid, IPC_RMID, nullptr);
+#endif
   delete shm_segment_info_;
   shm_segment_info_ = nullptr;
 }
@@ -224,21 +243,55 @@ void XServerPixelBuffer::InitShm(const XWindowAttribut
   shm_segment_info_->shmid = -1;
   shm_segment_info_->shmaddr = nullptr;
   shm_segment_info_->readOnly = False;
+#if defined(__OpenBSD__)
+  shm_segment_info_->shmseg = XCB_NONE;
+#endif
   x_shm_image_ = XShmCreateImage(display_, default_visual, default_depth,
                                  ZPixmap, nullptr, shm_segment_info_,
                                  window_rect_.width(), window_rect_.height());
   if (x_shm_image_) {
+#if defined(__OpenBSD__)
+    char name[19] = "/webrtc-XXXXXXXXXX";
+    shm_size_ = x_shm_image_->bytes_per_line * x_shm_image_->height;
+    shm_segment_info_->shmid = shm_mkstemp(name);
+    shm_unlink(name);
+#else
     shm_segment_info_->shmid =
         shmget(IPC_PRIVATE, x_shm_image_->bytes_per_line * x_shm_image_->height,
                IPC_CREAT | 0600);
+#endif
     if (shm_segment_info_->shmid != -1) {
+#if defined(__OpenBSD__)
+      if (ftruncate(shm_segment_info_->shmid, shm_size_) < 0) {
+        close(shm_segment_info_->shmid);
+        return;
+      }
+      void* shmat_result = mmap(nullptr, shm_size_, PROT_READ | PROT_WRITE,
+                                MAP_SHARED | __MAP_NOFAULT,
+                                shm_segment_info_->shmid, 0);
+      if (shmat_result == MAP_FAILED) {
+        close(shm_segment_info_->shmid);
+        return;
+      }
+#else
       void* shmat_result = shmat(shm_segment_info_->shmid, nullptr, 0);
+#endif
       if (shmat_result != reinterpret_cast<void*>(-1)) {
         shm_segment_info_->shmaddr = reinterpret_cast<char*>(shmat_result);
         x_shm_image_->data = shm_segment_info_->shmaddr;
 
         XErrorTrap error_trap(display_);
+#if defined(__OpenBSD__)
+        xcb_connection_ = XGetXCBConnection(display_);
+        shm_segment_info_->shmseg = xcb_generate_id(xcb_connection_);
+        xcb_void_cookie_t cookie =
+	    xcb_shm_attach_fd_checked(xcb_connection_, shm_segment_info_->shmseg,
+                                      shm_segment_info_->shmid, 0);
+        if (xcb_request_check(xcb_connection_, cookie) == NULL)
+          xshm_attached_ = true;
+#else
         xshm_attached_ = XShmAttach(display_, shm_segment_info_);
+#endif
         XSync(display_, False);
         if (error_trap.GetLastErrorAndDisable() != 0)
           xshm_attached_ = false;
@@ -263,7 +316,9 @@ void XServerPixelBuffer::InitShm(const XWindowAttribut
   if (have_pixmaps)
     have_pixmaps = InitPixmaps(default_depth);
 
+#if !defined(__OpenBSD__)
   shmctl(shm_segment_info_->shmid, IPC_RMID, nullptr);
+#endif
   shm_segment_info_->shmid = -1;
 
   RTC_LOG(LS_VERBOSE) << "Using X shared memory extension v" << major << "."
