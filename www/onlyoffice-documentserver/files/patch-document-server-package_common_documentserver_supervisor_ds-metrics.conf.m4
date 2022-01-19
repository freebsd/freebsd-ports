--- document-server-package/common/documentserver/supervisor/ds-metrics.conf.m4.orig	2022-01-19 20:01:21 UTC
+++ document-server-package/common/documentserver/supervisor/ds-metrics.conf.m4
@@ -1,7 +1,7 @@
 [program:metrics]
 command=/var/www/M4_DS_PREFIX/server/Metrics/metrics ./config/config.js
 directory=/var/www/M4_DS_PREFIX/server/Metrics
-user=ds
+user=onlyoffice
 environment=NODE_DISABLE_COLORS=1
 stdout_logfile=/var/log/M4_DS_PREFIX/metrics/out.log
 stdout_logfile_backups=0
