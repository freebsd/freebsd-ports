--- normalizemime.cc.orig	Tue Aug 30 21:31:02 2005
+++ normalizemime.cc	Tue Aug 30 21:33:08 2005
@@ -498,7 +498,7 @@
   char *obuf = buf;
   memcpy (icopy, message.c_str(), in_left);
   message.erase ();
-  char *ibuf = icopy;
+  const char *ibuf = icopy;
 
   while (in_left > 0) {
     if ((size_t)(-1) == iconv (ic, &ibuf, &in_left, &obuf, &out_left)) {
