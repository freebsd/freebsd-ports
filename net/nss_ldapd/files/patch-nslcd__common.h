--- ./nslcd/common.h.orig	2009-06-03 10:31:05.000000000 +0000
+++ ./nslcd/common.h	2009-08-02 22:32:27.000000000 +0000
@@ -124,9 +124,9 @@
 int nslcd_network_byname(TFILE *fp,MYLDAP_SESSION *session);
 int nslcd_network_byaddr(TFILE *fp,MYLDAP_SESSION *session);
 int nslcd_network_all(TFILE *fp,MYLDAP_SESSION *session);
-int nslcd_passwd_byname(TFILE *fp,MYLDAP_SESSION *session);
-int nslcd_passwd_byuid(TFILE *fp,MYLDAP_SESSION *session);
-int nslcd_passwd_all(TFILE *fp,MYLDAP_SESSION *session);
+int nslcd_passwd_byname(TFILE *fp,MYLDAP_SESSION *session,uid_t uid);
+int nslcd_passwd_byuid(TFILE *fp,MYLDAP_SESSION *session,uid_t uid);
+int nslcd_passwd_all(TFILE *fp,MYLDAP_SESSION *session,uid_t uid);
 int nslcd_protocol_byname(TFILE *fp,MYLDAP_SESSION *session);
 int nslcd_protocol_bynumber(TFILE *fp,MYLDAP_SESSION *session);
 int nslcd_protocol_all(TFILE *fp,MYLDAP_SESSION *session);
@@ -145,8 +145,12 @@
 int nslcd_pam_pwmod(TFILE *fp,MYLDAP_SESSION *session);
 
 /* macro for generating service handling code */
-#define NSLCD_HANDLE(db,fn,readfn,logcall,action,mkfilter,writefn) \
-  int nslcd_##db##_##fn(TFILE *fp,MYLDAP_SESSION *session) \
+#define COMMA	,
+#define NSLCD_HANDLE(db,fn,readfn,logcall,action,mkfilter,writefn)	NSLCD_HANDLE_PARAMS(db,fn,,readfn,logcall,action,mkfilter,writefn)
+#define NSLCD_HANDLE_UID(db,fn,readfn,logcall,action,mkfilter,writefn)	NSLCD_HANDLE_PARAMS(db,fn,COMMA uid_t calleruid,readfn,logcall,action,mkfilter,writefn)
+
+#define NSLCD_HANDLE_PARAMS(db,fn,params,readfn,logcall,action,mkfilter,writefn) \
+  int nslcd_##db##_##fn(TFILE *fp,MYLDAP_SESSION *session params ) \
   { \
     /* define common variables */ \
     int32_t tmpint32; \
