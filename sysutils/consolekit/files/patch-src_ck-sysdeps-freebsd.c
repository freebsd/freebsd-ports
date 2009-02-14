--- src/ck-sysdeps-freebsd.c.orig	2008-04-03 20:36:21.000000000 -0400
+++ src/ck-sysdeps-freebsd.c	2009-02-14 15:26:37.000000000 -0500
@@ -27,6 +27,7 @@
 #include <unistd.h>
 #include <string.h>
 #include <errno.h>
+#include <glob.h>
 #include <paths.h>
 #include <ttyent.h>
 #include <kvm.h>
@@ -202,7 +203,6 @@ ck_process_stat_new_for_unix_pid (pid_t 
                                   GError        **error)
 {
         gboolean       res;
-        GError        *local_error;
         CkProcessStat *proc;
 
         g_return_val_if_fail (pid > 1, FALSE);
@@ -217,7 +217,6 @@ ck_process_stat_new_for_unix_pid (pid_t 
         if (res) {
                 *stat = proc;
         } else {
-                g_propagate_error (error, local_error);
                 *stat = NULL;
         }
 
@@ -235,21 +234,25 @@ ck_unix_pid_get_env_hash (pid_t pid)
 {
         GHashTable       *hash;
         char            **penv;
+        char              errbuf[_POSIX2_LINE_MAX];
         kvm_t            *kd;
         struct kinfo_proc p;
         int               i;
 
-        kd = kvm_openfiles (_PATH_DEVNULL, _PATH_DEVNULL, NULL, O_RDONLY, NULL);
+        kd = kvm_openfiles (_PATH_DEVNULL, _PATH_DEVNULL, NULL, O_RDONLY, errbuf);
         if (kd == NULL) {
+                g_warning ("kvm_openfiles failed: %s", errbuf);
                 return NULL;
         }
 
         if (! get_kinfo_proc (pid, &p)) {
+                g_warning ("get_kinfo_proc failed: %s", g_strerror(errno));
                 return NULL;
         }
 
         penv = kvm_getenvv (kd, &p, 0);
         if (penv == NULL) {
+                g_warning ("kvm_getenvv failed");
                 return NULL;
         }
 
@@ -280,7 +283,7 @@ ck_unix_pid_get_env (pid_t       pid,
                      const char *var)
 {
         GHashTable *hash;
-        char       *val;
+        char       *val = NULL;
 
         /*
          * Would probably be more efficient to just loop through the
@@ -288,6 +291,8 @@ ck_unix_pid_get_env (pid_t       pid,
          * table, but this works for now.
          */
         hash = ck_unix_pid_get_env_hash (pid);
+        if (hash == NULL)
+                return val;
         val  = g_strdup (g_hash_table_lookup (hash, var));
         g_hash_table_destroy (hash);
 
@@ -327,38 +332,38 @@ gboolean
 ck_get_max_num_consoles (guint *num)
 {
         int      max_consoles;
-        int      res;
-        gboolean ret;
-        struct ttyent *t;
+        int      i;
+        glob_t   g;
 
-        ret = FALSE;
         max_consoles = 0;
 
-        res = setttyent ();
-        if (res == 0) {
-                goto done;
-        }
+        g.gl_offs = 0;
+        glob ("/dev/ttyv*", GLOB_DOOFFS | GLOB_NOSORT, NULL, &g);
+        for (i = 0; i < g.gl_pathc && g.gl_pathv[i] != NULL; i++) {
+                struct stat sb;
+                char *cdev;
 
-        while ((t = getttyent ()) != NULL) {
-                if (t->ty_status & TTY_ON && strncmp (t->ty_name, "ttyv", 4) == 0)
+                cdev = g.gl_pathv[i];
+                if (stat (cdev, &sb) > -1 && S_ISCHR (sb.st_mode)) {
                         max_consoles++;
+                } else {
+                        break;
+                }
         }
 
-        /* Increment one more so that all consoles are properly counted
+        globfree (&g);
+
+        /*
+         * Increment one more so that all consoles are properly counted
          * this is arguable a bug in vt_add_watches().
          */
         max_consoles++;
 
-        ret = TRUE;
-
-        endttyent ();
-
-done:
         if (num != NULL) {
                 *num = max_consoles;
         }
 
-        return ret;
+        return TRUE;
 }
 
 char *
@@ -369,7 +374,12 @@ ck_get_console_device_for_num (guint num
         /* The device number is always one less than the VT number. */
         num--;
 
-        device = g_strdup_printf ("/dev/ttyv%u", num);
+        if (num < 10)
+                device = g_strdup_printf ("/dev/ttyv%i", num);
+        else if (num < 32)
+                device = g_strdup_printf ("/dev/ttyv%c", num - 10 + 'a');
+        else
+                device = NULL;
 
         return device;
 }
@@ -379,6 +389,7 @@ ck_get_console_num_from_device (const ch
                                 guint      *num)
 {
         guint    n;
+        char     c;
         gboolean ret;
 
         n = 0;
@@ -388,7 +399,11 @@ ck_get_console_num_from_device (const ch
                 return FALSE;
         }
 
-        if (sscanf (device, "/dev/ttyv%u", &n) == 1) {
+        if (sscanf (device, "/dev/ttyv%c", &c) == 1) {
+                if (c < 58)
+                        n = c - 48;
+                else
+                        n = c - 'a' + 10;
                 /* The VT number is always one more than the device number. */
                 n++;
                 ret = TRUE;
@@ -408,6 +423,7 @@ ck_get_active_console_num (int    consol
         gboolean ret;
         int      res;
         int      active;
+        char      ttyn;
 
         g_assert (console_fd != -1);
 
@@ -420,7 +436,12 @@ ck_get_active_console_num (int    consol
                 goto out;
         }
 
-        g_debug ("Active VT is: %d (ttyv%d)", active, active - 1);
+        if (active - 1 < 10)
+                ttyn = active - 1 + '0';
+        else
+                ttyn = active - 11 + 'a';
+
+        g_debug ("Active VT is: %d (ttyv%c)", active, ttyn);
         ret = TRUE;
 
  out:
