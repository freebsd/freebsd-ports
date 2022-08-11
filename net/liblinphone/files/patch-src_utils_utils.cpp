--- src/utils/utils.cpp.orig	2022-06-16 10:56:15 UTC
+++ src/utils/utils.cpp
@@ -142,7 +142,7 @@ string Utils::unicodeToUtf8 (uint32_t ic) {
 
 string Utils::unicodeToUtf8 (uint32_t ic) {
 	string result;
-	
+
 	result.resize(5);
 	size_t size = 0;
 	if (ic < 0x80) {
@@ -215,12 +215,6 @@ time_t Utils::getTmAsTimeT (const tm &t) {
 time_t Utils::getTmAsTimeT (const tm &t) {
 	time_t result;
 
-	#if defined(LINPHONE_WINDOWS_UNIVERSAL) || defined(LINPHONE_MSC_VER_GREATER_19)
-		long adjustTimezone;
-	#else
-		time_t adjustTimezone;
-	#endif
-
 	#if TARGET_IPHONE_SIMULATOR
 		result = timegm(&const_cast<tm &>(t));
 		adjustTimezone = 0;
@@ -228,11 +222,6 @@ time_t Utils::getTmAsTimeT (const tm &t) {
 		// mktime uses local time => It's necessary to adjust the timezone to get an UTC time.
 		result = mktime(&const_cast<tm &>(t));
 
-		#if defined(LINPHONE_WINDOWS_UNIVERSAL) || defined(LINPHONE_MSC_VER_GREATER_19)
-			_get_timezone(&adjustTimezone);
-		#else
-			adjustTimezone = timezone;
-		#endif
 	#endif
 
 	if (result == time_t(-1)) {
@@ -240,7 +229,7 @@ time_t Utils::getTmAsTimeT (const tm &t) {
 		return time_t(-1);
 	}
 
-	return result - time_t(adjustTimezone);
+	return result;
 }
 
 // -----------------------------------------------------------------------------
@@ -283,7 +272,7 @@ map<string, Utils::Version> Utils::parseCapabilityDesc
 		if (std::getline(capversion, cap, '/') && std::getline(capversion, version, '/')){
 			result[cap] = Utils::Version(version);
 		}else result[cap] = Utils::Version(1, 0);
-		
+
 	}
 	return result;
 }
