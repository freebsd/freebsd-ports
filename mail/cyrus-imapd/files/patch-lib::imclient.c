Index: lib/imclient.c
diff -u lib/imclient.c.orig lib/imclient.c
--- lib/imclient.c.orig	Sat Jul 28 08:30:37 2001
+++ lib/imclient.c	Sat Aug 17 16:48:58 2002
@@ -1154,6 +1154,7 @@
       t->result = xstrdup(user);
   } else {
       printf("%s: ", t->prompt);
+      fflush(stdout);
       if (t->id == SASL_CB_PASS) {
 	  char *ptr = getpass("");
 	  strncpy(result, ptr, sizeof(result));
