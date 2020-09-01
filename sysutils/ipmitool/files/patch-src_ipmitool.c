--- src/ipmitool.c.orig	2016-08-21 06:59:27 UTC
+++ src/ipmitool.c
@@ -79,6 +79,7 @@ extern int ipmi_set_main(struct ipmi_intf * intf, int 
 extern int ipmi_exec_main(struct ipmi_intf * intf, int argc, char ** argv);
 extern int ipmi_lan6_main(struct ipmi_intf *intf, int argc, char **argv);
 
+VERSIONINFO gVersionInfo[HPMFWUPG_COMPONENT_ID_MAX];
 
 int csv_output = 0;
 int verbose = 0;
