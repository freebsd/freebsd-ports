--- spectool_net_client.h.orig	2014-01-12 19:57:48.000000000 +0100
+++ spectool_net_client.h	2014-01-12 19:55:31.000000000 +0100
@@ -134,6 +134,7 @@ void spectool_netcli_setbufferwrite(spec
 int spectool_netcli_getwritepend(spectool_server *sr);
 int spectool_netcli_getwritefd(spectool_server *sr);
 int spectool_netcli_poll(spectool_server *sr, char *errstr);
+int spectool_netcli_writepoll(spectool_server *sr, char *errstr);
 spectool_phy *spectool_netcli_enabledev(spectool_server *sr, unsigned int dev_id,
 									 char *errstr);
 int spectool_netcli_disabledev(spectool_server *sr, spectool_phy *dev);
