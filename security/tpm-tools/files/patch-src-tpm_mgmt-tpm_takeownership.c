--- src/tpm_mgmt/tpm_takeownership.c.orig	2010-09-30 17:28:09 UTC
+++ src/tpm_mgmt/tpm_takeownership.c
@@ -77,6 +77,7 @@ int main(int argc, char **argv)
 	{"srk-well-known", no_argument, NULL, 'z'},
 	};
 
+	memset(&hSrk, 0, sizeof(hSrk));
 	initIntlSys();
 
 	if (genericOptHandler
