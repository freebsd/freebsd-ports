--- utils.c.old	Tue Feb 12 15:21:57 2002
+++ utils.c	Tue Feb 12 15:21:24 2002
@@ -259,6 +259,7 @@
 				lastfail++;
 			}
 		}
+		iaddr=ntohl(iaddr);
 		sprintf(iaddrbuff, "%u.%u.%u.%u", (iaddr>>24)&0xff,
 		(iaddr>>16)&0xff, (iaddr>>8)&0xff,
 		iaddr&0xff);

