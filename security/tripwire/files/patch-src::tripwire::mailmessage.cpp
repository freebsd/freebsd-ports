--- src/tripwire/mailmessage.cpp.orig	Thu Jul  5 05:16:34 2001
+++ src/tripwire/mailmessage.cpp	Thu Jul  5 05:16:47 2001
@@ -241,7 +241,7 @@
 	time_t current_time = time(NULL);
 	tm = localtime ( &current_time );
 	
-	const TCHAR* szFormat = _T("%a %d %b %Y %H:%M:%S %z");
+	const TCHAR* szFormat = _T("%a, %d %b %Y %H:%M:%S %z");
 	
 	size_t numChars = _tcsftime( szDate, countof( szDate ), szFormat, tm );
 	
