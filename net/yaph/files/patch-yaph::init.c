--- yaph/init.c.orig	Sat Jun 14 14:52:31 2003
+++ yaph/init.c	Sat Jun 14 14:52:41 2003
@@ -127,7 +127,7 @@
 FILE *cnf=NULL;
 char buff[1024];
 	if(!(cnf=fopen("./yaph.conf","rb")))
-		if(!(cnf=fopen("/etc/yaph.conf","rb")))
+		if(!(cnf=fopen(PREFIX "/etc/yaph.conf","rb")))
 			goto no_file;
 	while(fgets(buff,sizeof(buff),cnf))
 	{
