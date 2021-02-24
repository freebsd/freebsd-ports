--- widentd.c.orig	2015-02-24 19:27:09 UTC
+++ widentd.c
@@ -191,7 +191,7 @@ main(int argc, char **argv)
 
 		to.tv_sec = TIMEOUT;
 		to.tv_usec = 0;
-		memset(buff, sizeof(buff), 0);
+		memset(buff, (0), sizeof(buff));
 		do {
 			int             n;
 
