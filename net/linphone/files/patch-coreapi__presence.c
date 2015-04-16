--- coreapi/presence.c.orig	2015-04-02 09:04:01 UTC
+++ coreapi/presence.c
@@ -164,12 +164,12 @@ static time_t parse_timestamp(const char
 	ret.tm_mon--;
 	ret.tm_year -= 1900;
 	ret.tm_isdst = 0;
-	seconds = mktime(&ret);
+	seconds = timegm(&ret);
 	if (seconds == (time_t)-1) {
-		ms_error("mktime() failed: %s", strerror(errno));
+		ms_error("timegm() failed: %s", strerror(errno));
 		return (time_t)-1;
 	}
-	return seconds - timezone;
+	return seconds;
 }
 
 char * linphone_timestamp_to_rfc3339_string(time_t timestamp) {
