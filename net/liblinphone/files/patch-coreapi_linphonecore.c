--- coreapi/linphonecore.c.orig	2023-07-28 13:53:32 UTC
+++ coreapi/linphonecore.c
@@ -799,7 +799,7 @@ static void _close_log_collection_file(void) {
 	}
 }
 
-#if (!__ANDROID__ && !__APPLE__) || (__ANDROID__ && __ANDROID_API__ < 21)
+#if (!__ANDROID__ && !__APPLE__ && !__FreeBSD__) || (__ANDROID__ && __ANDROID_API__ < 21)
 static const char* getprogname() {
 #if defined(__GLIBC__)
   	return program_invocation_short_name;
