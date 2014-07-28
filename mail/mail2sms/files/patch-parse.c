--- parse.c.orig	Wed Apr 16 05:06:23 2003
+++ parse.c	Wed Apr 16 05:45:31 2003
@@ -48,8 +48,9 @@
 /*
 ** strcasestr() - case insensitive strstr()
 */
- 
-char *strcasestr(char *haystack, char *needle)
+
+/* FreeBSD defines this function a bit differently, so rename this version */
+char *mail2sms_strcasestr(char *haystack, char *needle)
 {
   int nlen = strlen(needle);
   int hlen = strlen(haystack);
@@ -325,7 +326,7 @@ struct body * process(char *mbox,    /*
   if (use_stdin || !mbox || !strcasecmp(mbox, "NONE"))
     fp = stdin;
   else if ((fp = fopen(mbox, "r")) == NULL) {
-    return; /* add error code */
+    return -1; /* add error code */
   }

   isinheader = 1;
