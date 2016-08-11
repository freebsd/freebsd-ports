--- src/tools/htpasswd.c.orig	2011-09-15 05:13:13 UTC
+++ src/tools/htpasswd.c
@@ -53,7 +53,7 @@ void getword(char *word, char *line, cha
     ;
 }
 
-int getline(char *s, int n, FILE *f) {
+int get_line(char *s, int n, FILE *f) {
   register int i=0;
 
   while(1) {
@@ -165,7 +165,7 @@ int main(int argc, char *argv[]) {
   strcpy(user,argv[2]);
 
   found = 0;
-  while(!(getline(line,MAX_STRING_LEN,f))) {
+  while(!(get_line(line,MAX_STRING_LEN,f))) {
     if(found || (line[0] == '#') || (!line[0])) {
       putline(tfp,line);
       continue;
