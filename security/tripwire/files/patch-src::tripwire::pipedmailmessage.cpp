Index: src/tripwire/pipedmailmessage.cpp
===================================================================
retrieving revision 1.1
retrieving revision 1.2
diff -u -r1.1 -r1.2
--- src/tripwire/pipedmailmessage.cpp   21 Jan 2001 00:46:48 -0000      1.1
+++ src/tripwire/pipedmailmessage.cpp   26 May 2004 20:59:15 -0000      1.2
@@ -180,7 +180,7 @@

 void cPipedMailMessage::SendString( const TSTRING& s )
 {
-    if( _ftprintf( mpFile, s.c_str() ) < 0 )
+    if( _ftprintf( mpFile, "%s", s.c_str() ) < 0 )
     {
         TOSTRINGSTREAM estr;
         estr << TSS_GetString( cTripwire, tripwire::STR_ERR2_MAIL_MESSAGE_COMMAND )
