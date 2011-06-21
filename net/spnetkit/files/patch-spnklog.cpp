--- spnklog.cpp.orig	2011-06-21 09:28:36.000000000 +0800
+++ spnklog.cpp	2011-06-21 09:29:24.000000000 +0800
@@ -168,7 +168,7 @@ void SP_NKLog :: log( int pri, const cha
 		snprintf( logText, sizeof( logText ),
 			"%04i-%02i-%02i %02i:%02i:%02i #%i ",
 			1900 + tmTime.tm_year, tmTime.tm_mon+1, tmTime.tm_mday,
-			tmTime.tm_hour, tmTime.tm_min, tmTime.tm_sec, (int)spnk_threadid() );
+			tmTime.tm_hour, tmTime.tm_min, tmTime.tm_sec, (long)spnk_threadid() );
 	}
 
 	if( mIsLogPriName ) {
