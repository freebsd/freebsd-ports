--- src/main.c.orig	Mon Apr 12 12:55:02 2004
+++ src/main.c	Thu Mar 22 19:00:30 2007
@@ -127,8 +127,8 @@
     }
 
     toxine_free(tox->configfile);
-    toxine_free((char *)tox->video.name);
-    toxine_free((char *)tox->audio.name);
+    toxine_free(tox->video.name);
+    toxine_free(tox->audio.name);
     toxine_free(tox->command.line);
     toxine_free(tox->command.remain);
     toxine_free(tox->command.command);
