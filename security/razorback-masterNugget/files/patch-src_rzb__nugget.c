--- src/rzb_nugget.c.orig	2020-08-27 12:50:01 UTC
+++ src/rzb_nugget.c
@@ -330,8 +330,8 @@ static bool loadNuggets()
         if (sg_sSoVersion[l_iIt] == ':')
             sg_sSoVersion[l_iIt] = '.';
 
-	rzb_log(LOG_DEBUG, "LoadNuggets: SO Version: %s", sg_sSoVersion);
-	ftw(sg_sSoPath, processFile, 1);
+    rzb_log(LOG_DEBUG, "LoadNuggets: SO Version: %s", sg_sSoVersion);
+    ftw(sg_sSoPath, processFile, 1);
 #endif
     return true;
 }
