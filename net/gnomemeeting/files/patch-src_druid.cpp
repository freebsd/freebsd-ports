--- src/druid.cpp.orig	Sun Mar 13 15:15:47 2005
+++ src/druid.cpp	Sun Mar 13 15:17:05 2005
@@ -1682,9 +1682,11 @@
    * not for a random one.
    */
   gnomemeeting_sound_daemons_suspend ();
+#ifdef HAS_IXJ
   if (PString ("Quicknet") == audio_manager)
     devices = OpalIxJDevice::GetDeviceNames ();
   else
+#endif
     devices = PSoundChannel::GetDeviceNames (audio_manager,
 					     PSoundChannel::Player);
   if (devices.GetSize () == 0) {
@@ -1699,9 +1701,11 @@
   gm_dw_option_menu_update (dw->audio_player, array, player);
   free (array);
 
+#ifdef HAS_IXJ
   if (PString ("Quicknet") == audio_manager)
     devices = OpalIxJDevice::GetDeviceNames ();
   else
+#endif
     devices = PSoundChannel::GetDeviceNames (audio_manager,
 					     PSoundChannel::Recorder);
   if (devices.GetSize () == 0) {
