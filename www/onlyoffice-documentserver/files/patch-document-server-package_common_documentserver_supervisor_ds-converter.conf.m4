--- document-server-package/common/documentserver/supervisor/ds-converter.conf.m4.orig	2022-01-19 20:00:55 UTC
+++ document-server-package/common/documentserver/supervisor/ds-converter.conf.m4
@@ -1,7 +1,7 @@
 [program:converter]
 command=/var/www/M4_DS_PREFIX/server/FileConverter/converter
 directory=/var/www/M4_DS_PREFIX/server/FileConverter
-user=ds
+user=onlyoffice
 environment=NODE_ENV=production-linux,NODE_CONFIG_DIR=/etc/M4_DS_PREFIX,NODE_DISABLE_COLORS=1,APPLICATION_NAME=M4_COMPANY_NAME
 stdout_logfile=/var/log/M4_DS_PREFIX/converter/out.log
 stdout_logfile_backups=0
