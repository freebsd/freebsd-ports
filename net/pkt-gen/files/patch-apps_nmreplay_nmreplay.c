--- apps/nmreplay/nmreplay.c.orig	2022-02-11 07:45:02 UTC
+++ apps/nmreplay/nmreplay.c
@@ -1273,7 +1273,7 @@ main(int argc, char **argv)
 	D("exiting on abort");
 	sleep(1);
 
-	return (0);
+	return (err);
 }
 
 /* conversion factor for numbers.
