--- spnklog.cpp.orig	2008-02-18 12:19:32.000000000 +0800
+++ spnklog.cpp	2008-02-18 12:19:41.000000000 +0800
@@ -107,7 +107,7 @@
 		snprintf( logText, sizeof( logText ),
 			"%04i-%02i-%02i %02i:%02i:%02i #%i ",
 			1900 + tmTime.tm_year, tmTime.tm_mon+1, tmTime.tm_mday,
-			tmTime.tm_hour, tmTime.tm_min, tmTime.tm_sec, (int)pthread_self() );
+			tmTime.tm_hour, tmTime.tm_min, tmTime.tm_sec, pthread_self() );
 	}
 
 	if( mIsLogPriName ) {
