--- kmess/network/applications/p2papplication.cpp.orig	Sun Jun  4 15:00:05 2006
+++ kmess/network/applications/p2papplication.cpp	Sun Jun  4 15:00:44 2006
@@ -2056,7 +2056,7 @@
   // Get message content and Content-Type
   bool gotTransferInvitation = (invitationContentType_ == "application/x-msnmsgr-transreqbody");
   QString content     = message.getFields();
-  QString contentType = (gotTransferInvitation ? "application/x-msnmsgr-transrespbody" : invitationContentType_);
+  QString contentType = (gotTransferInvitation ? QString::fromLatin1("application/x-msnmsgr-transrespbody") : invitationContentType_);
 
   QString myHandle = CurrentAccount::instance()->getHandle();
 
