--- log.c	2007-01-02 17:11:26.000000000 -0200
+++ new/log.c	2007-01-29 17:19:17.000000000 -0200
@@ -1216,7 +1216,7 @@
 
               if(download_flag && strstr(code,"DENIED") == 0) {
                  ndownload = 1;
-                 sprintf(bufz, "%s %s %s %s %s %s\n",dia,hora,user,ip,download_url);
+                 sprintf(bufz, "%s %s %s %s %s\n",dia,hora,user,ip,download_url);
 
 #ifdef LEGACY_WRITE_DOWNLOAD
                  sprintf(tmp3,"%s/sarg/download.unsort",tmp);
