--- client/clparse.c.orig	Wed Jul 19 21:13:10 2000
+++ client/clparse.c	Thu Jul 20 21:52:53 2000
@@ -46 +46 @@
-char client_script_name [] = "/etc/dhclient-script";
+char client_script_name [] = CL_DEFAULT_SCRIPT_NAME;
