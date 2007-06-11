--- report.c.orig	Tue Jan  2 17:11:26 2007
+++ report.c	Fri Jun  8 08:13:13 2007
@@ -46,6 +46,7 @@
    long long int incache=0;
    long long int oucache=0;
    char *s;
+   char *haystack;
    DIR *dirp;
    struct dirent *direntp;
 
@@ -73,7 +74,9 @@
 
    dirp = opendir(tmp);
    while ((direntp = readdir( dirp )) != NULL ) {
-      if((strstr(direntp->d_name,".log") == 0) ||
+      haystack=direntp->d_name;
+      haystack+=(strlen(haystack)-5);
+      if((strstr(haystack,".log") == 0) ||
          (strncmp(direntp->d_name,"download.log",12) == 0) ||
          (strncmp(direntp->d_name,"denied.log",10) == 0) ||
 	 (strncmp(direntp->d_name,"authfail.log.unsort",19) == 0))
@@ -89,7 +92,7 @@
       getword(wname2,wdname,'.');
       strcat(user,wname2);
    
-      if(strcmp(wdname,"log") !=0) {
+      if((strcmp(wdname,"log")!=0) || (strlen(wdname)>3)) {
          strcat(user,".");
          goto strip_prefix;
       }
