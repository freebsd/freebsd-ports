--- crypt.c.orig	Tue Jan 11 16:20:48 2005
+++ crypt.c	Tue Jan 11 16:21:10 2005
@@ -596,6 +596,8 @@
     }
     else if (a->encoding == ENC8BIT)
       a->encoding = ENCQUOTEDPRINTABLE;
+    else if (a->encoding == ENC7BIT)
+      /* empty */ ;
     else if (a->encoding == ENCBINARY)
       a->encoding = ENCBASE64;
     else if (a->content && a->encoding != ENCBASE64 &&
