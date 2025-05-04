--- debian/logcheck.cron.d.orig	2025-04-28 15:28:43 UTC
+++ debian/logcheck.cron.d
@@ -1,8 +1,8 @@
 # /etc/cron.d/logcheck: crontab entries for the logcheck package
 # These do nothing under systemd because the systemd timer will take precedence
 
-PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin
+PATH=%%PREFIX%%/sbin:%%PREFIX%%/bin:/sbin:/bin:/usr/sbin:/usr/bin
 MAILTO=root
 
-@reboot         logcheck    if [ ! -d /run/systemd/system ] && [ -x /usr/sbin/logcheck ]; then nice -n10 /usr/sbin/logcheck -R; fi
-2 * * * *       logcheck    if [ ! -d /run/systemd/system ] && [ -x /usr/sbin/logcheck ]; then nice -n10 /usr/sbin/logcheck; fi
+@reboot         if [ ! -d /run/systemd/system ] && [ -x %%PREFIX%%/sbin/logcheck ]; then /usr/bin/lockf -t 0 /tmp/.logcheck nice -n10 %%PREFIX%%/sbin/logcheck -R; fi
+2 * * * *       if [ ! -d /run/systemd/system ] && [ -x %%PREFIX%%/sbin/logcheck ]; then /usr/bin/lockf -t 0 /tmp/.logcheck nice -n10 %%PREFIX%%/sbin/logcheck; fi
