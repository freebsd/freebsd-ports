--- src/tpm_mgmt/tpm_takeownership.c.orig	2013-07-24 22:02:59.000000000 +0900
+++ src/tpm_mgmt/tpm_takeownership.c	2013-07-24 22:03:53.000000000 +0900
@@ -77,6 +77,7 @@
 	{"srk-well-known", no_argument, NULL, 'z'},
 	};
 
+	memset(&hSrk, 0, sizeof(hSrk));
 	initIntlSys();
 
 	if (genericOptHandler
