--- libpromises/sysinfo.c.orig	2013-12-09 12:13:14.000000000 +0000
+++ libpromises/sysinfo.c	2014-03-25 14:30:28.000000000 +0000
@@ -1075,6 +1075,10 @@
         {
             snprintf(vbuff, CF_BUFSIZE, "/var/spool/cron/%s", pw->pw_name);
         }
+        else if (IsDefinedClass(ctx, "freebsd", NULL))
+        {
+            snprintf(vbuff, CF_BUFSIZE, "/var/cron/tabs/%s", pw->pw_name);
+        }
         else
         {
             snprintf(vbuff, CF_BUFSIZE, "/var/spool/cron/crontabs/%s", pw->pw_name);
