--- mDNSPosix/mDNSPosix.c.orig	2010-05-21 06:35:08.000000000 +0800
+++ mDNSPosix/mDNSPosix.c	2011-01-11 11:51:28.000000000 +0800
@@ -467,7 +467,7 @@
 	{
 	char line[256];
 	char nameserver[16];
-	char keyword[10];
+	char keyword[11];
 	int  numOfServers = 0;
 	FILE *fp = fopen(filePath, "r");
 	if (fp == NULL) return -1;
@@ -486,6 +486,7 @@
 			numOfServers++;
 			}
 		}  
+	fclose(fp);
 	return (numOfServers > 0) ? 0 : -1;
 	}
 
