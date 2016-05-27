Index: cgi-lib.c
===================================================================
RCS file: /home/cvs/ringlet/c/contrib/www/cgihtml/cgi-lib.c,v
retrieving revision 1.1.1.1
retrieving revision 1.6
--- cgi-lib.c.orig	1998-05-04 02:12:52 UTC
+++ cgi-lib.c
@@ -17,6 +17,10 @@
 
 #ifdef WINDOWS
 #include <io.h>
+#define mktemp	_mktemp
+#define snprintf	_snprintf
+#else
+#include <unistd.h>
 #endif
 
 #include "cgi-lib.h"
@@ -87,11 +91,11 @@ char *get_DEBUG()
 
 char *get_POST()
 {
-  unsigned int content_length;
+  size_t content_length;
   char *buffer;
 
   if (CONTENT_LENGTH != NULL) {
-    content_length = atoi(CONTENT_LENGTH);
+    content_length = (size_t)strtoull(CONTENT_LENGTH, NULL, 10);
     buffer = (char *)malloc(sizeof(char) * content_length + 1);
     if (fread(buffer,sizeof(char),content_length,stdin) != content_length) {
       /* consistency error. */
@@ -181,7 +185,7 @@ int parse_CGI_encoded(llist *entries, ch
 
 /* stolen from k&r and seriously modified to do what I want */
 
-int getline(char s[], int lim)
+int get_line(char s[], int lim)
 {
   int c, i=0, num;
 
@@ -202,7 +206,7 @@ int getline(char s[], int lim)
 
 int parse_form_encoded(llist* entries)
 {
-  long content_length;
+  size_t content_length, fnsize;
   entrytype entry;
   node* window;
   FILE *uploadfile;
@@ -220,7 +224,7 @@ int parse_form_encoded(llist* entries)
   _fmode = BINARY;                    /* default all file I/O as binary */
 #endif
   if (CONTENT_LENGTH != NULL)
-    content_length = atol(CONTENT_LENGTH);
+    content_length = (size_t)strtoull(CONTENT_LENGTH, NULL, 10);
   else
     return 0;
   /* get boundary */
@@ -231,9 +235,9 @@ int parse_form_encoded(llist* entries)
   list_create(entries);
   window = entries->head;
   /* ignore first boundary; this isn't so robust; improve it later */
-  getline(buffer,BUFSIZ);
+  get_line(buffer,BUFSIZ);
   /* now start parsing */
-  while ((bytesread=getline(buffer,BUFSIZ)) != 0) {
+  while ((bytesread=get_line(buffer,BUFSIZ)) != 0) {
     start = 1;
     /* this assumes that buffer contains no binary characters.
        if the buffer contains the first valid header, then this
@@ -241,14 +245,20 @@ int parse_form_encoded(llist* entries)
        robustness sake. */
     buffer[bytesread] = '\0';
     tempstr = newstr(buffer);
-    tempstr += (sizeof(char) * 38); /* 38 is header up to name */
-    entry.name = tempstr;
+    entry.name = strstr(tempstr, "name=\"");
+    if (entry.name == NULL) {
+      free(tempstr);
+      return 0;
+    }
+    entry.name += 6;
+    if (strchr(entry.name, '"') == NULL) {
+      free(tempstr);
+      return 0;
+    }
+    *strchr(entry.name, '"') = '\0';
     entry.value = (char *)malloc(sizeof(char) * BUFSIZ + 1);
     buffersize = BUFSIZ;
     strcpy(entry.value,"");
-    while (*tempstr != '"')
-      tempstr++;
-    *tempstr = '\0';
     if (strstr(buffer,"filename=\"") != NULL) {
       isfile = 1;
       tempstr = newstr(buffer);
@@ -258,9 +268,9 @@ int parse_form_encoded(llist* entries)
 	entry.value = (char *) realloc(entry.value, sizeof(char) *
 				       strlen(tempstr)+1);
       entry.value = tempstr;
-      while (*tempstr != '"')
-	tempstr++;
-      *tempstr = '\0';
+      if (strchr(tempstr, '"') == NULL)
+        return 0;
+      *strchr(tempstr, '"') = '\0';
       /* Netscape's Windows browsers handle paths differently from its
 	 UNIX and Mac browsers.  It delivers a full path for the uploaded
 	 file (which it shouldn't do), and it uses backslashes rather than
@@ -275,13 +285,12 @@ int parse_form_encoded(llist* entries)
       }
       window = list_insafter(entries,window,entry);
       numentries++;
-      uploadfname = (char *)malloc(strlen(UPLOADDIR)+strlen(entry.value)+2);
-#ifdef WINDOWS
-      sprintf(uploadfname,"%s\\%s",UPLOADDIR,entry.value);
-#else
-      sprintf(uploadfname,"%s/%s",UPLOADDIR,entry.value);
-#endif
-      if ( (uploadfile = fopen(uploadfname,"w")) == NULL) {
+      fnsize = strlen(UPLOADDIR) + 30;
+      uploadfname = (char *)malloc(fnsize);
+      snprintf(uploadfname,fnsize,"%s/cgihtml-upload-XXXXXX",UPLOADDIR);
+      uploadfname[fnsize - 1] = '\0';
+      if (mktemp(uploadfname) == NULL ||
+          (uploadfile = fopen(uploadfname,"w")) == NULL) {
 	/* null filename; for now, just don't save info.  later, save
 	   to default file */
 	isfile = 0;
@@ -290,7 +299,7 @@ int parse_form_encoded(llist* entries)
     else
       isfile = 0;
     /* ignore rest of headers and first blank line */
-    while (getline(buffer, BUFSIZ) > 1) {
+    while (get_line(buffer, BUFSIZ) > 1) {
       /* DOS style blank line? */
       if ((buffer[0] == '\r') && (buffer[1] == '\n'))
 	break;
@@ -298,7 +307,7 @@ int parse_form_encoded(llist* entries)
     done = 0;
     j = 0;
     while (!done) {
-      bytesread = getline(buffer,BUFSIZ);
+      bytesread = get_line(buffer,BUFSIZ);
       buffer[bytesread] = '\0';
       if (bytesread && strstr(buffer,boundary) == NULL) {
 	if (start) {
@@ -529,9 +538,9 @@ int parse_cookies(llist *entries)
   int numcookies = 0;
   short NM = 1;
 
+  list_create(entries);
   if (cookies == NULL)
     return 0;
-  list_create(entries);
   window = entries->head;
   len = strlen(cookies);
   entry.name = (char *)malloc(sizeof(char) * len + 1);
