--- cd-recorder.c.orig	Thu Oct  2 13:09:26 2003
+++ cd-recorder.c	Thu Oct  2 13:10:27 2003
@@ -334,12 +334,9 @@
 		cdrecorder->priv->music_count = build_list_of_music_arguments ("burn:///", &i, argv, 200-i-5);
 	} else {
 		cdrecorder->priv->music_count = 0;
+		argv[i++] = "-dao";  /* XXX, this is a hack. */
 		argv[i++] = "-data";
 		argv[i++] = filename;
-	}
-
-	if (needs_dvd_writer) {
-		argv[i++] = "-dao";
 	}
 
 	argv[i++] = NULL;
