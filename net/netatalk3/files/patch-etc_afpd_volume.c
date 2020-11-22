--- etc/afpd/volume.c.orig	2020-11-17 04:41:20 UTC
+++ etc/afpd/volume.c
@@ -183,6 +183,7 @@ static int get_tm_used(struct vol * restrict vol)
             
             if ((bandsize = get_tm_bandsize(cfrombstr(infoplist))) == -1) {
                 bdestroy(infoplist);
+                infoplist = NULL;
                 continue;
             }
 
@@ -190,7 +191,9 @@ static int get_tm_used(struct vol * restrict vol)
 
             if ((links = get_tm_bands(cfrombstr(bandsdir))) == -1) {
                 bdestroy(infoplist);
+                infoplist = NULL;
                 bdestroy(bandsdir);
+                bandsdir = NULL;
                 continue;
             }
 
