--- gatling.c.orig	Sat Jan 13 15:37:09 2007
+++ gatling.c	Sat Jan 13 15:47:04 2007
@@ -865,7 +865,7 @@ static inline int issafe(unsigned char c
   return (c!='"' && c!='%' && c>=' ' && c!='+');
 }
 
-unsigned long fmt_urlencoded(char* dest,const char* src,unsigned long len) {
+size_t fmt_urlencoded(char* dest,const char* src,size_t len) {
   register const unsigned char* s=(const unsigned char*) src;
   unsigned long written=0,i;
   for (i=0; i<len; ++i) {
@@ -1011,7 +1011,7 @@ username2:password2
  * authentication was OK or -1 if authentication is needed (the HTTP
  * response was then already written to the iob). */
 int http_dohtaccess(struct http_data* h) {
-  unsigned long filesize;
+  size_t filesize;
   char* map;
   char* s;
   char* auth;
@@ -1031,7 +1031,7 @@ int http_dohtaccess(struct http_data* h)
       char* username,* password;
       char* decoded;
       int i;
-      unsigned long l,dl,ul;
+      size_t l,dl,ul;
       auth+=6;
       while (*auth==' ' || *auth=='\t') ++auth;
       i=str_chr(auth,'\n');
@@ -1103,7 +1103,7 @@ int64 http_openfile(struct http_data* h,
   char* dir=0;
   char* s;
   char* args;
-  unsigned long i;
+  size_t i;
   int64 fd;
   int doesgzip,doesbzip2;
 
@@ -2948,7 +2948,7 @@ void forkslave(int fd,buffer* in) {
 		j=str_chr(x,'\n'); if (j && x[j-1]=='\r') { --j; }
 		k=str_chr(x,' ');
 		if (k<j) {
-		  unsigned long dl;
+		  size_t dl;
 		  remoteuser=alloca(20+k-j);
 		  i=fmt_str(remoteuser,"REMOTE_USER=");
 		  scan_base64(x+k+1,remoteuser+i,&dl);
