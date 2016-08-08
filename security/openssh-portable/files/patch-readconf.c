--- UTC
base defaults

r99048 | des | 2002-06-29 05:51:56 -0500 (Sat, 29 Jun 2002) | 4 lines
Changed paths:
   M /head/crypto/openssh/myproposal.h
   M /head/crypto/openssh/readconf.c
   M /head/crypto/openssh/servconf.c

Apply FreeBSD's configuration defaults.

------------------------------------------------------------------------
r181918 | des | 2008-08-20 05:40:07 -0500 (Wed, 20 Aug 2008) | 6 lines
Changed paths:
   M /head/crypto/openssh/readconf.c

Use net.inet.ip.portrange.reservedhigh instead of IPPORT_RESERVED.
Submitted upstream, no reaction.

Submitted by:   delphij@

--- readconf.c.orig	2014-07-17 23:11:26.000000000 -0500
+++ readconf.c	2014-11-03 16:45:05.188796445 -0600
@@ -17,6 +17,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/socket.h>
+#include <sys/sysctl.h>
 #include <sys/wait.h>
 #include <sys/un.h>
 
@@ -311,8 +312,19 @@ add_local_forward(Options *options, cons
 	struct Forward *fwd;
 	extern uid_t original_real_uid;
 	int i;
-
-	if (newfwd->listen_port < IPPORT_RESERVED && original_real_uid != 0 &&
+	int ipport_reserved;
+#ifdef __FreeBSD__
+	size_t len_ipport_reserved = sizeof(ipport_reserved);
+
+	if (sysctlbyname("net.inet.ip.portrange.reservedhigh",
+	    &ipport_reserved, &len_ipport_reserved, NULL, 0) != 0)
+		ipport_reserved = IPPORT_RESERVED;
+	else
+		ipport_reserved++;
+#else
+	ipport_reserved = IPPORT_RESERVED;
+#endif
+	if (newfwd->listen_port < ipport_reserved && original_real_uid != 0 &&
 	    newfwd->listen_path == NULL)
 		fatal("Privileged ports can only be forwarded by root.");
 	/* Don't add duplicates */
@@ -1934,7 +1946,7 @@ fill_default_options(Options * options)
 	if (options->batch_mode == -1)
 		options->batch_mode = 0;
 	if (options->check_host_ip == -1)
-		options->check_host_ip = 1;
+		options->check_host_ip = 0;
 	if (options->strict_host_key_checking == -1)
 		options->strict_host_key_checking = 2;	/* 2 is default */
 	if (options->compression == -1)
