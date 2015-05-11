--- src/fwalls/hosts.c.orig	2015-05-05 01:56:03 UTC
+++ src/fwalls/hosts.c
@@ -31,6 +31,7 @@
 #include "../config.h"
 #include "../sshguard_log.h"
 #include "../sshguard_fw.h"
+#include "parser/address.h"
 
 #ifndef HOSTSFILE_PATH
 #   define HOSTSFILE_PATH     "/etc/hosts.allow"
