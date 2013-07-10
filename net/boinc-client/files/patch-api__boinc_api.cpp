--- api/boinc_api.cpp.old	2013-05-17 14:10:37.000000000 +0300
+++ api/boinc_api.cpp	2013-05-17 14:10:49.000000000 +0300
@@ -111,7 +111,7 @@
     // CPPFLAGS=-DGETRUSAGE_IN_TIMER_THREAD
 #endif
 
-const char* api_version="API_VERSION_"PACKAGE_VERSION;
+const char* api_version="API_VERSION_" PACKAGE_VERSION;
 static APP_INIT_DATA aid;
 static FILE_LOCK file_lock;
 APP_CLIENT_SHM* app_client_shm = 0;
