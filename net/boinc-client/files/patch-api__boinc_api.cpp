--- ./api/boinc_api.cpp.orig	2013-07-24 15:13:28.000000000 +0000
+++ ./api/boinc_api.cpp	2013-09-17 21:16:00.000000000 +0000
@@ -120,7 +120,7 @@
     // CPPFLAGS=-DGETRUSAGE_IN_TIMER_THREAD
 #endif
 
-const char* api_version="API_VERSION_"PACKAGE_VERSION;
+const char* api_version="API_VERSION_" PACKAGE_VERSION;
 static APP_INIT_DATA aid;
 static FILE_LOCK file_lock;
 APP_CLIENT_SHM* app_client_shm = 0;
