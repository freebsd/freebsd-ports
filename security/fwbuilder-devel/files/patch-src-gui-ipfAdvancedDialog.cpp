--- src/gui/ipfAdvancedDialog.cpp.orig	2008-09-01 00:45:50.000000000 -0700
+++ src/gui/ipfAdvancedDialog.cpp	2008-09-02 11:23:23.533839864 -0700
@@ -97,6 +97,8 @@
     data.registerOption( m_dialog->ipf_nat_irc_proxy        ,fwopt, "ipf_nat_irc_proxy");
     data.registerOption( m_dialog->ipf_nat_ftp_proxy        ,fwopt, "ipf_nat_ftp_proxy");
     data.registerOption( m_dialog->ipf_nat_rcmd_proxy       ,fwopt, "ipf_nat_rcmd_proxy");
+    data.registerOption( m_dialog->ipf_nat_krcmd_proxy       ,fwopt, "ipf_nat_krcmd_proxy");
+    data.registerOption( m_dialog->ipf_nat_ekshell_proxy       ,fwopt, "ipf_nat_ekshell_proxy");
     data.registerOption( m_dialog->ipf_fw_dir               ,fwopt, "firewall_dir"      );
     data.registerOption( m_dialog->ipf_user                 ,fwopt, "admUser"           );
     data.registerOption( m_dialog->altAddress               ,fwopt, "altAddress"        );
