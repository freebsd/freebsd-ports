--- main.c.orig	Mon Oct 13 16:17:08 2003
+++ main.c	Mon Oct 13 16:17:41 2003
@@ -244,17 +244,17 @@ static void copy_input(obuf* out)
 }
 
 static const char* usage_str =
-"usage: %s [-cqDNT] [-n NUM] [-s STR] [-t TIME] %s
-  -c       Copy message into response
-  -n NUM   Set the maximum number of replies (defaults to 1)
-  -s STR   Add the subject to the autoresponse, prefixed by STR
-  -t TIME  Set the time interval, in seconds (defaults to 1 hour)
-  -q       Don't show error messages
-  -D       Don't remove old response records
-  -N       Don't send, just send autoresponse to standard output
-  If more than NUM messages are received from the same sender
-  within TIME seconds of each other, no response is sent.
-  This program must be run by qmail.
+"usage: %s [-cqDNT] [-n NUM] [-s STR] [-t TIME] %s\n\
+  -c       Copy message into response\n\
+  -n NUM   Set the maximum number of replies (defaults to 1)\n\
+  -s STR   Add the subject to the autoresponse, prefixed by STR\n\
+  -t TIME  Set the time interval, in seconds (defaults to 1 hour)\n\
+  -q       Don't show error messages\n\
+  -D       Don't remove old response records\n\
+  -N       Don't send, just send autoresponse to standard output\n\
+  If more than NUM messages are received from the same sender\n\
+  within TIME seconds of each other, no response is sent.\n\
+  This program must be run by qmail.\n\
 %s";
 
 void usage(const char* msg)
