--- init.c.orig	Wed Jul 24 10:41:29 2002
+++ init.c	Wed Apr 30 13:06:45 2003
@@ -45,7 +45,9 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
+#if __FreeBSD_version >= 500000
 #include <sys/utsname.h>
+#endif
 #include <errno.h>
 #include <sys/wait.h>
 
@@ -1707,7 +1709,11 @@
 void mutt_init (int skip_sys_rc, LIST *commands)
 {
   struct passwd *pw;
+#if __FreeBSD_version < 500000
+  char nodename[STRING];
+#else
   struct utsname utsname;
+#endif
   char *p, buffer[STRING], error[STRING];
   int i, default_rc = 0, need_pause = 0;
   BUFFER err;
@@ -1765,16 +1771,21 @@
 #endif
 
   /* And about the host... */
+#if __FreeBSD_version < 500000
+  gethostname(nodename, sizeof (nodename));
+#else
   uname (&utsname);
+  strfcpy (nodename, utsname.nodename, sizeof (nodename));
+#endif
   /* some systems report the FQDN instead of just the hostname */
-  if ((p = strchr (utsname.nodename, '.')))
+  if ((p = strchr (nodename, '.')))
   {
-    Hostname = mutt_substrdup (utsname.nodename, p);
+    Hostname = mutt_substrdup (nodename, p);
     p++;
     strfcpy (buffer, p, sizeof (buffer)); /* save the domain for below */
   }
   else
-    Hostname = safe_strdup (utsname.nodename);
+    Hostname = safe_strdup (nodename);
 
 #ifndef DOMAIN
 #define DOMAIN buffer
