--- scanner_clamd.c.orig	Mon May  1 10:54:52 2006
+++ scanner_clamd.c	Mon May  1 10:55:00 2006
@@ -99,7 +99,10 @@
       loc2 = tmp-config->virusscanner+1;
       len=strlen(config->virusscanner);
       config->clamdport=substr(config->virusscanner,loc2,len);
-      config->clamdserver=strndup(config->virusscanner,loc); //TODO: 6 bytes in 1 blocks are definitely lost in loss record 1 of 2
+//      config->clamdserver=strndup(config->virusscanner,loc); //TODO: 6 bytes in 1 blocks are definitely lost in loss record 1 of 2
+config->clamdserver=malloc(loc+1); 
+config->clamdserver=strncpy(config->clamdserver, config->virusscanner, loc);
+config->clamdserver[1] = 0;
       do_log(LOG_DEBUG, "Reset ClamdServer to: %s Port: %s",config->clamdserver, config->clamdport);
    }
    bzero(&clamd_pri, sizeof(clamd_pri));
@@ -262,7 +265,10 @@
    char  *tmp=NULL;
 
    if (strlen(NONULL(config->virusscanner))<1){
-      tmp=strndup(DEFAULT_SERVER,strlen(DEFAULT_SERVER));
+      //tmp=strndup(DEFAULT_SERVER,strlen(DEFAULT_SERVER));
+tmp=malloc(strlen(DEFAULT_SERVER)+1); 
+tmp=strncpy(tmp, DEFAULT_SERVER, loc);
+config->clamdserver[1] = 0;
       strncat(tmp,":",1);
       strncat(tmp,DEFAULT_PORT,4);
       config->virusscanner=tmp;
@@ -274,7 +280,10 @@
       loc2 = tmp-config->virusscanner+1;
       len=strlen(config->virusscanner);
       config->clamdport=substr(config->virusscanner,loc2,len);
-      config->clamdserver=strndup(config->virusscanner,loc); //TODO: 6 bytes in 1 blocks are definitely lost in loss record 1 of 2
+      //config->clamdserver=strndup(config->virusscanner,loc); //TODO: 6 bytes in 1 blocks are definitely lost in loss record 1 of 2
+config->clamdserver=malloc(loc+1); 
+config->clamdserver=strncpy(config->clamdserver, config->virusscanner, loc);
+config->clamdserver[1] = 0;
       do_log(LOG_DEBUG, "Clamd init. Server: %s Port: %s",config->clamdserver, config->clamdport);
    }else{
       do_log(LOG_CRIT, "Clamd init unable to locate separator: %s",config->virusscanner);
