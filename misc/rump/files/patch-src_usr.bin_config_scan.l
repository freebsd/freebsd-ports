--- src/usr.bin/config/scan.l.orig	2020-08-29 04:30:42 UTC
+++ src/usr.bin/config/scan.l
@@ -108,6 +108,7 @@ static int endinclude(void);
 static int getincludepath(void);
 static int getcurifdef(void);
 
+SLIST_HEAD(, prefix)	curdirs;	/* curdir stack */
 
 %}
 
