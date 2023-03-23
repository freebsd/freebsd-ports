--- src/utils/utils.cpp.orig	2023-03-17 13:29:37 UTC
+++ src/utils/utils.cpp
@@ -148,7 +148,7 @@ string Utils::unicodeToUtf8 (uint32_t ic) {
 
 string Utils::unicodeToUtf8 (uint32_t ic) {
 	string result;
-	
+
 	result.resize(5);
 	size_t size = 0;
 	if (ic < 0x80) {
@@ -222,12 +222,6 @@ time_t Utils::getTmAsTimeT (const tm &t) {
 	tm tCopy = t;
 	time_t result;
 
-	#if defined(LINPHONE_WINDOWS_UNIVERSAL) || defined(LINPHONE_MSC_VER_GREATER_19)
-		long adjustTimezone;
-	#else
-		time_t adjustTimezone;
-	#endif
-
 	#if TARGET_IPHONE_SIMULATOR
 		result = timegm(&tCopy);
 		adjustTimezone = 0;
@@ -235,11 +229,6 @@ time_t Utils::getTmAsTimeT (const tm &t) {
 		// mktime uses local time => It's necessary to adjust the timezone to get an UTC time.
 		result = mktime(&tCopy);
 
-		#if defined(LINPHONE_WINDOWS_UNIVERSAL) || defined(LINPHONE_MSC_VER_GREATER_19)
-			_get_timezone(&adjustTimezone);
-		#else
-			adjustTimezone = timezone;
-		#endif
 	#endif
 
 	if (result == time_t(-1)) {
@@ -249,7 +238,7 @@ time_t Utils::getTmAsTimeT (const tm &t) {
 		return time_t(-1);
 	}
 
-	return result - time_t(adjustTimezone);
+	return result;
 }
 
 std::string Utils::getTimeAsString (const std::string &format, time_t t) {
@@ -327,7 +316,7 @@ map<string, Utils::Version> Utils::parseCapabilityDesc
 		if (std::getline(capversion, cap, '/') && std::getline(capversion, version, '/')){
 			result[cap] = Utils::Version(version);
 		}else result[cap] = Utils::Version(1, 0);
-		
+
 	}
 	return result;
 }
