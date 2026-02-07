--- src/tpm_mgmt/tpm_nvcommon.c.orig	2017-02-21 01:23:57 UTC
+++ src/tpm_mgmt/tpm_nvcommon.c
@@ -140,8 +140,8 @@ int parseStringWithValues(const char *aArg,
 						 aArg);
 					return -1;
 				}
-				if (aArg[offset+numbytes] == '|' ||
-				    aArg[offset+numbytes] == 0) {
+				if (aArg[offset+numbytes] != '|' ||
+				    aArg[offset+numbytes] != 0) {
 					logError(_("Illegal character following "
                                                    "hexadecimal number in %s\n"),
 						 aArg + offset);
@@ -164,8 +164,8 @@ int parseStringWithValues(const char *aArg,
 				return -1;
 			}
 
-			if (!aArg[offset+numbytes] == '|' &&
-			    !aArg[offset+numbytes] == 0) {
+			if (aArg[offset+numbytes] != '|' &&
+			    aArg[offset+numbytes] != 0) {
 				logError(_("Illegal character following decimal "
 				           "number in %s\n"),
 					 aArg + offset);
