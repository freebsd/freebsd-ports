--- lib/sshsession/sshunixuser.c.orig	Wed Dec  3 14:17:21 2003
+++ lib/sshsession/sshunixuser.c	Mon Dec 29 20:57:45 2003
@@ -104,6 +104,10 @@
 
 #define SSH_DEBUG_MODULE "SshUnixUser"
 
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+#include <login_cap.h>
+#endif /* __FreeBSD && HAVE_LOGIN_CAP_H */
+
 extern char *crypt(const char *key, const char *salt);
 
 /* Group structure. */
@@ -1477,6 +1481,37 @@
   /* Set uid, gid, and groups. */
   if (getuid() == UID_ROOT || geteuid() == UID_ROOT)
     { 
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+      struct passwd *pw;
+
+      pw = getpwuid(ssh_user_uid(uc));
+      if (setusercontext(NULL, pw, ssh_user_uid(uc),
+                         LOGIN_SETALL & ~(LOGIN_SETLOGIN | LOGIN_SETUSER |
+                                          LOGIN_SETPATH | LOGIN_SETENV)) < 0)
+        {
+          SSH_DEBUG(2, ("setusercontext: unable to set user context"));
+          return FALSE;
+        }
+      endgrent();
+
+      /* chrooting at this point. */
+      if (chroot_dir)
+        {
+          if (chroot(chroot_dir) < 0)
+            {
+              ssh_warning("Chroot to '%s' failed: %s", chroot_dir,
+                          strerror(errno));
+              return FALSE;
+            }
+        }
+
+      if (setusercontext(NULL, pw, ssh_user_uid(uc), LOGIN_SETUSER) < 0)
+        {
+          SSH_DEBUG(2, ("setusercontext: unable to set user context"));
+          return FALSE;
+        }
+      endpwent();
+#else /* ! (__FreeBSD && HAVE_LOGIN_CAP_H) */
       if (setgid(ssh_user_gid(uc)) < 0)
         {
           SSH_DEBUG(2, ("setgid: %s", strerror(errno)));
@@ -1524,7 +1559,8 @@
         {
           if (chroot(chroot_dir) < 0)
             {
-              ssh_warning("Chroot to '%s' failed!", chroot_dir);
+              ssh_warning("Chroot to '%s' failed: %s", chroot_dir,
+                          strerror(errno));
               return FALSE;
             }
         }
@@ -1578,6 +1614,7 @@
           return FALSE;
         }
 #endif /* HAVE_SIA */
+#endif /* __FreeBSD && HAVE_LOGIN_CAP_H */
     }
   
 #ifdef KERBEROS
