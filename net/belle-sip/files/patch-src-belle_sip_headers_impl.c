--- src/belle_sip_headers_impl.c.orig	2015-01-20 10:39:04 UTC
+++ src/belle_sip_headers_impl.c
@@ -1663,7 +1663,6 @@ BELLESIP_EXPORT time_t belle_sip_header_
 	char tmp2[16] ={0};
 	int i,j;
 	time_t seconds;
-	time_t adjust_timezone;
 
 
 	/* time headers are in GMT as spec says */
@@ -1685,22 +1684,12 @@ BELLESIP_EXPORT time_t belle_sip_header_
 	return (time_t)-1;
 success:
 	ret.tm_isdst=0;
-
-#if TARGET_IPHONE_SIMULATOR
-	/* 'timezone' is buggy on iOS simulator, use the timegm() function to convert to UTC timestamp
-	   and discard the adjust timezone value */
 	seconds = timegm(&ret);
-	adjust_timezone = 0;
-#else
-	seconds = mktime(&ret);
-	adjust_timezone = timezone;
-#endif
-
 	if (seconds==(time_t)-1){
-		belle_sip_error("mktime() failed: %s",strerror(errno));
+		belle_sip_error("timegm() failed: %s",strerror(errno));
 		return (time_t)-1;
 	}
-	return seconds-adjust_timezone;
+	return seconds;
 }
 
 BELLESIP_EXPORT void belle_sip_header_date_set_time(belle_sip_header_date_t *obj, const time_t *utc_time){
