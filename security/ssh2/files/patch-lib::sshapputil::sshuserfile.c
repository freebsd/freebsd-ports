--- lib/sshapputil/sshuserfile.c.orig	Wed Dec  3 14:17:21 2003
+++ lib/sshapputil/sshuserfile.c	Mon Dec 29 20:58:27 2003
@@ -742,12 +742,13 @@
   if (uid != geteuid() || uid != getuid())
     {
 #if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
-      struct passwd * pw = getpwuid(uid);
-      login_cap_t * lc = login_getuserclass(pw);
-      if (setusercontext(lc, pw, uid,
+      struct passwd *pw;
+
+      pw = getpwuid(uid);
+      if (setusercontext(NULL, pw, uid,
                          LOGIN_SETALL & ~(LOGIN_SETLOGIN | LOGIN_SETPATH |
                                           LOGIN_SETENV)) < 0)
-        ssh_fatal("setusercontext: %s", strerror(errno));
+        ssh_fatal("setusercontext: unable to set user context");
 #else /* ! (__FreeBSD && HAVE_LOGIN_CAP_H) */
       if (setgid(gid) < 0)
         ssh_fatal("setgid: %s", strerror(errno));
