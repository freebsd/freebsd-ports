--- ./ssmtp.h.orig	2002-09-27 09:18:24.000000000 -0400
+++ ./ssmtp.h	2008-11-17 18:55:03.000000000 -0500
@@ -37,5 +37,5 @@
 void get_arpadate(char *);
 
 /* base64.c */
-void to64frombits(unsigned char *, const unsigned char *, int);
-int from64tobits(char *, const char *);
+void to64frombits(char *, const unsigned char *, int);
+int from64tobits(unsigned char *, const char *);
