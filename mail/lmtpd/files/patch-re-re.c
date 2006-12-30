--- re/re.c.orig	2004-10-26 17:59:51.000000000 +0200
+++ re/re.c	2006-12-24 11:29:14.000000000 +0100
@@ -44,8 +44,8 @@
 extern RE re_rfc822;
 extern RE re_true;
 extern RE re_false;
-extern RE re_error;
-extern RE re_error_memory;
+static RE re_error;
+static RE re_error_memory;
 #if WITH_TRE
 extern RE re_tre_extended;
 char *re_tre_init(void);
