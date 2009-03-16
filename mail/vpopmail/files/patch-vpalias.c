Honor the correct limits.

--- a/vpalias.c
+++ b/vpalias.c
@@ -30,11 +30,11 @@
 
 /* Globals */
 static char alias_line[MAX_ALIAS_LINE];
-static char Dir[156];
+static char Dir[MAX_PW_DIR + 8 + MAX_PW_NAME + 1];
 static int max_names, num_names, cur_name;
 static char **names = NULL;
 
-#define MAX_FILE_SIZE 156
+#define MAX_FILE_SIZE MAX_PW_DIR
 static FILE *alias_fs = NULL;
 static char mydomain[MAX_FILE_SIZE];
 
@@ -46,7 +46,7 @@
 char *valias_select( char *alias, char *domain )
 {
  char *tmpstr;
- static char tmpbuf[156];
+ static char tmpbuf[MAX_PW_DIR];
  uid_t uid;
  gid_t gid;
  int i;
@@ -77,7 +77,7 @@
       alias_fs = NULL;
     }
 
-    if ((tmpstr=vget_assign(domain,alias_line,MAX_ALIAS_LINE,&uid,&gid))==NULL) {
+    if ((tmpstr=vget_assign(domain,Dir,MAX_PW_DIR+1,&uid,&gid))==NULL) {
 	printf("invalid domain, not in qmail assign file\n");
 	return(NULL);
     }
@@ -115,7 +115,6 @@
 {
  int i;
  char *tmpstr;
- char Dir[156];
  char *p;
  uid_t uid;
  gid_t gid;
@@ -128,7 +127,7 @@
     if ( strlen(domain) > MAX_PW_DOMAIN ) return(VA_DOMAIN_NAME_TOO_LONG);
     if ( strlen(alias_line) >= MAX_ALIAS_LINE ) return(VA_ALIAS_LINE_TOO_LONG);
 
-    if ((tmpstr = vget_assign(domain, Dir, sizeof(Dir), &uid, &gid )) == NULL) {
+    if ((tmpstr = vget_assign(domain, Dir, MAX_PW_DIR+1, &uid, &gid )) == NULL) {
 	printf("invalid domain, not in qmail assign file\n");
 	return(-1);
     }
@@ -164,7 +163,6 @@
 {
  int i;
  char *tmpstr;
- char Dir[156];
  char *p;
  char LineBuf[512];
  char *DirNew;
@@ -179,7 +177,7 @@
     if ( strlen(domain) > MAX_PW_DOMAIN ) return(VA_DOMAIN_NAME_TOO_LONG);
     if ( strlen(alias_line) >= MAX_ALIAS_LINE ) return(VA_ALIAS_LINE_TOO_LONG);
 
-    if ((tmpstr = vget_assign(domain, Dir, sizeof(Dir), &uid, &gid )) == NULL) {
+    if ((tmpstr = vget_assign(domain, Dir, MAX_PW_DIR+1, &uid, &gid )) == NULL) {
     printf("invalid domain, not in qmail assign file\n");
     return(-1);
     }
@@ -191,7 +189,11 @@
       Dir[i++] = (*p == '.' ? ':' : *p);
     Dir[i] = '\0';
 
-    DirNew = strcat(strcpy(malloc(8 + sizeof(Dir) + 4), Dir), ".new");
+    i = strlen(Dir) + 5;
+    DirNew = malloc(i);
+    if (DirNew == NULL)
+      return(-1);
+    snprintf(DirNew, i, "%s.new", Dir);
 
     if ( (fr = fopen(Dir, "r")) == NULL ) {
       free(DirNew);
@@ -230,7 +232,6 @@
 int valias_delete( char *alias, char *domain)
 {
  char *tmpstr;
- char Dir[156];
  char *p;
  uid_t uid;
  gid_t gid;
@@ -241,7 +242,7 @@
     if ( strlen(alias) > MAX_PW_NAME ) return(VA_USER_NAME_TOO_LONG);
     if ( strlen(domain) > MAX_PW_DOMAIN ) return(VA_DOMAIN_NAME_TOO_LONG);
 
-    if ((tmpstr = vget_assign(domain, Dir, 156, &uid, &gid )) == NULL) {
+    if ((tmpstr = vget_assign(domain, Dir, MAX_PW_DIR+1, &uid, &gid )) == NULL) {
 	printf("invalid domain, not in qmail assign file\n");
 	return(-1);
     }
@@ -295,7 +296,7 @@
         alias_fs = NULL;
     }
 
-    if ((vget_assign(domain, Dir, sizeof(Dir), &uid, &gid )) == NULL) {
+    if ((vget_assign(domain, Dir, MAX_PW_DIR+1, &uid, &gid )) == NULL) {
 	printf("invalid domain, not in qmail assign file\n");
 	return(NULL);
     }
@@ -441,7 +442,7 @@
         alias_fs = NULL;
     }
 
-    if ((vget_assign(domain, Dir, sizeof(Dir), &uid, &gid )) == NULL) {
+    if ((vget_assign(domain, Dir, MAX_PW_DIR+1, &uid, &gid )) == NULL) {
 	printf("invalid domain, not in qmail assign file\n");
 	return(NULL);
     }
