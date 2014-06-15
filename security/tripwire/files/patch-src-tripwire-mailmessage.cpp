--- src/tripwire/mailmessage.cpp.orig	2011-11-21 17:06:56.000000000 +0100
+++ src/tripwire/mailmessage.cpp	2014-06-15 01:56:20.000000000 +0200
@@ -258,7 +258,7 @@ bool cMailMessageUtil::ReadDate( TSTRING
 }
 
 
-static char* util_Get_IANA_CharSet()
+static const char* util_Get_IANA_CharSet()
 {
     const char* pCP = setlocale( LC_CTYPE, NULL );
 
