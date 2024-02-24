--- hier.c.orig	1998-09-05 02:33:37 UTC
+++ hier.c
@@ -2,20 +2,17 @@ void hier()
 
 void hier()
 {
-  h(auto_home,-1,-1,02755);
+  h(auto_home,-1,-1,0755);
 
-  d(auto_home,"bin",-1,-1,02755);
-  d(auto_home,"lib",-1,-1,02755);
-  d(auto_home,"include",-1,-1,02755);
-  d(auto_home,"man",-1,-1,02755);
-  d(auto_home,"man/man1",-1,-1,02755);
-  d(auto_home,"man/man3",-1,-1,02755);
-  d(auto_home,"man/man5",-1,-1,02755);
-  d(auto_home,"man/man8",-1,-1,02755);
-  d(auto_home,"man/cat1",-1,-1,02755);
-  d(auto_home,"man/cat3",-1,-1,02755);
-  d(auto_home,"man/cat5",-1,-1,02755);
-  d(auto_home,"man/cat8",-1,-1,02755);
+  d(auto_home,"bin",-1,-1,0755);
+  d(auto_home,"lib",-1,-1,0755);
+  d(auto_home,"include",-1,-1,0755);
+  d(auto_home,"share/man",-1,-1,0755);
+  d(auto_home,"share/man/man1",-1,-1,0755);
+  d(auto_home,"share/man/man3",-1,-1,0755);
+  d(auto_home,"share/man/man5",-1,-1,0755);
+  d(auto_home,"share/man/man8",-1,-1,0755);
+  d(auto_home,"etc",-1,-1,0755);
 
   c(auto_home,"lib","mess822.a",-1,-1,0644);
   c(auto_home,"include","mess822.h",-1,-1,0644);
@@ -30,41 +27,23 @@ void hier()
   c(auto_home,"bin","822received",-1,-1,0755);
   c(auto_home,"bin","822print",-1,-1,0755);
 
-  c(auto_home,"man/man1","iftocc.1",-1,-1,0644);
-  c(auto_home,"man/man1","new-inject.1",-1,-1,0644);
-  c(auto_home,"man/man1","822field.1",-1,-1,0644);
-  c(auto_home,"man/man1","822header.1",-1,-1,0644);
-  c(auto_home,"man/man1","822date.1",-1,-1,0644);
-  c(auto_home,"man/man1","822received.1",-1,-1,0644);
-  c(auto_home,"man/man1","822print.1",-1,-1,0644);
-  c(auto_home,"man/man5","rewriting.5",-1,-1,0644);
-  c(auto_home,"man/man8","ofmipd.8",-1,-1,0644);
-  c(auto_home,"man/man8","ofmipname.8",-1,-1,0644);
-  c(auto_home,"man/man3","mess822.3",-1,-1,0644);
-  c(auto_home,"man/man3","mess822_addr.3",-1,-1,0644);
-  c(auto_home,"man/man3","mess822_date.3",-1,-1,0644);
-  c(auto_home,"man/man3","mess822_fold.3",-1,-1,0644);
-  c(auto_home,"man/man3","mess822_quote.3",-1,-1,0644);
-  c(auto_home,"man/man3","mess822_token.3",-1,-1,0644);
-  c(auto_home,"man/man3","mess822_when.3",-1,-1,0644);
+  c(auto_home,"share/man/man1","iftocc.1",-1,-1,0644);
+  c(auto_home,"share/man/man1","new-inject.1",-1,-1,0644);
+  c(auto_home,"share/man/man1","822field.1",-1,-1,0644);
+  c(auto_home,"share/man/man1","822header.1",-1,-1,0644);
+  c(auto_home,"share/man/man1","822date.1",-1,-1,0644);
+  c(auto_home,"share/man/man1","822received.1",-1,-1,0644);
+  c(auto_home,"share/man/man1","822print.1",-1,-1,0644);
+  c(auto_home,"share/man/man5","rewriting.5",-1,-1,0644);
+  c(auto_home,"share/man/man8","ofmipd.8",-1,-1,0644);
+  c(auto_home,"share/man/man8","ofmipname.8",-1,-1,0644);
+  c(auto_home,"share/man/man3","mess822.3",-1,-1,0644);
+  c(auto_home,"share/man/man3","mess822_addr.3",-1,-1,0644);
+  c(auto_home,"share/man/man3","mess822_date.3",-1,-1,0644);
+  c(auto_home,"share/man/man3","mess822_fold.3",-1,-1,0644);
+  c(auto_home,"share/man/man3","mess822_quote.3",-1,-1,0644);
+  c(auto_home,"share/man/man3","mess822_token.3",-1,-1,0644);
+  c(auto_home,"share/man/man3","mess822_when.3",-1,-1,0644);
 
-  c(auto_home,"man/cat1","iftocc.0",-1,-1,0644);
-  c(auto_home,"man/cat1","new-inject.0",-1,-1,0644);
-  c(auto_home,"man/cat1","822field.0",-1,-1,0644);
-  c(auto_home,"man/cat1","822header.0",-1,-1,0644);
-  c(auto_home,"man/cat1","822date.0",-1,-1,0644);
-  c(auto_home,"man/cat1","822received.0",-1,-1,0644);
-  c(auto_home,"man/cat1","822print.0",-1,-1,0644);
-  c(auto_home,"man/cat5","rewriting.0",-1,-1,0644);
-  c(auto_home,"man/cat8","ofmipd.0",-1,-1,0644);
-  c(auto_home,"man/cat8","ofmipname.0",-1,-1,0644);
-  c(auto_home,"man/cat3","mess822.0",-1,-1,0644);
-  c(auto_home,"man/cat3","mess822_addr.0",-1,-1,0644);
-  c(auto_home,"man/cat3","mess822_date.0",-1,-1,0644);
-  c(auto_home,"man/cat3","mess822_fold.0",-1,-1,0644);
-  c(auto_home,"man/cat3","mess822_quote.0",-1,-1,0644);
-  c(auto_home,"man/cat3","mess822_token.0",-1,-1,0644);
-  c(auto_home,"man/cat3","mess822_when.0",-1,-1,0644);
-
-  c("/etc",".","leapsecs.dat",-1,-1,0644);
+  c(auto_home,"etc","leapsecs.dat",-1,-1,0644);
 }
