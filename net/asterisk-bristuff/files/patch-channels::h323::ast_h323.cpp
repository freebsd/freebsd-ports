
$FreeBSD$

--- channels/h323/ast_h323.cpp.orig	Thu Jan 12 18:16:08 2006
+++ channels/h323/ast_h323.cpp	Thu Jan 12 18:16:35 2006
@@ -953,8 +953,8 @@ BOOL MyH323Connection::OnReceivedCapabil
 H323Channel * MyH323Connection::CreateRealTimeLogicalChannel(const H323Capability & capability,	
 								   H323Channel::Directions dir,
 								   unsigned sessionID,
-		 					           const H245_H2250LogicalChannelParameters * /*param*/,
-								   RTP_QOS * /*param*/ )
+		 					           const H245_H2250LogicalChannelParameters * /*param*/ /*,
+								   RTP_QOS * */ /*param*/ )
 {
 	return new MyH323_ExternalRTPChannel(*this, capability, dir, sessionID);
 }
