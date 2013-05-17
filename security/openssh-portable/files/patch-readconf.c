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


--- readconf.c.orig	2010-08-03 00:04:46.000000000 -0600
+++ readconf.c	2010-09-14 16:14:12.000000000 -0600
@@ -1169,7 +1169,7 @@
 	if (options->batch_mode == -1)
 		options->batch_mode = 0;
 	if (options->check_host_ip == -1)
-		options->check_host_ip = 1;
+		options->check_host_ip = 0;
 	if (options->strict_host_key_checking == -1)
 		options->strict_host_key_checking = 2;	/* 2 is default */
 	if (options->compression == -1)
--- readconf.c	(revision 181917)
+++ readconf.c	(revision 181918)
@@ -18,6 +18,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/socket.h>
+#include <sys/sysctl.h>
 
 #include <netinet/in.h>
 
@@ -245,7 +246,19 @@
 	Forward *fwd;
 #ifndef NO_IPPORT_RESERVED_CONCEPT
 	extern uid_t original_real_uid;
-	if (newfwd->listen_port < IPPORT_RESERVED && original_real_uid != 0)
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
+	if (newfwd->listen_port < ipport_reserved && original_real_uid != 0)
 		fatal("Privileged ports can only be forwarded by root.");
 #endif
 	if (options->num_local_forwards >= SSH_MAX_FORWARDS_PER_DIRECTION)
