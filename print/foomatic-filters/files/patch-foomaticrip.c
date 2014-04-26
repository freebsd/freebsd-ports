--- foomaticrip.c.orig	2014-04-26 11:32:42.578342305 +0400
+++ foomaticrip.c	2014-04-26 11:44:16.016294870 +0400
@@ -1197,7 +1197,8 @@ int main(int argc, char** argv)
         debug = 1;
 
     if (debug) {
-	int fd = mkstemp (LOG_FILE "-XXXXXX.log");
+	sprintf(tmp, "%s-XXXXXX.log", LOG_FILE);
+	int fd = mkstemps (tmp, 4);
 	if (fd != -1)
 	    logh = fdopen(fd, "w");
 	else
