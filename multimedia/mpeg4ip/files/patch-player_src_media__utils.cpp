--- player/src/media_utils.cpp.orig	2007-03-29 18:52:19 UTC
+++ player/src/media_utils.cpp
@@ -605,12 +605,12 @@ static int create_media_for_iptv (CPlaye
 				  int have_audio_driver,
 				  control_callback_vft_t *cc_vft)
 {
-  char *slash, *cm;
+  char *cm;
   uint64_t prog;
   session_desc_t *sdp;
 
   name += strlen("iptv://");
-  slash = strchr(name, '/');
+  const char *slash = strchr(name, '/');
   if (slash == NULL || slash == name) {
     psptr->set_message("Invalid iptv content manager");
     return -1;
@@ -618,8 +618,7 @@ static int create_media_for_iptv (CPlaye
   cm = (char *)malloc(slash - name + 1);
   memcpy(cm, name, slash - name);
   cm[slash - name] = '\0';
-  slash++;
-  if (sscanf(slash, U64, &prog) != 1) {
+  if (sscanf(slash + 1, U64, &prog) != 1) {
     psptr->set_message("Invalid iptv program");
     return -1;
   }
