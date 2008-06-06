--- src/timsieve.c.orig	Mon Feb  4 17:37:40 2008
+++ src/timsieve.c	Tue Feb  5 19:19:12 2008
@@ -40,7 +40,7 @@
 	  if (strlen(banner) > 0) \
             ci_write(stream, "\"IMPLEMENTATION\" \"%s\"\r\n", banner); \
 	  else \
-            ci_write(stream, "\"IMPLEMENTATION\" \"DBMail timsieved v%s\"\r\n", VERSION); \
+            ci_write(stream, "\"IMPLEMENTATION\" \"DBMail timsieved v%s\"\r\n", DBMAIL_VERSION); \
           ci_write(stream, "\"SASL\" \"PLAIN\"\r\n"); \
           ci_write(stream, "\"SIEVE\" \"%s\"\r\n", sieve_extensions); \
           ci_write(stream, "OK\r\n")
