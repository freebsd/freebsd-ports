--- src/timsieve.c.orig	Tue Jan  6 14:51:55 2009
+++ src/timsieve.c	Sun Jan 25 18:38:52 2009
@@ -69,7 +69,7 @@
 	if (strlen(banner) > 0)
 		ci_write(session->ci, "\"IMPLEMENTATION\" \"%s\"\r\n", banner);
 	else
-		ci_write(session->ci, "\"IMPLEMENTATION\" \"DBMail timsieved %s\"\r\n", VERSION);
+		ci_write(session->ci, "\"IMPLEMENTATION\" \"DBMail timsieved %s\"\r\n", DBMAIL_VERSION);
 	ci_write(session->ci, "\"SASL\" \"PLAIN\"\r\n");
 	ci_write(session->ci, "\"SIEVE\" \"%s\"\r\n", sieve_extensions);
 	ci_write(session->ci, "OK\r\n");
