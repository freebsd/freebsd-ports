--- ErrorLogger.cpp.orig	Tue Mar 14 23:43:02 2000
+++ ErrorLogger.cpp	Fri Dec  1 22:27:20 2006
@@ -28,6 +28,8 @@
 using std::ofstream;
 using std::string;
 using std::list;
+using std::ios;
+using std::endl;
 
 ErrorLogger* ErrorLogger::instance = 0;
 
