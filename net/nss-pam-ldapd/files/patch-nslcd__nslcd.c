--- nslcd/nslcd.c.orig	2010-07-06 23:36:52.000000000 +0400
+++ nslcd/nslcd.c	2010-07-06 23:40:01.000000000 +0400
@@ -574,7 +574,7 @@
   char *error;
   int *enable_flag;
   /* try to load the NSS module */
-  handle=dlopen("libnss_ldap.so.2",RTLD_LAZY|RTLD_NODELETE);
+  handle=dlopen("nss_ldap.so.1",RTLD_LAZY|RTLD_NODELETE);
   if (handle==NULL)
   {
     log_log(LOG_WARNING,"Warning: LDAP NSS module not loaded: %s",dlerror());
