--- kiltdown/folderdb.cc.orig	Mon May 14 05:25:23 2001
+++ kiltdown/folderdb.cc	Sun Aug 10 14:40:43 2003
@@ -152,35 +152,35 @@
 } persistenceTable [] = {
 
     // sender
-    { PT_STRINGLIST, 1, {(void (MailMessage::*)())&MailMessage::getSenders}, {(void (MailMessage::*)())&MailMessage::setSenders} },
+    { PT_STRINGLIST, 1, (void (MailMessage::*)())&MailMessage::getSenders, (void (MailMessage::*)())&MailMessage::setSenders },
     // realsender
-    { PT_STRING, 1, {(void (MailMessage::*)())&MailMessage::getRealSender}, {(void (MailMessage::*)())&MailMessage::setRealSender} },
+    { PT_STRING, 1, (void (MailMessage::*)())&MailMessage::getRealSender, (void (MailMessage::*)())&MailMessage::setRealSender },
     // recipient(s)
-    { PT_STRINGLIST, 1, {(void (MailMessage::*)())&MailMessage::getRecipients}, {(void (MailMessage::*)())&MailMessage::setRecipients} },
+    { PT_STRINGLIST, 1, (void (MailMessage::*)())&MailMessage::getRecipients, (void (MailMessage::*)())&MailMessage::setRecipients },
     // replyto
-    { PT_STRING, 2, {(void (MailMessage::*)())&MailMessage::getReplyTo}, {(void (MailMessage::*)())&MailMessage::setReplyTo} },
+    { PT_STRING, 2, (void (MailMessage::*)())&MailMessage::getReplyTo, (void (MailMessage::*)())&MailMessage::setReplyTo },
     // returnpath
-    { PT_STRING, 2, {(void (MailMessage::*)())&MailMessage::getReturnPath}, {(void (MailMessage::*)())&MailMessage::setReturnPath} },
+    { PT_STRING, 2, (void (MailMessage::*)())&MailMessage::getReturnPath, (void (MailMessage::*)())&MailMessage::setReturnPath },
     // cc(s)
-    { PT_STRINGLIST, 1, {(void (MailMessage::*)())&MailMessage::getCCs}, {(void (MailMessage::*)())&MailMessage::setCCs} },
+    { PT_STRINGLIST, 1, (void (MailMessage::*)())&MailMessage::getCCs, (void (MailMessage::*)())&MailMessage::setCCs },
     // bcc(s)
-    { PT_STRINGLIST, 1, {(void (MailMessage::*)())&MailMessage::getBCCs}, {(void (MailMessage::*)())&MailMessage::setBCCs} },
+    { PT_STRINGLIST, 1, (void (MailMessage::*)())&MailMessage::getBCCs, (void (MailMessage::*)())&MailMessage::setBCCs },
     // subject
-    { PT_STRING, 1, {(void (MailMessage::*)())&MailMessage::getSubject}, {(void (MailMessage::*)())&MailMessage::setSubject} },
+    { PT_STRING, 1, (void (MailMessage::*)())&MailMessage::getSubject, (void (MailMessage::*)())&MailMessage::setSubject },
     // sent
-    { PT_DATE, 1, {(void (MailMessage::*)())(ERRCODE (MailMessage::*)(time_t *))&MailMessage::getSent}, {(void (MailMessage::*)())&MailMessage::setSent}  },
+    { PT_DATE, 1, (void (MailMessage::*)())(ERRCODE (MailMessage::*)(time_t *))&MailMessage::getSent, (void (MailMessage::*)())&MailMessage::setSent },
     // received
-    { PT_DATE, 1, {(void (MailMessage::*)())(ERRCODE (MailMessage::*)(time_t *))&MailMessage::getReceived}, {(void (MailMessage::*)())&MailMessage::setReceived} },
+    { PT_DATE, 1, (void (MailMessage::*)())(ERRCODE (MailMessage::*)(time_t *))&MailMessage::getReceived, (void (MailMessage::*)())&MailMessage::setReceived },
     // has attachment(s)
-    { PT_BOOLEAN, 1, {(void (MailMessage::*)())&MailMessage::getHasAttachments}, {(void (MailMessage::*)())&MailMessage::setHasAttachments} },
+    { PT_BOOLEAN, 1, (void (MailMessage::*)())&MailMessage::getHasAttachments, (void (MailMessage::*)())&MailMessage::setHasAttachments },
     // priority
-    { PT_INTEGER, 1, {(void (MailMessage::*)())&MailMessage::getPriority}, {(void (MailMessage::*)())&MailMessage::setPriority} },
+    { PT_INTEGER, 1, (void (MailMessage::*)())&MailMessage::getPriority, (void (MailMessage::*)())&MailMessage::setPriority },
     // size
-    { PT_INTEGER, 1, {(void (MailMessage::*)())&MailMessage::getSize}, {(void (MailMessage::*)())&MailMessage::setSize} },
+    { PT_INTEGER, 1, (void (MailMessage::*)())&MailMessage::getSize, (void (MailMessage::*)())&MailMessage::setSize },
     // status
-    { PT_INTEGER, 1, {(void (MailMessage::*)())&MailMessage::getStatus}, {(void (MailMessage::*)())&MailMessage::setStatus} },
+    { PT_INTEGER, 1, (void (MailMessage::*)())&MailMessage::getStatus, (void (MailMessage::*)())&MailMessage::setStatus },
     // extra headers
-    { PT_STRINGLIST, 1, {(void (MailMessage::*)())&MailMessage::getExtraHeaders}, {(void (MailMessage::*)())&MailMessage::setExtraHeaders} },
+    { PT_STRINGLIST, 1, (void (MailMessage::*)())&MailMessage::getExtraHeaders, (void (MailMessage::*)())&MailMessage::setExtraHeaders },
 
     // that's it!
     { PT_FINITO, -1, NULL, NULL }
