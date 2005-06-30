--- kopete/protocols/oscar/oscarcontact.cpp.orig	Thu Jun 30 02:18:56 2005
+++ kopete/protocols/oscar/oscarcontact.cpp	Thu Jun 30 02:19:24 2005
@@ -183,7 +183,7 @@
 	Q_UNUSED( session );
 	Oscar::Message message;
 	
-	message.setText( msg.escapedBody() );
+	message.setText( msg.plainBody() );
 	
 	message.setTimestamp( msg.timestamp() );
 	message.setSender( mAccount->accountId() );
