--- mDNSPosix/mDNSPosix.c.orig	2011-04-07 06:48:43.000000000 +0800
+++ mDNSPosix/mDNSPosix.c	2011-08-28 22:14:54.089049545 +0800
@@ -487,7 +487,7 @@
 	{
 	char line[256];
 	char nameserver[16];
-	char keyword[10];
+	char keyword[11];
 	int  numOfServers = 0;
 	FILE *fp = fopen(filePath, "r");
 	if (fp == NULL) return -1;
@@ -506,6 +506,7 @@
 			numOfServers++;
 			}
 		}  
+	fclose(fp);
 	return (numOfServers > 0) ? 0 : -1;
 	}
 
