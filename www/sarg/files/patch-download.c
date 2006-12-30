--- download.c	2006-12-27 19:29:36.000000000 -0200
+++ download.c	2006-12-27 19:29:16.000000000 -0200
@@ -57,7 +57,7 @@
    strcpy(wdirname,dirname);
    sprintf(report,"%s/download.html",wdirname);
    strcat(wdirname,"/");
-   strcat(wdirname,"period");
+   strcat(wdirname,"sarg-period");
 
    if ((fp_in = fopen(wdirname, "r")) == 0) {
       fprintf(stderr, "SARG: (download) %s: %s\n",text[45],wdirname);

 	  	 
