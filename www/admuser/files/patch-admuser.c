--- admuser.c.orig	Wed Sep 22 17:11:45 2004
+++ admuser.c	Thu Sep 23 14:25:33 2004
@@ -22,6 +22,26 @@
 FILE           *fpw,
                *tmp;
 
+void getword(char *, char *, char);
+void Herror(char *, FILE *, FILE *);
+static void fix_string(unsigned char *);
+void getconf(char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *);
+void read_pwd_file(char *, char *, char *, char *, char *, char *, int, char *);
+void change_user(char *, char *, char *, char *);
+void go_change_user(char *, char *, char *, char *, char *, char *, int);
+void remove_user(char *, char *, char *, char *, char *);
+void read_pwd_file(char *, char *, char *, char *, char *, char *, int, char *);
+void expire_pwd(char *, char *, char *, char *);
+void disable_user(char *, char *, char *);
+void authfiles(char *);
+void enable_user(char *, char *, char *);
+void add_user(char *, char *, char *, char *);
+void go_add_user(char *, char *, char *, char *, char *);
+void confirm_remove_user(char *, char *, char *);
+static void UserForm(char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *);
+void sort_pwd_file(char *, char *, char *);
+static void go_Authenticate(char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *);
+
 main(argc, argv)
     int             argc;
     char           *argv[];
@@ -116,7 +136,7 @@
     }
 
     if (strcmp(getenv("REQUEST_METHOD"), "GET") == 0) {
-	UserForm(BgColor,TxColor,TiColor,RuColor,Logo,Width,Height,Header,BgImage,PwdFile);
+	UserForm(BgColor,TxColor,TiColor,RuColor,Logo,Width,Height,Header,BgImage,PwdFile,null);
 	return;
     }
 
@@ -153,7 +173,7 @@
        getword(user,InputBuffer,'&');
        getword(pass,InputBuffer,'=');
        getword(pass,InputBuffer,'&');
-       go_Authenticate(user, pass, PwdFile, BgColor, TxColor, TiColor, RuColor, Logo, Width, Height, Header, BgImage);
+       go_Authenticate(user, pass, null, PwdFile, BgColor, TxColor, TiColor, RuColor, Logo, Width, Height, Header, BgImage);
     }
 
     // Reading password file
@@ -1524,17 +1544,17 @@
    char wuser[255];
    int  ok=0;
 
-   if(access(authpwd, F_OK) != 0) {
-      sprintf(Msg, "%s: %s",msg40, authpwd);
+   if(access(pwdfile, F_OK) != 0) {
+      sprintf(Msg, "%s: %s",msg40, pwdfile);
       Xerror(Msg);
    }
-   if(access(authpwd, R_OK) != 0) {
-      sprintf(Msg, "%s: %s",msg41, authpwd);
+   if(access(pwdfile, R_OK) != 0) {
+      sprintf(Msg, "%s: %s",msg41, pwdfile);
       Xerror(Msg);
    }
    authfiles(pwdfile);
-   if((fpw=fopen(authpwd, "r")) == NULL) {
-      sprintf(Msg, "%s %s",msg41, authpwd);
+   if((fpw=fopen(pwdfile, "r")) == NULL) {
+      sprintf(Msg, "%s %s",msg41, pwdfile);
       Herror(Msg, fpw, tmp);
       return;
    }
