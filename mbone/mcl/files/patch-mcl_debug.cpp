--- src/common/mcl_debug.cpp.orig	Tue Jul 22 19:37:39 2003
+++ src/common/mcl_debug.cpp	Wed Oct 15 17:55:58 2003
@@ -73,7 +73,7 @@
 	PRINT_OUT((mcl_stdout, "\tDUMP %d first bytes...\n\t", i * sizeof(int)))
 	for (ptr = (int*)buf; i > 0; i--, ptr++) {
 		/* convert to big endian format to be sure of byte order */
-		PRINT_OUT((mcl_stdout, "%08x ", htonl(*ptr)))
+		PRINT_OUT((mcl_stdout, "%08lx ", htonl(*ptr)))
 		if (++j == 8) {
 			j = 0;
 			PRINT_OUT((mcl_stdout, "\n\t"))
