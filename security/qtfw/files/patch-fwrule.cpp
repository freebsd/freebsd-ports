--- fwrule.cpp.orig	Fri Feb 14 13:36:27 2003
+++ fwrule.cpp	Fri Feb 14 13:36:33 2003
@@ -5,6 +5,7 @@
 #include <sys/param.h>
 #include <ctype.h>
 #include <netdb.h>
+#include <netinet/in.h>
 
 #define    IPPROTO_IP              0
 
@@ -547,7 +547,7 @@
 		nCurrentIndex++;
 		ac++;
 	}
-	av = new (char*)[ac];
+	av = new char*[ac];
 	
 	/* Now fill the av[] array */
 	for (int i =0;i < ac;i++)
