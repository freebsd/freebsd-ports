--- src/vfakeio.h.orig	Wed Apr  5 19:20:50 2006
+++ src/vfakeio.h	Wed Apr  5 19:22:28 2006
@@ -48,9 +48,9 @@
 #include <libgnomevfs/gnome-vfs.h>
 #endif
  
-class GMH323FakeVideoInputDevice : public PVideoInputDevice 
+class PVideoInputDevice_Picture : public PVideoInputDevice 
 {
-  PCLASSINFO(GMH323FakeVideoInputDevice, PVideoInputDevice);
+  PCLASSINFO(PVideoInputDevice_Picture, PVideoInputDevice);
 
   PMutex pixbuf_mutex;      /* To protect the pixbufs that are read and written
 			    from various threads */
@@ -112,14 +112,14 @@
    * BEHAVIOR     :  Creates the Fake Input Device.
    * PRE          :  /
    */
-  GMH323FakeVideoInputDevice ();
+  PVideoInputDevice_Picture();
 
 
   /* DESCRIPTION  :  The destructor
    * BEHAVIOR     :  /
    * PRE          :  /
    */
-  ~GMH323FakeVideoInputDevice ();
+  ~PVideoInputDevice_Picture();
 
   
   BOOL Open (const PString &,
@@ -245,6 +245,6 @@
   { return GetInputDeviceNames(); }
 };
 
-PCREATE_VIDINPUT_PLUGIN (Picture, GMH323FakeVideoInputDevice);
+PCREATE_VIDINPUT_PLUGIN (Picture);
 
 #endif
