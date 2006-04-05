--- src/sound_handling.cpp.orig	Sun Mar  6 14:11:32 2005
+++ src/sound_handling.cpp	Fri Mar 17 20:27:11 2006
@@ -278,8 +278,8 @@
      test anyway */
   static GMLid *l = NULL;
   static PMutex lid_mutex;
-  PINDEX i;
 #endif
+  PINDEX i;
   
   GMH323EndPoint *ep = NULL;
   
@@ -335,9 +335,12 @@
   gdk_threads_leave ();
   g_free (msg);
 
+#ifdef HAS_IXJ
   if ((driver_name != "Quicknet" && !channel)
       || (driver_name == "Quicknet" && (!l || !l->IsOpen ()))) {
-
+#else
+  if (driver_name != "Quicknet" && !channel) {
+#endif
     gdk_threads_enter ();  
     if (is_encoding)
       gnomemeeting_error_dialog (GTK_WINDOW (druid_window), _("Failed to open the device"), _("Impossible to open the selected audio device (%s) for recording. Please check your audio setup, the permissions and that the device is not busy."), (const char *) device_name);
@@ -374,11 +377,16 @@
       
       if (is_encoding) {
 
+#ifdef HAS_IXJ
 	if ((driver_name != "Quicknet"
 	     && !channel->Read ((void *) buffer, 640))
 	    || (driver_name == "Quicknet"
 		&& l
 		&& !l->ReadFrame (0, (void *) buffer, i)))  {
+#else
+	if ((driver_name != "Quicknet"
+	     && !channel->Read ((void *) buffer, 640))) {
+#endif
       
 	  gdk_threads_enter ();  
 	  gnomemeeting_error_dialog (GTK_WINDOW (druid_window), _("Cannot use the audio device"), _("The selected audio device (%s) was successfully opened but it is impossible to read data from this device. Please check your audio setup."), (const char*) device_name);
@@ -450,11 +458,17 @@
 	
 	  buffer_pos += 640;
 
+#ifdef HAS_IXJ
 	  if ((driver_name != "Quicknet"
 	       && !channel->Write ((void *) buffer, 640))
 	      || (driver_name == "Quicknet"
 		  && l
 		  && !l->WriteFrame (0, (const void *) buffer, 640, i)))  {
+#else
+	  if ((driver_name != "Quicknet"
+	       && !channel->Write ((void *) buffer, 640))) {
+
+#endif
       
 	    gdk_threads_enter ();  
 	    gnomemeeting_error_dialog (GTK_WINDOW (druid_window), _("Cannot use the audio device"), _("The selected audio device (%s) was successfully opened but it is impossible to write data to this device. Please check your audio setup."), (const char*) device_name);
@@ -486,7 +500,9 @@
   nbr_opened_channels = PMAX (nbr_opened_channels--, 0);
 
   free (buffer);
+#ifdef HAS_IXJ
   l = NULL;
+#endif
 }
 
 
