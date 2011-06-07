--- ui/gfx/surface/transport_dib_mac.cc.orig	2011-06-05 20:47:40.781162828 +0300
+++ ui/gfx/surface/transport_dib_mac.cc	2011-06-05 20:47:51.617166566 +0300
@@ -96,3 +96,12 @@
 TransportDIB::Handle TransportDIB::handle() const {
   return shared_memory_.handle();
 }
+
+XID TransportDIB::MapToX(Display* display) {
+  if (!x_shm_) {
+    x_shm_ = ui::AttachSharedMemory(display, key_);
+    display_ = display;
+  }
+
+  return x_shm_;
+}
