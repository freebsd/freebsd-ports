commit 239e8c98636a7578cc67a6f9d54d14c71b095e36
Author: Kyle Evans <kevans@FreeBSD.org>
Date:   Sat Aug 9 11:01:57 2025 -0500

    ssh: sshd-session: properly save off the privileged gid
    
    Current and traditional FreeBSD behavior means that getegid() here is
    the first element in the prior setgroups() call, if any, so we may
    inadvertently wipe out our rgid with the unprivileged gid.  This is
    rendered somewhat harmless by the fact that we're losing the privileged
    gid -- we'll still regain it as the egid in restore_uid() later by way
    of restoring saved_egroups, rather than by intentionally restoring it
    from getgid().
    
    This will be promptly reverted if we can get setgroups(2)/getgroups(2)
    changed in FreeBSD 15.0, but it seemed wise to get this technically
    correct for previous branches.
    
    Reviewed by:    jlduran
    Differential Revision:  https://reviews.freebsd.org/D51753

diff --git uidswap.c uidswap.c
index 6ed3024d0180..0143f4994611 100644
--- uidswap.c
+++ uidswap.c
@@ -14,6 +14,10 @@
 
 #include "includes.h"
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <assert.h>
+#endif
 #include <errno.h>
 #include <pwd.h>
 #include <string.h>
@@ -121,8 +124,20 @@ temporarily_use_uid(struct passwd *pw)
 		fatal("setgroups: %.100s", strerror(errno));
 #ifndef SAVED_IDS_WORK_WITH_SETEUID
 	/* Propagate the privileged gid to all of our gids. */
+#if defined(__FreeBSD__) && __FreeBSD_version < 1500061
+	/*
+	 * FreeBSD traditionally includes the egid as the first element.  If we
+	 * use getegid() here then we effectively propagate user_groups[0],
+	 * which is probably pw->pw_gid.  Fix it to work as intended by using
+	 * the egid we already have stashed off.
+	 */
+	assert(saved_egroupslen > 0);
+	if (setgid(saved_egroups[0]) == -1)
+		debug("setgid %u: %.100s", (u_int) saved_egroups[0], strerror(errno));
+#else
 	if (setgid(getegid()) == -1)
 		debug("setgid %u: %.100s", (u_int) getegid(), strerror(errno));
+#endif
 	/* Propagate the privileged uid to all of our uids. */
 	if (setuid(geteuid()) == -1)
 		debug("setuid %u: %.100s", (u_int) geteuid(), strerror(errno));
