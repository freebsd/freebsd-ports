--- nslcd/nslcd.c.orig	2011-01-09 13:45:07.000000000 +0300
+++ nslcd/nslcd.c	2011-01-09 13:45:55.000000000 +0300
@@ -574,7 +574,7 @@
   char *error;
   int *enable_flag;
   /* try to load the NSS module */
-  handle=dlopen(NSS_LDAP_SONAME,RTLD_LAZY|RTLD_NODELETE);
+  handle=dlopen(NSS_LDAP_SONAME,RTLD_LAZY);
   if (handle==NULL)
   {
     log_log(LOG_WARNING,"Warning: LDAP NSS module not loaded: %s",dlerror());
@@ -593,7 +593,7 @@
     if (__nss_configure_lookup("hosts","files dns"))
       log_log(LOG_ERR,"unable to override hosts lookup method: %s",strerror(errno));
 #endif /* HAVE___NSS_CONFIGURE_LOOKUP */
-    dlclose(handle);
+    /* Do not dlclose() to keep reference count > 0 instead of RTLD_NODELETE */
     return;
   }
   /* disable nss_ldap */
