--- src/tn5250.c.orig	Tue Jul 22 18:25:06 2003
+++ src/tn5250.c	Tue Jul 22 18:25:31 2003
@@ -179,7 +179,7 @@
   tn5250 [options] HOST[:PORT]\n");
 #ifdef HAVE_LIBSSL
    printf("\
-   To connect using ssl prefix HOST with 'ssl:'.  Example:
+   To connect using ssl prefix HOST with 'ssl:'.  Example:\n\
       tn5250 +ssl_verify_server ssl:as400.example.com\n");
 #endif
    printf ("\n\
