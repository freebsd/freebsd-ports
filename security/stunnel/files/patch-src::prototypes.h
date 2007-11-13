An official patch obtained from ftp://stunnel.mirt.net/stunnel/setuid.patch

--- src/prototypes.h.old	2007-11-12 11:30:43.000000000 +0200
+++ src/prototypes.h	2007-11-12 11:30:48.000000000 +0200
@@ -57,7 +57,6 @@
 void main_initialize(char *, char *);
 void main_execute(void);
 void stunnel_info(int);
-void drop_privileges(void);
 
 /**************************************** Prototypes for log.c */
 
