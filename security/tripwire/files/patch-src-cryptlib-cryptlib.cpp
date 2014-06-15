--- src/cryptlib/cryptlib.cpp.orig	2011-11-21 17:06:56.000000000 +0100
+++ src/cryptlib/cryptlib.cpp	2014-06-15 01:42:35.000000000 +0200
@@ -43,8 +43,8 @@ void StreamCipher::ProcessString(byte *o
 
 void StreamCipher::ProcessString(byte *inoutString, unsigned int length)
 {
-	while(length--)
-		*inoutString++ = ProcessByte(*inoutString);
+	for(;length--; inoutString++)
+		*inoutString = ProcessByte(*inoutString);
 }
 
 bool MessageAuthenticationCode::Verify(const byte *macIn)
