--- readconf.c.orig	2009-02-13 23:28:21.000000000 -0600
+++ readconf.c	2010-01-14 01:33:17.913145559 -0600
@@ -42,6 +42,7 @@
 #include "buffer.h"
 #include "kex.h"
 #include "mac.h"
+#include "version.h"
 
 /* Format of the configuration file:
 
@@ -130,6 +131,7 @@
 	oServerAliveInterval, oServerAliveCountMax, oIdentitiesOnly,
 	oSendEnv, oControlPath, oControlMaster, oHashKnownHosts,
 	oTunnel, oTunnelDevice, oLocalCommand, oPermitLocalCommand,
+	oVersionAddendum,
 	oVisualHostKey, oZeroKnowledgePasswordAuthentication,
 	oDeprecated, oUnsupported
 } OpCodes;
@@ -235,6 +237,7 @@
 	{ "zeroknowledgepasswordauthentication", oUnsupported },
 #endif
 
+	{ "versionaddendum", oVersionAddendum },
 	{ NULL, oBadOption }
 };
 
@@ -914,6 +917,13 @@
 		intptr = &options->visual_host_key;
 		goto parse_flag;
 
+	case oVersionAddendum:
+		ssh_version_set_addendum(strtok(s, "\n"));
+		do {
+			arg = strdelim(&s);
+		} while (arg != NULL && *arg != '\0');
+		break;
+
 	case oDeprecated:
 		debug("%s line %d: Deprecated option \"%s\"",
 		    filename, linenum, keyword);
@@ -1112,7 +1122,7 @@
 	if (options->batch_mode == -1)
 		options->batch_mode = 0;
 	if (options->check_host_ip == -1)
-		options->check_host_ip = 1;
+		options->check_host_ip = 0;
 	if (options->strict_host_key_checking == -1)
 		options->strict_host_key_checking = 2;	/* 2 is default */
 	if (options->compression == -1)
