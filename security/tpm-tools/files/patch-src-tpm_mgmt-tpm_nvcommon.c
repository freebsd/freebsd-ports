--- src/tpm_mgmt/tpm_nvcommon.c.orig	2011-08-17 12:20:35 UTC
+++ src/tpm_mgmt/tpm_nvcommon.c
@@ -140,8 +140,8 @@ int parseStringWithValues(const char *aA
 						 aArg);
 					return -1;
 				}
-				if (!aArg[offset+numbytes] == '|' &&
-				    !aArg[offset+numbytes] == 0) {
+				if (aArg[offset+numbytes] != '|' &&
+				    aArg[offset+numbytes] != 0) {
 					logError(_("Illegal character following "
                                                    "hexadecimal number in %s\n"),
 						 aArg + offset);
@@ -164,8 +164,8 @@ int parseStringWithValues(const char *aA
 				return -1;
 			}
 
-			if (!aArg[offset+numbytes] == '|' &&
-			    !aArg[offset+numbytes] == 0) {
+			if (aArg[offset+numbytes] != '|' &&
+			    aArg[offset+numbytes] != 0) {
 				logError(_("Illegal character following decimal "
 				           "number in %s\n"),
 					 aArg + offset);
