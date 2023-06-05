--- parse.c.orig	2002-06-10 12:19:44 UTC
+++ parse.c
@@ -48,8 +48,9 @@ int preferedcontent(char *type)
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
@@ -325,7 +326,7 @@ struct body * process(char *mbox,    /* file name */
   if (use_stdin || !mbox || !strcasecmp(mbox, "NONE"))
     fp = stdin;
   else if ((fp = fopen(mbox, "r")) == NULL) {
-    return; /* add error code */
+    return -1; /* add error code */
   }
   
   isinheader = 1;
