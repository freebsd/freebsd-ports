--- gensnmptree/gensnmptree.c.orig	Thu Sep 22 08:58:15 2005
+++ gensnmptree/gensnmptree.c	Thu Sep 22 08:59:03 2005
@@ -595,7 +595,9 @@
 
 	fprintf(fp, "#include <sys/types.h>\n");
 	fprintf(fp, "#include <stdio.h>\n");
+#ifdef HAVE_STDINT_H
 	fprintf(fp, "#include <stdint.h>\n");
+#endif
 	if (localincs) {
 		fprintf(fp, "#include \"asn1.h\"\n");
 		fprintf(fp, "#include \"snmp.h\"\n");
