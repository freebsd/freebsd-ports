--- normalizemime.cc.orig	Tue Sep 13 00:03:52 2005
+++ normalizemime.cc	Tue Sep 13 00:04:18 2005
@@ -58,6 +58,8 @@
 #include <map>
 #include <string>
 
+#include <sys/types.h>
+
 #include <regex.h>
 #include <assert.h>
 #include <ctype.h>
@@ -498,7 +500,7 @@
   char *obuf = buf;
   memcpy (icopy, message.c_str(), in_left);
   message.erase ();
-  char *ibuf = icopy;
+  const char *ibuf = icopy;
 
   while (in_left > 0) {
     if ((size_t)(-1) == iconv (ic, &ibuf, &in_left, &obuf, &out_left)) {
@@ -1491,6 +1493,7 @@
       "X-Spam-",           // Added by SpamAssasin for example
       "X-CRM114-",         // Added by CRM114
       "X-Virus-",          // Added by ClamAV
+      "X-DSPAM-",          // Added by DSPAM
       "X-UID:",            // added by Pine mail user agent
       "Status:",           // added by Pine mail user agent
       "X-Status:",         // added by Pine mail user agent
