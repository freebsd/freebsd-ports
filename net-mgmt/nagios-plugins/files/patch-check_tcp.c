--- plugins/check_tcp.c.orig	Thu Dec 30 03:41:40 2004
+++ plugins/check_tcp.c	Thu May 12 14:02:13 2005
@@ -196,7 +196,6 @@
 		EXPECT = strdup("<?xml version=\'1.0\'?><stream:stream xmlns:stream=\'http://etherx.jabber.org/streams\'");
 		QUIT = strdup("</stream:stream>\n");
 		PROTOCOL=TCP_PROTOCOL;
-		use_ssl=TRUE;
 		PORT = 5222;
 	}
        else if (strstr (argv[0], "check_nntps")) {
