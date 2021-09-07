--- src/regex.c.orig	1999-05-10 04:27:07 UTC
+++ src/regex.c
@@ -5789,7 +5789,7 @@ regerror (errcode, preg, errbuf, errbuf_size)
       if (msg_size > errbuf_size)
         {
 #if defined HAVE_MEMPCPY || defined _LIBC
-	  *((char *) __mempcpy (errbuf, msg, errbuf_size - 1)) = '\0';
+	  *((char *) mempcpy (errbuf, msg, errbuf_size - 1)) = '\0';
 #else
           memcpy (errbuf, msg, errbuf_size - 1);
           errbuf[errbuf_size - 1] = 0;
