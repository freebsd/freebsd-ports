--- pgp.c.orig	Wed Jan  9 16:39:28 2002
+++ pgp.c	Wed Jan 12 09:46:08 2005
@@ -1193,6 +1193,8 @@
     }
     else if (a->encoding == ENC8BIT)
       a->encoding = ENCQUOTEDPRINTABLE;
+    else if (a->encoding == ENC7BIT)
+      /* empty */ ;
     else if (a->encoding == ENCBINARY)
       a->encoding = ENCBASE64;
     else if (a->content && a->encoding != ENCBASE64 &&
