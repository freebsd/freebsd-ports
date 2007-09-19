--- src/gui/ipfAdvancedDialog.cpp.orig	2007-01-06 14:03:25.000000000 -0800
+++ src/gui/ipfAdvancedDialog.cpp	2007-09-19 11:29:47.000000000 -0700
@@ -88,6 +88,8 @@
     data.registerOption( ipf_nat_irc_proxy        ,fwopt, "ipf_nat_irc_proxy");
     data.registerOption( ipf_nat_ftp_proxy        ,fwopt, "ipf_nat_ftp_proxy");
     data.registerOption( ipf_nat_rcmd_proxy       ,fwopt, "ipf_nat_rcmd_proxy");
+    data.registerOption( ipf_nat_krcmd_proxy      ,fwopt, "ipf_nat_krcmd_proxy");
+    data.registerOption( ipf_nat_ekshell_proxy    ,fwopt, "ipf_nat_ekshell_proxy");
     data.registerOption( ipf_fw_dir               ,fwopt, "firewall_dir"      );
     data.registerOption( ipf_user                 ,fwopt, "admUser"           );
     data.registerOption( altAddress               ,fwopt, "altAddress"        );
