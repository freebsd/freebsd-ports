--- src/usereventdlg.cpp.orig	Sun Mar 23 18:49:39 2003
+++ src/usereventdlg.cpp	Sat Mar 29 08:31:33 2003
@@ -1390,7 +1390,7 @@
     {
       CEventMsg *ue = (CEventMsg *)e->UserEvent();
       // create initial strings (implicit copying, no allocation impact :)
-      char *tmp = gTranslator.NToRN(codec->fromUnicode(ue->Message()));
+      char *tmp = gTranslator.NToRN(ue->Message());
       QCString wholeMessageRaw(tmp);
       delete [] tmp;
       unsigned int wholeMessagePos = 0;
@@ -1439,8 +1439,8 @@
         }
         else
         {
-          message = ue->Message();
-          messageRaw = codec->fromUnicode(message);
+          messageRaw = wholeMessageRaw;
+          message = codec->toUnicode(wholeMessageRaw);
         }
 
         icqEventTag = server->icqSendMessage(m_nUin, messageRaw.data(),
