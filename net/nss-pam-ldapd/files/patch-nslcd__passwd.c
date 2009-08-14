--- ./nslcd/passwd.c.orig	2009-06-29 19:04:54.000000000 +0000
+++ ./nslcd/passwd.c	2009-08-02 22:32:27.000000000 +0000
@@ -292,7 +292,7 @@
 #define MAXUIDS_PER_ENTRY 5
 
 static int write_passwd(TFILE *fp,MYLDAP_ENTRY *entry,const char *requser,
-                        const uid_t *requid)
+                        const uid_t *requid,uid_t calleruid)
 {
   int32_t tmpint32;
   const char **tmpvalues;
@@ -323,7 +323,7 @@
   else
   {
     passwd=get_userpassword(entry,attmap_passwd_userPassword);
-    if (passwd==NULL)
+    if ((passwd==NULL) || (calleruid!=0))
       passwd=default_passwd_userPassword;
   }
   /* get the uids for this entry */
@@ -451,7 +451,7 @@
   return 0;
 }
 
-NSLCD_HANDLE(
+NSLCD_HANDLE_UID(
   passwd,byname,
   char name[256];
   char filter[1024];
@@ -463,10 +463,10 @@
   log_log(LOG_DEBUG,"nslcd_passwd_byname(%s)",name);,
   NSLCD_ACTION_PASSWD_BYNAME,
   mkfilter_passwd_byname(name,filter,sizeof(filter)),
-  write_passwd(fp,entry,name,NULL)
+  write_passwd(fp,entry,name,NULL,calleruid)
 )
 
-NSLCD_HANDLE(
+NSLCD_HANDLE_UID(
   passwd,byuid,
   uid_t uid;
   char filter[1024];
@@ -474,15 +474,15 @@
   log_log(LOG_DEBUG,"nslcd_passwd_byuid(%d)",(int)uid);,
   NSLCD_ACTION_PASSWD_BYUID,
   mkfilter_passwd_byuid(uid,filter,sizeof(filter)),
-  write_passwd(fp,entry,NULL,&uid)
+  write_passwd(fp,entry,NULL,&uid,calleruid)
 )
 
-NSLCD_HANDLE(
+NSLCD_HANDLE_UID(
   passwd,all,
   const char *filter;
   /* no parameters to read */,
   log_log(LOG_DEBUG,"nslcd_passwd_all()");,
   NSLCD_ACTION_PASSWD_ALL,
   (filter=passwd_filter,0),
-  write_passwd(fp,entry,NULL,NULL)
+  write_passwd(fp,entry,NULL,NULL,calleruid)
 )
