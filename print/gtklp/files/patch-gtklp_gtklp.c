--- gtklp/gtklp.c.orig	2019-11-01 16:27:28 UTC
+++ gtklp/gtklp.c
@@ -119,7 +119,6 @@ ppd_file_t *printerPPD;
 int PPDopen;
 char *PPDfilename;
 int conflict_active;
-int nox;
 int num_commandline_opts;
 cups_option_t *commandline_opts;
 char nupLayout[5];
