--- src/tpm_mgmt/tpm_nvwrite.c.orig	2017-02-21 01:23:57 UTC
+++ src/tpm_mgmt/tpm_nvwrite.c
@@ -33,6 +33,7 @@ static BOOL nvindex_set;
 static unsigned int nvindex;
 static unsigned int offset;
 static unsigned int length;
+static int lengthp;
 static int fillvalue = -1;
 static const char *filename;
 static BOOL passWellKnown;
@@ -60,6 +61,7 @@ static int parse(const int aOpt, const char *aArg)
 		if (parseHexOrDecimal(aArg, &length, 0, UINT_MAX,
 				      "length of data") != 0)
 			return -1;
+		lengthp = 1;
 		break;
 
 	case 'n':
@@ -220,7 +222,7 @@ int main(int argc, char **argv)
 		close(fd);
 		fd = -1;
 	} else if (fillvalue >= 0) {
-		if (length < 0) {
+		if (lengthp == 0) {
 			logError(_("Requiring size parameter.\n"));
 			return -1;
 		}
