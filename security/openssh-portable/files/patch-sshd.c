--- UTC
r109683 | des | 2003-01-22 08:12:59 -0600 (Wed, 22 Jan 2003) | 7 lines
Changed paths:
   M /head/crypto/openssh/sshd.c

Force early initialization of the resolver library, since the resolver
configuration files will no longer be available once sshd is chrooted.

PR:             39953, 40894
Submitted by:   dinoex

r199804 | attilio | 2009-11-25 09:12:24 -0600 (Wed, 25 Nov 2009) | 13 lines
Changed paths:
   M /head/crypto/openssh/sshd.c
   M /head/usr.sbin/cron/cron/cron.c
   M /head/usr.sbin/inetd/inetd.c
   M /head/usr.sbin/syslogd/syslogd.c

Avoid sshd, cron, syslogd and inetd to be killed under high-pressure swap
environments.
Please note that this can't be done while such processes run in jails.

Note: in future it would be interesting to find a way to do that
selectively for any desired proccess (choosen by user himself), probabilly
via a ptrace interface or whatever.

r206397 | kib | 2010-04-08 07:07:40 -0500 (Thu, 08 Apr 2010) | 8 lines
Changed paths:
   M /head/crypto/openssh/sshd.c

Enhance r199804 by marking the daemonised child as immune to OOM instead
of short-living parent. Only mark the master process that accepts
connections, do not protect connection handlers spawned from inetd.


--- sshd.c.orig	2024-06-30 21:36:28.000000000 -0700
+++ sshd.c	2024-07-01 13:44:05.739756000 -0700
@@ -28,6 +28,7 @@
 
 #include <sys/types.h>
 #include <sys/ioctl.h>
+#include <sys/mman.h>
 #include <sys/socket.h>
 #ifdef HAVE_SYS_STAT_H
 # include <sys/stat.h>
@@ -69,6 +70,13 @@
 #include <prot.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <resolv.h>
+#ifdef GSSAPI
+#include "ssh-gss.h"
+#endif
+#endif
+
 #include "xmalloc.h"
 #include "ssh.h"
 #include "sshpty.h"
@@ -1671,7 +1679,30 @@ main(int ac, char **av)
 	for (i = 0; i < options.num_log_verbose; i++)
 		log_verbose_add(options.log_verbose[i]);
 
+#ifdef __FreeBSD__
 	/*
+	 * Initialize the resolver.  This may not happen automatically
+	 * before privsep chroot().
+	 */
+	if ((_res.options & RES_INIT) == 0) {
+		debug("res_init()");
+		res_init();
+	}
+#ifdef GSSAPI
+	/*
+	 * Force GSS-API to parse its configuration and load any
+	 * mechanism plugins.
+	 */
+	{
+		gss_OID_set mechs;
+		OM_uint32 minor_status;
+		gss_indicate_mechs(&minor_status, &mechs);
+		gss_release_oid_set(&minor_status, &mechs);
+	}
+#endif
+#endif
+
+	/*
 	 * If not in debugging mode, not started from inetd and not already
 	 * daemonized (eg re-exec via SIGHUP), disconnect from the controlling
 	 * terminal, and fork.  The original process exits.
@@ -1687,6 +1718,10 @@ main(int ac, char **av)
 	/* Reinitialize the log (because of the fork above). */
 	log_init(__progname, options.log_level, options.log_facility, log_stderr);
 
+ 	/* Avoid killing the process in high-pressure swapping environments. */
+ 	if (!inetd_flag && madvise(NULL, 0, MADV_PROTECT) != 0)
+ 		debug("madvise(): %.200s", strerror(errno));
+
 	/*
 	 * Chdir to the root directory so that the current disk can be
 	 * unmounted if desired.
