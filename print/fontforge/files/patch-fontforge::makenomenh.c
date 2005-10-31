--- fontforge/makenomenh.c.orig	Wed Oct 19 09:50:52 2005
+++ fontforge/makenomenh.c	Wed Oct 19 09:51:36 2005
@@ -299,7 +299,7 @@
     fprintf( po, "\"Project-Id-Version: PACKAGE VERSION\\n\"\n" );
     time(&now);
     tmnow = localtime(&now);
-#if !defined(__Mac) && !defined(__CygWin)
+#if !defined(__Mac) && !defined(__CygWin) && !defined(__FreeBSD__)
     fprintf( po, "\"POT-Creation-Date: %d-%02d-%02d %02d:%02d+%02ld%02ld\\n\"\n",
 	    tmnow->tm_year+1900, tmnow->tm_mon, tmnow->tm_mday,
 	    tmnow->tm_hour, tmnow->tm_min,
