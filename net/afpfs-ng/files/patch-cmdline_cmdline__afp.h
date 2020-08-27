--- cmdline/cmdline_afp.h.orig	2020-08-27 17:43:00 UTC
+++ cmdline/cmdline_afp.h
@@ -1,7 +1,7 @@
 #ifndef CMDLINE_AFP_H_
 #define CMDLINE_AFP_H_
 
-int full_url;
+extern int full_url;
 
 int com_connect(char * arg);
 int com_dir(char * arg);
