--- nslcd/cfg.c.orig	2009-10-05 21:47:47.000000000 +0400
+++ nslcd/cfg.c	2009-12-20 18:10:37.000000000 +0300
@@ -33,6 +33,9 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
+#ifdef ENABLE_NSS_COMPAT
+#include <libgen.h>
+#endif
 #include <errno.h>
 #include <netdb.h>
 #include <sys/socket.h>
@@ -665,6 +668,25 @@
   int rc;
   char *value;
 #endif
+#ifdef ENABLE_NSS_COMPAT
+  /* get secret password */
+  snprintf(linebuf, sizeof(linebuf), "%s/nss_ldap.secret", dirname(filename));
+  if ((fp=fopen(linebuf,"r"))==NULL)
+  {
+    log_log(LOG_ERR,"cannot open secret file (%s): %s",linebuf,strerror(errno));
+    /* exit(EXIT_FAILURE); */
+  }
+  else if (fgets(linebuf,MAX_LINE_LENGTH,fp)!=NULL)
+  {
+    i=strlen(linebuf);
+    if (i>0)
+      linebuf[i-1]='\0';
+    cfg->ldc_bindpw=strdup(linebuf);
+  }
+  if (fp!=NULL)
+    fclose(fp);
+#endif
+
   /* open config file */
   if ((fp=fopen(filename,"r"))==NULL)
   {
@@ -733,13 +755,20 @@
       get_int(filename,lnr,keyword,&line,&cfg->ldc_version);
       get_eol(filename,lnr,keyword,&line);
     }
+#ifdef ENABLE_NSS_COMPAT
+    else if (strcasecmp(keyword,"rootbinddn")==0)
+#else
     else if (strcasecmp(keyword,"binddn")==0)
+#endif
     {
       get_restdup(filename,lnr,keyword,&line,&cfg->ldc_binddn);
     }
     else if (strcasecmp(keyword,"bindpw")==0)
     {
-      get_restdup(filename,lnr,keyword,&line,&cfg->ldc_bindpw);
+#ifdef ENABLE_NSS_COMPAT
+      if (cfg->ldc_bindpw == NULL)
+#endif
+        get_restdup(filename,lnr,keyword,&line,&cfg->ldc_bindpw);
     }
     /* SASL authentication options */
     else if (strcasecmp(keyword,"sasl_authcid")==0)
