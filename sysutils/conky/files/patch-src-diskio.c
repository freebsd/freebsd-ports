--- src/diskio.c.orig
+++ src/diskio.c
@@ -76,12 +76,6 @@ struct diskio_stat *prepare_diskio_stat(const char *s)
 	if (!s)
 		return &stats;
 
-#if defined(__FreeBSD__)
-	if (strncmp(s, "/dev/", 5) == 0) {
-		// supplied a /dev/device arg, so cut off the /dev part
-		strncpy(device_name, s + 5, text_buffer_size);
-	} else
-#endif
 	strncpy(device_name, s, text_buffer_size);
 
 	snprintf(stat_name, text_buffer_size, "/dev/%s", device_name);
