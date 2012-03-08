--- ./src/mailboxField.cpp.orig	2009-09-06 05:10:27.000000000 -0700
+++ ./src/mailboxField.cpp	2012-03-08 10:49:05.687243933 -0800
@@ -51,7 +51,7 @@
 	// Here, we cannot simply call "m_mailbox.parse()" because it
 	// may have more than one address specified (even if this field
 	// should contain only one). We are never too much careful...
-	ref <address> parsedAddress = address::parseNext(buffer, position, end, newPosition);
+	ref <address> parsedAddress = mailbox::parseNext(buffer, position, end, newPosition);
 
 	if (parsedAddress)
 	{
