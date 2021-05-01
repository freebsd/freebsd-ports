--- import/extract_mp3.c.orig	2011-11-19 16:50:27 UTC
+++ import/extract_mp3.c
@@ -243,7 +243,7 @@ static int mp3scan(int infd, int outfd)
 }
 
 #define MAX_BUF 4096
-char audio[MAX_BUF];
+static char audio[MAX_BUF];
 
 /* ------------------------------------------------------------
  *
