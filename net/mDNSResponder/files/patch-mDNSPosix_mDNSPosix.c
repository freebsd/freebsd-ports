--- mDNSPosix/mDNSPosix.c.orig	2009-01-25 04:16:46.000000000 +0100
+++ mDNSPosix/mDNSPosix.c	2010-06-20 21:03:33.000000000 +0200
@@ -581,7 +581,7 @@
 	{
 	char line[256];
 	char nameserver[16];
-	char keyword[10];
+	char keyword[11];
 	int  numOfServers = 0;
 	FILE *fp = fopen(filePath, "r");
 	if (fp == NULL) return -1;
@@ -600,6 +600,7 @@
 			numOfServers++;
 			}
 		}  
+	fclose(fp);
 	return (numOfServers > 0) ? 0 : -1;
 	}
 
