--- coreapi/presence.c.orig
+++ coreapi/presence.c
@@ -167,7 +167,7 @@
 		ms_error("mktime() failed: %s", strerror(errno));
 		return (time_t)-1;
 	}
-	return seconds - timezone;
+	return seconds;
 }
 
 static char * timestamp_to_string(time_t timestamp) {
