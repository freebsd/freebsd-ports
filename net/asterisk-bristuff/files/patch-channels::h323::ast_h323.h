
$FreeBSD$

--- channels/h323/ast_h323.h.orig	Thu Jan 12 18:14:49 2006
+++ channels/h323/ast_h323.h	Thu Jan 12 18:15:02 2006
@@ -155,8 +155,8 @@ class MyH323Connection : public H323Conn
 	H323Channel * CreateRealTimeLogicalChannel(const H323Capability &, 
 						   H323Channel::Directions, 
 					 	   unsigned, 
-						   const H245_H2250LogicalChannelParameters *,
-						   RTP_QOS *);
+						   const H245_H2250LogicalChannelParameters * /* ,
+						   RTP_QOS * */);
 	H323Connection::AnswerCallResponse OnAnswerCall(const PString &, 
 							const H323SignalPDU &, 
 							H323SignalPDU &);
