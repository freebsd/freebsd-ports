--- quicktime/libdv/oss.c.orig	Mon Feb 12 22:35:19 2001
+++ quicktime/libdv/oss.c	Mon Nov  1 09:41:06 2004
@@ -82,7 +82,7 @@
   if(oss->arg_audio_device && oss->arg_audio_file) goto usage;
   if(oss->arg_audio_file) {
     if ((oss->fd = open(oss->arg_audio_file, 
-			O_WRONLY|O_CREAT|O_TRUNC|O_LARGEFILE,
+			O_WRONLY|O_CREAT|O_TRUNC,
 			S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP)) == -1) goto no_file;
   } else {
     device = (gchar *)(oss->arg_audio_device ? oss->arg_audio_device : default_device);
