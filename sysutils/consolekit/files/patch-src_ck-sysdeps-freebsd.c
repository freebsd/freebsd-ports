--- src/ck-sysdeps-freebsd.c.orig        2008-01-23 09:30:44.000000000 -0500
+++ src/ck-sysdeps-freebsd.c        2008-02-06 22:50:57.000000000 -0500
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
 
@@ -318,38 +317,40 @@ gboolean
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
-
-        while ((t = getttyent ()) != NULL) {
-                if (t->ty_status & TTY_ON && strncmp (t->ty_name, "ttyv", 4) == 0)
+        g.gl_offs = 0;
+        glob ("/dev/ttyv*", GLOB_DOOFFS, NULL, &g);
+        for (i = 0; i < g.gl_pathc && g.gl_pathv[i] != NULL; i++) {
+                int fd;
+                char *cdev;
+
+                cdev = g.gl_pathv[i];
+                fd = open (cdev, O_RDONLY | O_NOCTTY);
+                if (fd > -1) {
+                        close (fd);
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
@@ -360,7 +361,12 @@ ck_get_console_device_for_num (guint num
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
@@ -370,6 +376,7 @@ ck_get_console_num_from_device (const ch
                                 guint      *num)
 {
         guint    n;
+        char     c;
         gboolean ret;
 
         n = 0;
@@ -379,7 +386,11 @@ ck_get_console_num_from_device (const ch
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
@@ -399,6 +410,7 @@ ck_get_active_console_num (int    consol
         gboolean ret;
         int      res;
         int      active;
+        char      ttyn;
 
         g_assert (console_fd != -1);
 
@@ -411,7 +423,12 @@ ck_get_active_console_num (int    consol
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
