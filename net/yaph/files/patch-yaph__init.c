--- yaph/init.c.orig	Sun Feb  9 07:33:04 2003
+++ yaph/init.c	Mon Aug  9 10:41:24 2004
@@ -105,6 +105,7 @@
 globals->content_data=malloc(1024*8);
 if(!globals->content_data)
   exit_error(errno);
+bzero(globals->content_data, 1024 * 8);
 globals->content_request=malloc(1024*8);
 if(!globals->content_request)
   exit_error(errno);
@@ -127,8 +128,9 @@
 FILE *cnf=NULL;
 char buff[1024];
 	if(!(cnf=fopen("./yaph.conf","rb")))
-		if(!(cnf=fopen("/etc/yaph.conf","rb")))
-			goto no_file;
+		cnf=fopen(PREFIX "/etc/yaph.conf","rb");
+	
+	if(cnf != NULL) 
 	while(fgets(buff,sizeof(buff),cnf))
 	{
             if(buff[strspn(buff," ")]!='#')
@@ -200,7 +202,6 @@
                 }
             }
         }
-	no_file:
 }
 
 // ------   open files
