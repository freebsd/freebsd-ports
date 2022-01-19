--- document-server-package/common/documentserver/supervisor/ds-docservice.conf.m4.orig	2022-01-19 20:01:10 UTC
+++ document-server-package/common/documentserver/supervisor/ds-docservice.conf.m4
@@ -1,7 +1,7 @@
 [program:docservice]
 command=/var/www/M4_DS_PREFIX/server/DocService/docservice
 directory=/var/www/M4_DS_PREFIX/server/DocService
-user=ds
+user=onlyoffice
 environment=NODE_ENV=production-linux,NODE_CONFIG_DIR=/etc/M4_DS_PREFIX,NODE_DISABLE_COLORS=1
 stdout_logfile=/var/log/M4_DS_PREFIX/docservice/out.log
 stdout_logfile_backups=0
