--- src/putarticle.c.orig	Wed Jan 22 08:30:59 2003
+++ src/putarticle.c	Sat May 17 21:43:03 2003
@@ -128,6 +128,11 @@
 #define MAILFOLDER_TAG "From "
 #define MAILFOLDER_TAG_LEN 5
 
+/*
+ *  fix for inn-2.4.0 (it has been removed from inn/config.h)
+ */
+typedef int	BOOL;
+
 /* for log etc. */
 static char msgid[NNTP_STRLEN];
 static char msgsender[NNTP_STRLEN];
