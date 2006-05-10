--- talk/xmpp/saslplainmechanism.h.orig	Wed May 10 07:43:35 2006
+++ talk/xmpp/saslplainmechanism.h	Wed May 10 07:44:01 2006
@@ -48,7 +48,7 @@
 
     FormatXmppPassword credential;
     credential.Append("\0", 1);
-    credential.Append(user_jid_.Str());
+    credential.Append(user_jid_.node());
     credential.Append("\0", 1);
     credential.Append(&password_);
     el->AddText(Base64EncodeFromArray(credential.GetData(), credential.GetLength()));
