--- plugins/check_tcp.c.orig	Sun Jun  5 21:43:58 2005
+++ plugins/check_tcp.c	Thu Sep  1 12:16:31 2005
@@ -179,7 +179,7 @@
 		SEND = "<stream:stream to=\'host\' xmlns=\'jabber:client\' xmlns:stream=\'http://etherx.jabber.org/streams\'>\n";
 		EXPECT = "<?xml version=\'1.0\'?><stream:stream xmlns:stream=\'http://etherx.jabber.org/streams\'";
 		QUIT = "</stream:stream>\n";
-		flags |= FLAG_SSL | FLAG_HIDE_OUTPUT;
+		flags |= FLAG_HIDE_OUTPUT;
 		PORT = 5222;
 	}
 	else if (!strncmp (SERVICE, "NNTPS", 5)) {
