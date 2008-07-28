--- normalizemime.cc.orig	2008-07-28 10:36:10.000000000 -0300
+++ normalizemime.cc	2008-07-28 10:37:16.000000000 -0300
@@ -58,6 +58,8 @@
 #include <map>
 #include <string>
 
+#include <sys/types.h>
+
 #include <string.h>
 #include <stdlib.h>
 #include <regex.h>
@@ -500,7 +502,7 @@
   char *obuf = buf;
   memcpy (icopy, message.c_str(), in_left);
   message.erase ();
-  char *ibuf = icopy;
+  const char *ibuf = icopy;
 
   while (in_left > 0) {
     if ((size_t)(-1) == iconv (ic, &ibuf, &in_left, &obuf, &out_left)) {
@@ -1493,6 +1495,7 @@
       "X-Spam-",           // Added by SpamAssasin for example
       "X-CRM114-",         // Added by CRM114
       "X-Virus-",          // Added by ClamAV
+      "X-DSPAM-",          // Added by DSPAM
       "X-UID:",            // added by Pine mail user agent
       "Status:",           // added by Pine mail user agent
       "X-Status:",         // added by Pine mail user agent
