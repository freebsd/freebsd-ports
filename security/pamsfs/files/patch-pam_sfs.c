--- pam_sfs.c.orig	Tue Feb 15 02:19:36 2005
+++ pam_sfs.c	Sun Sep 18 15:43:56 2005
@@ -38,14 +38,26 @@
 void safe_strcat(char*,const char*,int);
 
 PAM_EXTERN int pam_sm_authenticate(pam_handle_t *pamh,int flags,int argc,const char **argv) {
+  const char *user;
+  const char *pass;
+  struct passwd *pw;
+  char *homedir;
+  char *sfs="/sfs/";
+  char *serverBegin;
+  char *serverEnd;
+  int lenServer;
+  char *server;
+  int pid;
+    int maxCmd=4096;
+    char *cmd;
+    FILE *f;
+    int status;
+
   openlog("pam_sfs",0,LOG_AUTH);
 
   syslog(LOG_DEBUG,"%s","pam_sm_authenticate");
 
   //read the authentication information
-  const char *user;
-  const char *pass;
-
   if (pam_get_user(pamh,&user,NULL)!=PAM_SUCCESS)
     return PAM_SERVICE_ERR;
 
@@ -53,7 +65,7 @@
     return PAM_SERVICE_ERR;
 
   //get the pw entry for the given user
-  struct passwd *pw=getpwnam(user);
+  pw=getpwnam(user);
   if (pw==NULL)
     return PAM_USER_UNKNOWN;
 
@@ -62,26 +74,24 @@
   //check if user's home-directory matches /sfs/<host>/
   //if not, exit right away
   //if it does, extract <host>
-  char *homedir=pw->pw_dir;
-
-  char *sfs="/sfs/";
+  homedir=pw->pw_dir;
 
   if (strncmp(homedir,sfs,strlen(sfs))!=0)
     return PAM_SUCCESS; //home dir not in /sfs
 
-  char *serverBegin=homedir+strlen(sfs);
-  char *serverEnd=strchr(serverBegin,'/');
+  serverBegin=homedir+strlen(sfs);
+  serverEnd=strchr(serverBegin,'/');
 
   //absolute max of 2048 characters in server name
-  int lenServer=serverEnd-serverBegin+1;
+  lenServer=serverEnd-serverBegin+1;
   if (lenServer>2048)
     return PAM_SERVICE_ERR;
 
-  char *server=malloc(lenServer);
+  server=malloc(lenServer);
   strncpy(server,serverBegin,lenServer-1);
   server[lenServer-1]='\0';
 
-  int pid=fork();
+  pid=fork();
   if (pid==0) {
     //child
     //change to the desired user
@@ -93,8 +103,7 @@
     system("/usr/local/sfs-0.7.2/bin/sfsagent -c 2>/dev/null");
 
     //use a temporary variable to assemble the command in
-    int maxCmd=4096;
-    char *cmd=malloc(maxCmd);
+    *cmd=malloc(maxCmd);
 
     strcpy(cmd,"export HOME=/ ; /usr/local/sfs-0.7.2/bin/sfskey -p 0 add ");
     safe_strcat(cmd,user,maxCmd);
@@ -104,7 +113,7 @@
 
     //syslog(LOG_DEBUG,"executing: %s",cmd);
 
-    FILE *f=popen(cmd,"w");
+    f=popen(cmd,"w");
 
     free(cmd);
     free(server); //child's copy
@@ -116,7 +125,7 @@
 
     fprintf(f,"%s",pass);
 
-    int status=pclose(f);
+    status=pclose(f);
     if (status!=0) {
       syslog(LOG_ERR,"Error from sfskey: %d.",status);
       exit(EXIT_FAILURE);
