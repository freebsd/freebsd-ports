--- engine/TelEngine.cpp.orig	2014-08-19 12:09:15.000000000 +0300
+++ engine/TelEngine.cpp	2014-08-19 12:08:27.000000000 +0300
@@ -803,7 +803,7 @@ int Time::timeZone()
     if (localtime_r(&time,&t))
 	return t.tm_gmtoff;
 #endif
-    return -timezone;
+    return -(long int)timezone;
 #endif
 }
 
