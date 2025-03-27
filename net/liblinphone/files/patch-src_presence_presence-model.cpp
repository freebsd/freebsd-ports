--- src/presence/presence-model.cpp.orig	2025-03-26 23:44:07 UTC
+++ src/presence/presence-model.cpp
@@ -656,11 +656,6 @@ time_t PresenceModel::parseTimestamp(const std::string
 time_t PresenceModel::parseTimestamp(const std::string &timestamp) {
 	struct tm ret;
 	time_t seconds;
-#if defined(LINPHONE_WINDOWS_UNIVERSAL) || defined(LINPHONE_MSC_VER_GREATER_19)
-	long adjustTimezone;
-#else
-	time_t adjustTimezone;
-#endif
 
 	memset(&ret, 0, sizeof(ret));
 	sscanf(L_STRING_TO_C(timestamp), "%d-%d-%dT%d:%d:%d", &ret.tm_year, &ret.tm_mon, &ret.tm_mday, &ret.tm_hour,
@@ -673,12 +668,7 @@ time_t PresenceModel::parseTimestamp(const std::string
 		ms_error("mktime() failed: %s", strerror(errno));
 		return (time_t)-1;
 	}
-#if defined(LINPHONE_WINDOWS_UNIVERSAL) || defined(LINPHONE_MSC_VER_GREATER_19)
-	_get_timezone(&adjustTimezone);
-#else
-	adjustTimezone = timezone;
-#endif
-	return seconds - (time_t)adjustTimezone;
+	return seconds;
 }
 
 #else
