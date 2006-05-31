--- src/psiaccount.cpp.orig	Tue May 30 22:17:08 2006
+++ src/psiaccount.cpp	Tue May 30 19:40:01 2006
@@ -3049,13 +3049,13 @@
 
 		values["Sender.jid.full"] = jidSender.full();
 		values["Sender.jid.bare"] = jidSender.bare();
-		values["Sender.nick"]     = (uSender)? uSender->name() : "";
-		values["Sender.nick-jid"] = jidnick(jidSender.bare(), (uSender)? uSender->name() : "");
+		values["Sender.nick"]     = (uSender)? uSender->name() : (QString)"";
+		values["Sender.nick-jid"] = jidnick(jidSender.bare(), (uSender)? uSender->name() : (QString)"");
 
 		values["Me.jid.full"] = jidMe.resource().isEmpty()? jidMe.full() + "/" + d->client->resource() : jidMe.full();
 		values["Me.jid.bare"] = jidMe.bare();
-		values["Me.nick"]     = (uMe)? uMe->name() : "";;
-		values["Me.nick-jid"] = jidnick(jidMe.bare(), (uMe)? uMe->name() : "");
+		values["Me.nick"]     = (uMe)? uMe->name() : (QString)"";;
+		values["Me.nick-jid"] = jidnick(jidMe.bare(), (uMe)? uMe->name() : (QString)"");
 
 		header = headerTemplate.expand(values);
 	}
@@ -3081,7 +3081,7 @@
 
 		Template::ExpandData values;
 		
-		values["fortune"] = (option.fortunes.count())? option.fortunes[rand()%option.fortunes.count()] : "";
+		values["fortune"] = (option.fortunes.count())? option.fortunes[rand()%option.fortunes.count()] : (QString)"";
 
 		signature = signatureTemplate.expand(values);
 
@@ -3146,7 +3146,7 @@
 		sepBody = "\n";
 
 	// signature
-	QString signature = (option.useMessageSignature)? expandSignatureTemplate(option.messageSignature, option.autoMessageSignatureDelimiter,FALSE) : "";
+	QString signature = (option.useMessageSignature)? expandSignatureTemplate(option.messageSignature, option.autoMessageSignatureDelimiter,FALSE) : (QString)"";
 
 	// body/signature separator
 	//		we want to have one empty line between body and signature (at least two '\n');
