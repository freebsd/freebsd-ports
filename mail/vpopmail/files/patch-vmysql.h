--- vmysql.h.orig	Sat Nov  2 23:02:32 2002
+++ vmysql.h	Sat Nov  2 23:06:01 2002
@@ -250,3 +250,12 @@
       INDEX error_idx (error), INDEX message_idx (message)"
 #endif
 
+#ifdef ENABLE_MYSQL_LIMITS
+#define LIMITS_TABLE_LAYOUT "id BIGINT PRIMARY KEY AUTO_INCREMENT, \
+      domain CHAR(64), maxpopaccounts INTEGER, maxaliases INTEGER, \
+      maxforwards INT, maxautoresponders INT, maxmailinglists INT \
+      diskquota INT, defaultquota INT, disablepop INT, disableimap INT, \
+      disabledialup INT, disablepasswordchanging INT, disablewebmail INT, \
+      disablerelay INT, \
+      INDEX domain_idx (domain)"
+#endif
