--- ppa_syslog.h.orig	2009-12-10 19:11:17 UTC
+++ ppa_syslog.h
@@ -39,7 +39,7 @@
 #include <syslog.h>
 #endif
 
-char syslog_message[128];
+extern char syslog_message[128];
 extern size_t message_size ;
 
 void wrap_syslog( int, char *, char *);
