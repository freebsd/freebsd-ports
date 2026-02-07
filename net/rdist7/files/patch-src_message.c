--- src/message.c.orig	2001-10-22 13:29:22.000000000 -0700
+++ src/message.c	2024-03-19 17:13:40.618837000 -0700
@@ -490,9 +490,8 @@
 		return;
 
 	if (!msgfac->mf_fptr) {
-		register char *cp;
+		const char *cp;
 		size_t len;
-		char *getenv();
 		int fd;
 
 		/*
@@ -546,7 +545,7 @@
  */
 static void _message(flags, msgbuf)
 	int flags;
-	char *msgbuf;
+	const char *msgbuf;
 {
 	register int i, x;
 	register char *cp;
