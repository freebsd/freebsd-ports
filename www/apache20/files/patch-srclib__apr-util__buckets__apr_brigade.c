--- ./srclib/apr-util/buckets/apr_brigade.c.orig	2005-02-04 15:39:09.000000000 -0500
+++ ./srclib/apr-util/buckets/apr_brigade.c	2010-05-06 16:06:03.715831795 -0400
@@ -653,9 +653,6 @@
       return -1;
     }
 
-    /* tack on null terminator to remaining string */
-    *(vd.vbuff.curpos) = '\0';
-
     /* write out what remains in the buffer */
     return apr_brigade_write(b, flush, ctx, buf, vd.vbuff.curpos - buf);
 }
