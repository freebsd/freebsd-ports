--- xdao/SoundIF-ao.cc.orig	2010-06-06 16:37:14.000000000 +0200
+++ xdao/SoundIF-ao.cc	2010-06-06 16:42:17.000000000 +0200
@@ -37,6 +37,7 @@ SoundIF::SoundIF()
 
   impl_ = new SoundIFImpl;
   impl_->driverId = ao_default_driver_id();
+  memset(&impl_->format, 0, sizeof(impl_->format));
   impl_->format.bits = 16;
   impl_->format.rate = 44100;
   impl_->format.channels = 2;
