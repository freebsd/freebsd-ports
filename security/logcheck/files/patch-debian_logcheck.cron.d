--- debian/logcheck.cron.d.orig	2017-01-25 21:08:04 UTC
+++ debian/logcheck.cron.d
@@ -1,9 +1,5 @@
-# /etc/cron.d/logcheck: crontab entries for the logcheck package
-
-PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin
+# crontab entries for the logcheck package
+PATH=/sbin:/bin:/usr/sbin:/usr/bin:%%PREFIX%%/sbin:%%PREFIX%%/bin
 MAILTO=root
-
-@reboot         logcheck    if [ -x /usr/sbin/logcheck ]; then nice -n10 /usr/sbin/logcheck -R; fi
-2 * * * *       logcheck    if [ -x /usr/sbin/logcheck ]; then nice -n10 /usr/sbin/logcheck; fi
-
-# EOF
+@reboot    if [ -x %%PREFIX%%/sbin/logcheck ]; then nice -n10 %%PREFIX%%/sbin/logcheck -R; fi
+2 * * * *  if [ -x %%PREFIX%%/sbin/logcheck ]; then nice -n10 %%PREFIX%%/sbin/logcheck; fi
