--- refer/inv1.c.orig	2016-03-09 21:27:38 UTC
+++ refer/inv1.c
@@ -28,6 +28,9 @@
 #include <stdio.h>
 #include <locale.h>
 #include <assert.h>
+#ifdef __FreeBSD__
+#include <paths.h>
+#endif
 #include <stdlib.h>
 #include <string.h>
 #include "refer..c"
@@ -59,7 +62,11 @@ main(int argc, char **argv)
 	int iflong =0;
 	char *sortdir;
 
+#ifdef __FreeBSD__
+	sortdir = _PATH_VARTMP;
+#else
 	sortdir = (access("/crp/tmp", 06)==0) ? "/crp/tmp" : "/var/tmp";
+#endif
 	while (argc>1 && argv[1][0] == '-')
 	{
 		switch(argv[1][1])
