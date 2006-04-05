--- src/vfakeio.cpp.orig	Wed Apr  5 19:20:41 2006
+++ src/vfakeio.cpp	Wed Apr  5 19:20:56 2006
@@ -51,10 +51,10 @@
 #ifndef DISABLE_GNOME
 #include <libgnomevfs/gnome-vfs.h>
 
-const size_t GMH323FakeVideoInputDevice::buffer_size = 4096;
+const size_t PVideoInputDevice_Picture::buffer_size = 4096;
 #endif
 
-GMH323FakeVideoInputDevice::GMH323FakeVideoInputDevice ()
+PVideoInputDevice_Picture::PVideoInputDevice_Picture ()
 {
   orig_pix = NULL;
   cached_pix = NULL;
@@ -73,7 +73,7 @@
 }
 
 
-GMH323FakeVideoInputDevice::~GMH323FakeVideoInputDevice ()
+PVideoInputDevice_Picture::~PVideoInputDevice_Picture ()
 {
   Close ();
 
@@ -83,12 +83,12 @@
 }
 
 #ifndef DISABLE_GNOME
-void GMH323FakeVideoInputDevice::loader_area_updated_cb (GdkPixbufLoader *loader,
+void PVideoInputDevice_Picture::loader_area_updated_cb (GdkPixbufLoader *loader,
 							 gint x, gint y, gint width,
 							 gint height, 
 							 gpointer thisclass)
 {
-  GMH323FakeVideoInputDevice *thisc = static_cast<GMH323FakeVideoInputDevice *> (thisclass);
+  PVideoInputDevice_Picture *thisc = static_cast<PVideoInputDevice_Picture *> (thisclass);
 
   PWaitAndSignal m(thisc->pixbuf_mutex);
 
@@ -103,11 +103,11 @@
   g_object_ref (G_OBJECT (thisc->orig_pix));
 }
 
-void GMH323FakeVideoInputDevice::async_close_cb (GnomeVFSAsyncHandle *fp,
+void PVideoInputDevice_Picture::async_close_cb (GnomeVFSAsyncHandle *fp,
 						 GnomeVFSResult result, 
 						 gpointer thisclass)
 {
-  GMH323FakeVideoInputDevice *thisc = static_cast<GMH323FakeVideoInputDevice *> (thisclass);
+  PVideoInputDevice_Picture *thisc = static_cast<PVideoInputDevice_Picture *> (thisclass);
 
   PWaitAndSignal m(thisc->pixbuf_mutex);
 
@@ -118,14 +118,14 @@
   }
 }
 
-void GMH323FakeVideoInputDevice::async_read_cb (GnomeVFSAsyncHandle *fp,
+void PVideoInputDevice_Picture::async_read_cb (GnomeVFSAsyncHandle *fp,
 						GnomeVFSResult result, 
 						gpointer buffer,
 						GnomeVFSFileSize requested,
 						GnomeVFSFileSize bytes_read,
 						gpointer thisclass)
 {
-  GMH323FakeVideoInputDevice *thisc = static_cast<GMH323FakeVideoInputDevice *> (thisclass);
+  PVideoInputDevice_Picture *thisc = static_cast<PVideoInputDevice_Picture *> (thisclass);
   
   if (result != GNOME_VFS_OK && result != GNOME_VFS_ERROR_EOF) {
     gnome_vfs_async_close (fp, async_close_cb, thisclass);
@@ -144,11 +144,11 @@
   }
 }
 
-void GMH323FakeVideoInputDevice::async_open_cb (GnomeVFSAsyncHandle *fp,
+void PVideoInputDevice_Picture::async_open_cb (GnomeVFSAsyncHandle *fp,
 						GnomeVFSResult result, 
 						gpointer thisclass)
 {
-  GMH323FakeVideoInputDevice *thisc = static_cast<GMH323FakeVideoInputDevice *> (thisclass);
+  PVideoInputDevice_Picture *thisc = static_cast<PVideoInputDevice_Picture *> (thisclass);
   
 
   if (result != GNOME_VFS_OK) {
@@ -160,7 +160,7 @@
 			async_read_cb, thisclass);
 }
 
-gboolean GMH323FakeVideoInputDevice::async_cancel (gpointer data)
+gboolean PVideoInputDevice_Picture::async_cancel (gpointer data)
 {
   gnome_vfs_async_cancel ((GnomeVFSAsyncHandle *)data);
 
@@ -169,7 +169,7 @@
 #endif
 
 BOOL
-GMH323FakeVideoInputDevice::Open (const PString &name,
+PVideoInputDevice_Picture::Open (const PString &name,
 				  BOOL start_immediate)
 {
   gchar *image_name = NULL;
@@ -222,7 +222,7 @@
 
 
 BOOL
-GMH323FakeVideoInputDevice::IsOpen ()
+PVideoInputDevice_Picture::IsOpen ()
 {
   if (orig_pix) 
     return TRUE;
@@ -232,7 +232,7 @@
 
 
 BOOL
-GMH323FakeVideoInputDevice::Close ()
+PVideoInputDevice_Picture::Close ()
 {
   gnomemeeting_threads_enter ();
 #ifndef DISABLE_GNOME
@@ -264,28 +264,28 @@
 
   
 BOOL
-GMH323FakeVideoInputDevice::Start ()
+PVideoInputDevice_Picture::Start ()
 {
   return TRUE;
 }
 
   
 BOOL
-GMH323FakeVideoInputDevice::Stop ()
+PVideoInputDevice_Picture::Stop ()
 {
   return TRUE;
 }
 
 
 BOOL
-GMH323FakeVideoInputDevice::IsCapturing ()
+PVideoInputDevice_Picture::IsCapturing ()
 {
   return IsCapturing ();
 }
 
 
 PStringList
-GMH323FakeVideoInputDevice::GetInputDeviceNames ()
+PVideoInputDevice_Picture::GetInputDeviceNames ()
 {
   PStringList l;
 
@@ -297,7 +297,7 @@
 
 
 BOOL
-GMH323FakeVideoInputDevice::SetFrameSize (unsigned int width,
+PVideoInputDevice_Picture::SetFrameSize (unsigned int width,
 					  unsigned int height)
 {
   if (!PVideoDevice::SetFrameSize (width, height))
@@ -308,7 +308,7 @@
 
 
 BOOL
-GMH323FakeVideoInputDevice::GetFrame (PBYTEArray &a)
+PVideoInputDevice_Picture::GetFrame (PBYTEArray &a)
 {
   PINDEX returned;
 
@@ -322,7 +322,7 @@
 
 
 BOOL
-GMH323FakeVideoInputDevice::GetFrameData (BYTE *a, PINDEX *i)
+PVideoInputDevice_Picture::GetFrameData (BYTE *a, PINDEX *i)
 {
   WaitFinishPreviousFrame ();
 
@@ -334,7 +334,7 @@
 }
 
 
-BOOL GMH323FakeVideoInputDevice::GetFrameDataNoDelay (BYTE *frame, PINDEX *i)
+BOOL PVideoInputDevice_Picture::GetFrameDataNoDelay (BYTE *frame, PINDEX *i)
 {
   guchar *data = NULL;
 
@@ -418,21 +418,21 @@
 
 
 BOOL
-GMH323FakeVideoInputDevice::TestAllFormats ()
+PVideoInputDevice_Picture::TestAllFormats ()
 {
   return TRUE;
 }
 
 
 PINDEX
-GMH323FakeVideoInputDevice::GetMaxFrameBytes ()
+PVideoInputDevice_Picture::GetMaxFrameBytes ()
 {
   return CalculateFrameBytes (frameWidth, frameHeight, colourFormat);
 }
 
 
 void
-GMH323FakeVideoInputDevice::WaitFinishPreviousFrame ()
+PVideoInputDevice_Picture::WaitFinishPreviousFrame ()
 {
   frameTimeError += msBetweenFrames;
 
@@ -454,28 +454,28 @@
 
 
 BOOL
-GMH323FakeVideoInputDevice::SetVideoFormat (VideoFormat newFormat)
+PVideoInputDevice_Picture::SetVideoFormat (VideoFormat newFormat)
 {
   return PVideoDevice::SetVideoFormat (newFormat);
 }
 
 
 int
-GMH323FakeVideoInputDevice::GetNumChannels()
+PVideoInputDevice_Picture::GetNumChannels()
 {
   return 1;
 }
 
 
 BOOL
-GMH323FakeVideoInputDevice::SetChannel (int newChannel)
+PVideoInputDevice_Picture::SetChannel (int newChannel)
 {
   return PVideoDevice::SetChannel (newChannel);
 }
 
 
 BOOL
-GMH323FakeVideoInputDevice::SetColourFormat (const PString &newFormat)
+PVideoInputDevice_Picture::SetColourFormat (const PString &newFormat)
 {
   if (newFormat == "BGR32") 
     return PVideoDevice::SetColourFormat (newFormat);
@@ -485,7 +485,7 @@
 
 
 BOOL
-GMH323FakeVideoInputDevice::SetFrameRate (unsigned rate)
+PVideoInputDevice_Picture::SetFrameRate (unsigned rate)
 {
   PVideoDevice::SetFrameRate (12);
  
@@ -494,7 +494,7 @@
 
 
 BOOL
-GMH323FakeVideoInputDevice::GetFrameSizeLimits (unsigned & minWidth,
+PVideoInputDevice_Picture::GetFrameSizeLimits (unsigned & minWidth,
 						unsigned & minHeight,
 						unsigned & maxWidth,
 						unsigned & maxHeight)
