--- lib/afp_url.c.orig	2008-03-04 20:16:49.000000000 +0000
+++ lib/afp_url.c	2012-10-14 13:13:06.000000000 +0000
@@ -3,7 +3,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
-#include "afp.h"
+#include "afpfs-ng/afp.h"
 
 void afp_default_url(struct afp_url *url)
 {
@@ -21,7 +21,9 @@
 
 static int check_port(char * port) 
 {
-	long long ret = strtol(port,NULL,10);
+	long long ret = 0;
+	errno = 0;
+	ret = strtol(port,NULL,10);
 	if ((ret<0) || (ret>32767)) return -1;
 	if (errno) {
 		printf("port error\n");
@@ -33,7 +35,7 @@
 static int check_uamname(const char * uam) 
 {
 	char * p;
-	for (p=uam;*p;p++) {
+	for (p=(char *)uam;*p;p++) {
 		if (*p==' ') continue;
 		if ((*p<'A') || (*p>'z')) return -1;
 	}
@@ -188,7 +190,7 @@
 		return -1;
 
 	}
-	if (p==NULL) p=toparse;
+	if (p==NULL) p=(char *)toparse;
 
 	/* Now split on the first / */
 	if (sscanf(p,"%[^/]/%[^$]",
diff -Naur afpfs-ng-0.8.1.orig/lib/client.c afpfs-ng-0.8.1/lib/client.c
