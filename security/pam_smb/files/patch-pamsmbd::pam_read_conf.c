--- pamsmbd/pam_read_conf.c.orig	Wed Mar 20 01:03:33 2002
+++ pamsmbd/pam_read_conf.c	Sat Sep 20 09:32:41 2003
@@ -25,7 +25,7 @@
 #include "constants.h"
 #include "cache.h"
 
-#define CONFFILE "/etc/pam_smb.conf"
+#define CONFFILE "%%PREFIX%%/etc/pam_smb.conf"
 
 int smb_readpamconf(domain_list *);
 
