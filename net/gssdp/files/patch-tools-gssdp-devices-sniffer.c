--- tools/gssdp-device-sniffer.c.orig	2009-07-29 15:53:32.000000000 +0200
+++ tools/gssdp-device-sniffer.c	2009-12-26 13:56:48.000000000 +0100
@@ -319,7 +319,7 @@
 
         uuid = usn_tokens[0] + 5; /* skip the prefix 'uuid:' */
 
-        if (usn_tokens[1]) {
+        if (usn_tokens[1] && strlen(usn_tokens[1]) != 0) {
                 char **urn_tokens;
 
                 urn_tokens = g_strsplit (usn_tokens[1], ":device:", -1);
