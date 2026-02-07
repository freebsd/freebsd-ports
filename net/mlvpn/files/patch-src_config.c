--- src/config.c.orig	2015-12-28 11:20:16 UTC
+++ src/config.c
@@ -269,6 +269,7 @@ mlvpn_config(int config_file_fd, int fir
             } else if (strncmp(lastSection, "filters", 7) != 0) {
                 char *bindaddr;
                 char *bindport;
+				uint32_t bindfib = 0;
                 char *dstaddr;
                 char *dstport;
                 uint32_t bwlimit = 0;
@@ -284,6 +285,9 @@ mlvpn_config(int config_file_fd, int fir
                     _conf_set_str_from_conf(
                         config, lastSection, "bindport", &bindport, NULL,
                         "bind port is mandatory in server mode.\n", 1);
+					_conf_set_uint_from_conf(
+						config, lastSection, "bindfib", &bindfib, 0,
+						NULL, 0);
                     _conf_set_str_from_conf(
                         config, lastSection, "remotehost", &dstaddr, NULL,
                         NULL, 0);
@@ -297,6 +301,9 @@ mlvpn_config(int config_file_fd, int fir
                     _conf_set_str_from_conf(
                         config, lastSection, "bindport", &bindport, NULL,
                         NULL, 0);
+					 _conf_set_uint_from_conf(
+						config, lastSection, "bindfib", &bindfib, 0,
+						NULL, 0);
                     _conf_set_str_from_conf(
                         config, lastSection, "remotehost", &dstaddr, NULL,
                         "No remote address specified.\n", 1);
@@ -336,6 +343,7 @@ mlvpn_config(int config_file_fd, int fir
                               tmptun->name);
                         if ((! mystr_eq(tmptun->bindaddr, bindaddr)) ||
                                 (! mystr_eq(tmptun->bindport, bindport)) ||
+								(tmptun->bindfib != bindfib) ||
                                 (! mystr_eq(tmptun->destaddr, dstaddr)) ||
                                 (! mystr_eq(tmptun->destport, dstport))) {
                             mlvpn_rtun_status_down(tmptun);
@@ -347,6 +355,9 @@ mlvpn_config(int config_file_fd, int fir
                         if (bindport) {
                             strlcpy(tmptun->bindport, bindport, sizeof(tmptun->bindport));
                         }
+						if (tmptun->bindfib != bindfib) {
+							tmptun->bindfib = bindfib;
+						}
                         if (dstaddr) {
                             strlcpy(tmptun->destaddr, dstaddr, sizeof(tmptun->destaddr));
                         }
@@ -380,7 +391,7 @@ mlvpn_config(int config_file_fd, int fir
                 {
                     log_info("config", "%s tunnel added", lastSection);
                     mlvpn_rtun_new(
-                        lastSection, bindaddr, bindport, dstaddr, dstport,
+                        lastSection, bindaddr, bindport, bindfib, dstaddr, dstport,
                         default_server_mode, timeout, fallback_only,
                         bwlimit, loss_tolerence);
                 }
