--- apps/nmreplay/nmreplay.c.orig	2021-11-25 23:16:06 UTC
+++ apps/nmreplay/nmreplay.c
@@ -1280,7 +1280,7 @@ main(int argc, char **argv)
 	D("exiting on abort");
 	sleep(1);
 
-	return (0);
+	return (err);
 }
 
 /* conversion factor for numbers.
