--- plugins/check_tcp.c.orig	Thu Mar 30 02:03:36 2006
+++ plugins/check_tcp.c	Fri May 12 23:27:44 2006
@@ -155,7 +155,7 @@
 		SEND = "<stream:stream to=\'host\' xmlns=\'jabber:client\' xmlns:stream=\'http://etherx.jabber.org/streams\'>\n";
 		EXPECT = "<?xml version=\'1.0\'?><stream:stream xmlns:stream=\'http://etherx.jabber.org/streams\'";
 		QUIT = "</stream:stream>\n";
-		flags |= FLAG_SSL | FLAG_HIDE_OUTPUT;
+		flags |= FLAG_HIDE_OUTPUT;
 		PORT = 5222;
 	}
 	else if (!strncmp (SERVICE, "NNTPS", 5)) {
