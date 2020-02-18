--- Local/sa-exim.c.orig	2020-02-18 20:02:59.741459000 +0100
+++ Local/sa-exim.c	2020-02-18 20:03:42.394082000 +0100
@@ -1218,7 +1218,7 @@
 	    }
 
 	    stret=write(fd, buffer, strlen(buffer));
-	    CHECKERR(stret,string_sprintf("SA body write to msg"),__LINE__);
+	    CHECKERR(stret,"SA body write to msg",__LINE__);
 	    if (SAEximDebug > 8)
 	    {
 		log_write(0, LOG_MAIN, "SA: Debug9: Wrote to msg; line %d (wrote %d)", line, ret);
