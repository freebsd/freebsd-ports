--- src/belle_sip_headers_impl.c.orig	2016-08-11 09:23:59 UTC
+++ src/belle_sip_headers_impl.c
@@ -1672,11 +1672,6 @@ BELLESIP_EXPORT time_t belle_sip_header_
 	char tmp2[16] ={0};
 	int i,j;
 	time_t seconds;
-#if defined(BELLE_SIP_WINDOWS_UNIVERSAL) || defined(BELLE_SIP_MSC_VER_GREATER_19)
-	long adjust_timezone;
-#else
-	time_t adjust_timezone;
-#endif
 
 
 	/* time headers are in GMT as spec says */
@@ -1698,26 +1693,12 @@ BELLESIP_EXPORT time_t belle_sip_header_
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
-#if defined(BELLE_SIP_WINDOWS_UNIVERSAL) || defined(BELLE_SIP_MSC_VER_GREATER_19)
-	_get_timezone(&adjust_timezone);
-#else
-	adjust_timezone = timezone;
-#endif
-#endif
-
 	if (seconds==(time_t)-1){
-		belle_sip_error("mktime() failed: %s",strerror(errno));
+		belle_sip_error("timegm() failed: %s",strerror(errno));
 		return (time_t)-1;
 	}
-	return seconds-(time_t)adjust_timezone;
+	return seconds;
 }
 
 BELLESIP_EXPORT void belle_sip_header_date_set_time(belle_sip_header_date_t *obj, const time_t *utc_time){
