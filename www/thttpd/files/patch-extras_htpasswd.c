--- extras/htpasswd.c.orig	2001-12-19 00:08:08 UTC
+++ extras/htpasswd.c
@@ -19,7 +19,12 @@
 #define LF 10
 #define CR 13
 
+#define CPW_LEN 13
+
+/* ie 'string' + '\0' */
 #define MAX_STRING_LEN 256
+/* ie 'maxstring' + ':' + cpassword */
+#define MAX_LINE_LEN MAX_STRING_LEN+1+CPW_LEN
 
 int tfd;
 char temp_template[] = "/tmp/htp.XXXXXX";
@@ -135,8 +140,9 @@ add_password( char* user, FILE* f )
     }
 
 static void usage(void) {
-    fprintf(stderr,"Usage: htpasswd [-c] passwordfile username\n");
-    fprintf(stderr,"The -c flag creates a new file.\n");
+    fprintf(stderr,"Usage: htpasswd [-c] passwordfile username\n"
+                   "The -c flag creates a new file.\n"
+                   "Will prompt for password, unless given on stdin.\n");
     exit(1);
 }
 
@@ -149,52 +155,129 @@ void interrupted(int signo) {
 int main(int argc, char *argv[]) {
     FILE *tfp,*f;
     char user[MAX_STRING_LEN];
-    char line[MAX_STRING_LEN];
-    char l[MAX_STRING_LEN];
+    char pwfilename[MAX_STRING_LEN];
+    char line[MAX_LINE_LEN];
+    char l[MAX_LINE_LEN];
     char w[MAX_STRING_LEN];
-    char command[MAX_STRING_LEN];
-    int found;
+    int found,u;
 
     tfd = -1;
+    u = 2; /* argv[u] is username, unless...  */
     signal(SIGINT,(void (*)(int))interrupted);
     if(argc == 4) {
+        u = 3;
         if(strcmp(argv[1],"-c"))
             usage();
+        if((f=fopen(argv[2],"r")) != NULL) {
+            fclose(f);
+            fprintf(stderr,
+                "Password file %s already exists.\n"
+                "Delete it first, if you really want to overwrite it.\n",
+                argv[2]);
+            exit(1);
+        }
+    } else if(argc != 3) usage();
+    /* check uname length; underlying system will take care of pwdfile
+       name too long */
+    if (strlen(argv[u]) >= MAX_STRING_LEN) {
+      fprintf(stderr,"Username too long (max %i): %s\n",
+              MAX_STRING_LEN-1, argv[u]);
+      exit(1);
+    }
+    
+    if(argc == 4) {
         if(!(tfp = fopen(argv[2],"w"))) {
             fprintf(stderr,"Could not open passwd file %s for writing.\n",
                     argv[2]);
             perror("fopen");
             exit(1);
         }
+        if (strlen(argv[2]) > (sizeof(pwfilename) - 1)) {
+            fprintf(stderr, "%s: filename is too long\n", argv[0]);
+	    exit(1);
+        }
+        if (((strchr(argv[2], ';')) != NULL) || ((strchr(argv[2], '>')) != NULL)) {
+	    fprintf(stderr, "%s: filename contains an illegal character\n",
+		argv[0]);
+	    exit(1);
+        }
+        if (strlen(argv[3]) > (sizeof(user) - 1)) {
+	    fprintf(stderr, "%s: username is too long\n", argv[0]);
+	    exit(1);
+        }
+        if ((strchr(argv[3], ':')) != NULL) {
+            fprintf(stderr, "%s: username contains an illegal character\n",
+                argv[0]);
+            exit(1);
+        }
         printf("Adding password for %s.\n",argv[3]);
         add_password(argv[3],tfp);
         fclose(tfp);
         exit(0);
-    } else if(argc != 3) usage();
+    }
 
-    tfd = mkstemp(temp_template);
-    if(!(tfp = fdopen(tfd,"w"))) {
-        fprintf(stderr,"Could not open temp file.\n");
+    if (strlen(argv[1]) > (sizeof(pwfilename) - 1)) {
+        fprintf(stderr, "%s: filename is too long\n", argv[0]);
+        exit(1);
+    }
+    if (((strchr(argv[1], ';')) != NULL) || ((strchr(argv[1], '>')) != NULL)) {
+        fprintf(stderr, "%s: filename contains an illegal character\n",
+                argv[0]);
+        exit(1);
+    }
+    if (strlen(argv[2]) > (sizeof(user) - 1)) {
+        fprintf(stderr, "%s: username is too long\n", argv[0]);
+        exit(1);
+    }
+    if ((strchr(argv[2], ':')) != NULL) {
+        fprintf(stderr, "%s: username contains an illegal character\n",
+                argv[0]);
         exit(1);
     }
-
     if(!(f = fopen(argv[1],"r"))) {
         fprintf(stderr,
                 "Could not open passwd file %s for reading.\n",argv[1]);
         fprintf(stderr,"Use -c option to create new one.\n");
         exit(1);
     }
+    if(freopen(argv[1],"a",f) == NULL) {
+        fprintf(stderr,
+                "Could not open passwd file %s for writing!.\n"
+                "Changes would be lost.\n",argv[1]);
+        exit(1);
+    }
+    f = freopen(argv[1],"r",f);
+    
+    /* pwdfile is there, go on with tempfile now ... */
+    tfd = mkstemp(temp_template);
+    if(!(tfp = fdopen(tfd,"w"))) {
+        fprintf(stderr,"Could not open temp file.\n");
+        exit(1);
+    }
+    /* already checked for boflw ... */
     strncpy(user,argv[2],sizeof(user)-1);
     user[sizeof(user)-1] = '\0';
 
     found = 0;
-    while(!(my_getline(line,MAX_STRING_LEN,f))) {
+    /* line we get is username:pwd, or possibly any other cruft */
+    while(!(my_getline(line,MAX_LINE_LEN,f))) {
+        char *i;
+
         if(found || (line[0] == '#') || (!line[0])) {
             putline(tfp,line);
             continue;
         }
-        strcpy(l,line);
-        getword(w,l,':');
+        i = index(line,':');
+        w[0] = '\0';
+        /* actually, cpw is CPW_LEN chars and never null, hence ':' should 
+           always be at line[strlen(line)-CPW_LEN-1] in a valid user:cpw line
+           Here though we may allow for pre-hancrafted pwdfile (!)...
+           But still need to check for length limits.
+         */
+        if (i != 0 && i-line <= MAX_STRING_LEN-1) {
+            strcpy(l,line);
+            getword(w,l,':');
+        }
         if(strcmp(user,w)) {
             putline(tfp,line);
             continue;
@@ -208,10 +291,28 @@ int main(int argc, char *argv[]) {
         printf("Adding user %s\n",user);
         add_password(user,tfp);
     }
+    /* close, rewind & copy */
+    fclose(f);
+    fclose(tfp);
+    f = fopen(argv[1],"w");    
+    if(f==NULL) {
+      fprintf(stderr,"Failed re-opening %s!?\n",argv[1]);
+      exit(1);
+    }
+    tfp = fopen(temp_template,"r");
+    if(tfp==NULL) {
+      fprintf(stderr,"Failed re-opening tempfile!?\n");
+      exit(1);
+    }
+    {
+      int c;
+      while((c=fgetc(tfp))!=EOF && !feof(tfp))  {
+        fputc(c,f);
+        /* fputc(c,stderr); */
+      }
+    }
     fclose(f);
     fclose(tfp);
-    sprintf(command,"cp %s %s",temp_template,argv[1]);
-    system(command);
     unlink(temp_template);
     exit(0);
 }
