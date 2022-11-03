--- tpm_mkaik.c.orig	2017-05-26 13:25:17 UTC
+++ tpm_mkaik.c
@@ -102,7 +102,8 @@ static int usage(const char *prog)
   const char text[] =
     "Usage: %s [options] blob pubkey\n"
     "Options:\n"
-    "\t-z   Use well known secret used as owner secret\n"
+    "\t-y   Use well known secret used as owner secret\n"
+    "\t-z   Use well known secret used as SRK secret\n"
     "\t-u   Use TSS UNICODE encoding for passwords\n"
     "\t-h   Display command usage info\n"
     "\t-v   Display command version info\n"
@@ -115,13 +116,17 @@ int main (int argc, char **argv)
 
 int main (int argc, char **argv)
 {
-  int well_known = 0;
+  int well_known_srk = 0;
+  int well_known_owner = 0;
   int utf16le = 0;
   int opt;
-  while ((opt = getopt(argc, argv, "zuhv")) != -1) {
+  while ((opt = getopt(argc, argv, "yzuhv")) != -1) {
     switch (opt) {
+    case 'y':
+      well_known_owner = 1;
+      break;
     case 'z':
-      well_known = 1;
+      well_known_srk = 1;
       break;
     case 'u':
       utf16le = 1;
@@ -173,7 +178,7 @@ int main (int argc, char **argv)
   if (rc != TSS_SUCCESS)
     return tidy(hContext, tss_err(rc, "getting SRK policy"));
 
-  rc = setSecret("Enter SRK password: ", hContext, hSrkPolicy, well_known, utf16le);
+  rc = setSecret("Enter SRK password: ", hContext, hSrkPolicy, well_known_srk, utf16le);
   if (rc != TSS_SUCCESS)
     return tidy(hContext, tss_err(rc, "setting SRK secret"));
 
@@ -193,7 +198,7 @@ int main (int argc, char **argv)
   if (rc != TSS_SUCCESS)
     return tidy(hContext, tss_err(rc, "assigning TPM policy"));
 
-  rc = setSecret("Enter owner password: ", hContext, hTPMPolicy, well_known, utf16le);
+  rc = setSecret("Enter owner password: ", hContext, hTPMPolicy, well_known_owner, utf16le);
   if (rc != TSS_SUCCESS)
     return tidy(hContext, tss_err(rc, "setting TPM policy secret"));
 
