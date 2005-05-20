--- asmtpd/smtpd.C.orig	Fri May 20 08:10:46 2005
+++ asmtpd/smtpd.C	Fri May 20 08:11:15 2005
@@ -88,14 +88,14 @@
     p++;
 
   for (;;) {
-    const char *q = p + min (e - p, 75);
+    const char *q = p + min ((long) (e - p), (long) 75);
     if (q != e)
       while (q > p && !isspace (q[-1]))
 	q--;
     while (q > p && isspace (q[-1]))
       q--;
     if (q == p) {
-      q = p + min (e - p, 75);
+      q = p + min ((long) (e - p), (long) 75);
       while (q < e && !isspace (*q))
 	q++;
     }
