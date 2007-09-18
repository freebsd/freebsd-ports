--- smbd/sec_ctx.c.orig	Thu Mar  1 05:54:08 2007
+++ smbd/sec_ctx.c	Sat Sep 15 02:49:24 2007
@@ -5,7 +5,7 @@
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
-   the Free Software Foundation; either version 2 of the License, or
+   the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
@@ -14,8 +14,7 @@
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software
-   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
+   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
 #include "includes.h"
@@ -192,7 +191,7 @@
 
 	if (sec_ctx_stack_ndx == MAX_SEC_CTX_DEPTH) {
 		DEBUG(0, ("Security context stack overflow!\n"));
-		smb_panic("Security context stack overflow!\n");
+		smb_panic("Security context stack overflow!");
 	}
 
 	/* Store previous user context */
@@ -228,6 +227,73 @@
 }
 
 /****************************************************************************
+ Change UNIX security context. Calls panic if not successful so no return value.
+****************************************************************************/
+
+#ifndef HAVE_DARWIN_INITGROUPS
+
+/* Normal credential switch path. */
+
+static void set_unix_security_ctx(uid_t uid, gid_t gid, int ngroups, gid_t *groups)
+{
+	/* Start context switch */
+	gain_root();
+#ifdef HAVE_SETGROUPS
+	if (sys_setgroups(gid, ngroups, groups) != 0 && !non_root_mode()) {
+		smb_panic("sys_setgroups failed");
+	}
+#endif
+	become_id(uid, gid);
+	/* end context switch */
+}
+
+#else /* HAVE_DARWIN_INITGROUPS */
+
+/* The Darwin groups implementation is a little unusual. The list of
+* groups in the kernel credential is not exhaustive, but more like
+* a cache. The full group list is held in userspace and checked
+* dynamically.
+*
+* This is an optional mechanism, and setgroups(2) opts out
+* of it. That is, if you call setgroups, then the list of groups you
+* set are the only groups that are ever checked. This is not what we
+* want. We want to opt in to the dynamic resolution mechanism, so we
+* need to specify the uid of the user whose group list (cache) we are
+* setting.
+*
+* The Darwin rules are:
+*  1. Thou shalt setegid, initgroups and seteuid IN THAT ORDER
+*  2. Thou shalt not pass more that NGROUPS_MAX to initgroups
+*  3. Thou shalt leave the first entry in the groups list well alone
+*/
+
+#include <sys/syscall.h>
+
+static void set_unix_security_ctx(uid_t uid, gid_t gid, int ngroups, gid_t *groups)
+{
+	int max = groups_max();
+
+	/* Start context switch */
+	gain_root();
+
+	become_gid(gid);
+
+
+	if (syscall(SYS_initgroups, (ngroups > max) ? max : ngroups,
+			groups, uid) == -1 && !non_root_mode()) {
+		DEBUG(0, ("WARNING: failed to set group list "
+			"(%d groups) for UID %ld: %s\n",
+			ngroups, uid, strerror(errno)));
+		smb_panic("sys_setgroups failed");
+	}
+
+	become_uid(uid);
+	/* end context switch */
+}
+
+#endif /* HAVE_DARWIN_INITGROUPS */
+
+/****************************************************************************
  Set the current security context to a given user.
 ****************************************************************************/
 
@@ -243,11 +309,8 @@
 	debug_nt_user_token(DBGC_CLASS, 5, token);
 	debug_unix_user_token(DBGC_CLASS, 5, uid, gid, ngroups, groups);
 
-	gain_root();
-
-#ifdef HAVE_SETGROUPS
-	sys_setgroups(ngroups, groups);
-#endif
+	/* Change uid, gid and supplementary group list. */
+	set_unix_security_ctx(uid, gid, ngroups, groups);
 
 	ctx_p->ut.ngroups = ngroups;
 
@@ -277,8 +340,6 @@
 		ctx_p->token = NULL;
 	}
 
-	become_id(uid, gid);
-
 	ctx_p->ut.uid = uid;
 	ctx_p->ut.gid = gid;
 
@@ -315,7 +376,7 @@
 
 	if (sec_ctx_stack_ndx == 0) {
 		DEBUG(0, ("Security context stack underflow!\n"));
-		smb_panic("Security context stack underflow!\n");
+		smb_panic("Security context stack underflow!");
 	}
 
 	ctx_p = &sec_ctx_stack[sec_ctx_stack_ndx];
@@ -334,15 +395,13 @@
 
 	sec_ctx_stack_ndx--;
 
-	gain_root();
-
 	prev_ctx_p = &sec_ctx_stack[sec_ctx_stack_ndx];
 
-#ifdef HAVE_SETGROUPS
-	sys_setgroups(prev_ctx_p->ut.ngroups, prev_ctx_p->ut.groups);
-#endif
-
-	become_id(prev_ctx_p->ut.uid, prev_ctx_p->ut.gid);
+	/* Change uid, gid and supplementary group list. */
+	set_unix_security_ctx(prev_ctx_p->ut.uid,
+			prev_ctx_p->ut.gid,
+			prev_ctx_p->ut.ngroups,
+			prev_ctx_p->ut.groups);
 
 	/* Update current_user stuff */
 
