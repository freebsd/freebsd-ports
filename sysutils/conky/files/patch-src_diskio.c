--- src/diskio.c.orig	2008-05-26 11:36:44.000000000 -0400
+++ src/diskio.c	2008-05-26 11:43:00.000000000 -0400
@@ -73,11 +73,11 @@ struct diskio_stat *prepare_diskio_stat(
 		free(new->dev);
 		new->dev = 0;
 	}
-	if (strncmp(s, "/dev/", 5) == 0) {
+	if (strncmp(s, "/dev/", 5) == 0 && strlen(s) > 5) {
 		// supplied a /dev/device arg, so cut off the /dev part
-		new->dev = strndup(s + 5, text_buffer_size);
+		new->dev = strdup(s + 5);
 	} else {
-		new->dev = strndup(s, text_buffer_size);
+		new->dev = strdup(s);
 	}
 	/*
 	 * check that device actually exists
