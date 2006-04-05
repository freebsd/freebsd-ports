--- src/config.cpp.orig	Sun Jan 30 12:27:01 2005
+++ src/config.cpp	Sun Jan 30 12:29:38 2005
@@ -826,10 +826,12 @@
 	&& !strcmp (gm_conf_entry_get_key (entry),
 		    AUDIO_DEVICES_KEY "input_device")) {
       
+#ifdef HAS_IXJ
       if (dev.Find ("/dev/phone") != P_MAX_INDEX) 
 	ep->CreateLid (dev);
       else 
 	ep->RemoveLid ();
+#endif
       
       capa = ep->GetAvailableAudioCapabilities ();
 
