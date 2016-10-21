--- coreapi/presence.c.orig	2016-08-18 12:21:44 UTC
+++ coreapi/presence.c
@@ -160,11 +160,6 @@ static void presence_activity_delete(Lin
 static time_t parse_timestamp(const char *timestamp) {
 	struct tm ret;
 	time_t seconds;
-#if defined(LINPHONE_WINDOWS_UNIVERSAL) || defined(LINPHONE_MSC_VER_GREATER_19)
-	long adjust_timezone;
-#else
-	time_t adjust_timezone;
-#endif
 
 	memset(&ret, 0, sizeof(ret));
 	sscanf(timestamp, "%d-%d-%dT%d:%d:%d",
@@ -172,17 +167,12 @@ static time_t parse_timestamp(const char
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
-#if defined(LINPHONE_WINDOWS_UNIVERSAL) || defined(LINPHONE_MSC_VER_GREATER_19)
-	_get_timezone(&adjust_timezone);
-#else
-	adjust_timezone = timezone;
-#endif
-	return seconds - (time_t)adjust_timezone;
+	return seconds;
 }
 
 char * linphone_timestamp_to_rfc3339_string(time_t timestamp) {
