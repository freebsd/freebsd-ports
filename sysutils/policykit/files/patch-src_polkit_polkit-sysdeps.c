--- src/polkit/polkit-sysdeps.c.orig	2008-04-08 12:23:22.000000000 -0400
+++ src/polkit/polkit-sysdeps.c	2008-04-18 01:03:41.000000000 -0400
@@ -51,7 +51,7 @@
 #else
 #include <procfs.h>
 #endif
-#else
+#elif defined(HAVE_INOTIFY)
 #include <sys/inotify.h>
 #endif
 #include <syslog.h>
@@ -106,7 +106,11 @@ polkit_sysdeps_get_start_time_for_pid (p
         }
         start_time = (unsigned long long) (info.pr_start.tv_sec);
 #else
+#ifdef __FreeBSD__
+	filename = kit_strdup_printf ("/proc/%d/status", pid);
+#else
         filename = kit_strdup_printf ("/proc/%d/stat", pid);
+#endif
         if (filename == NULL) {
                 errno = ENOMEM;
                 goto out;
@@ -117,6 +121,36 @@ polkit_sysdeps_get_start_time_for_pid (p
                 goto out;
         }
 
+#ifdef __FreeBSD__
+        tokens = kit_strsplit (contents, ' ', &num_tokens);
+        if (tokens == NULL)
+                goto out;
+        if (num_tokens < 8) {
+                kit_strfreev (tokens);
+                goto out;
+        }
+
+        p = kit_strdup (tokens[7]);
+        kit_strfreev (tokens);
+
+        tokens = kit_strsplit (p, ',', &num_tokens);
+        kit_free (p);
+        if (tokens == NULL)
+                goto out;
+        if (num_tokens >= 1) {
+                start_time = strtoll (tokens[0], &endp, 10);
+                if (endp == tokens[0]) {
+                        kit_strfreev (tokens);
+                        goto out;
+                }
+        } else {
+                kit_strfreev (tokens);
+                goto out;
+        }
+
+        kit_strfreev (tokens);
+#else
+
         /* start time is the 19th token after the '(process name)' entry */
 
         p = strchr (contents, ')');
@@ -143,6 +177,7 @@ polkit_sysdeps_get_start_time_for_pid (p
 
         kit_strfreev (tokens);
 #endif
+#endif
 
 out:
 #ifndef HAVE_SOLARIS
@@ -235,7 +270,11 @@ polkit_sysdeps_get_exe_for_pid (pid_t pi
         ret = strlen (info.pr_psargs);
         strncpy (out_buf, info.pr_psargs, ret);
 #else
+#ifdef __FreeBSD__
+	snprintf (proc_name, sizeof (proc_name), "/proc/%d/file", pid);
+#else
         snprintf (proc_name, sizeof (proc_name), "/proc/%d/exe", pid);
+#endif
         ret = readlink (proc_name, out_buf, buf_size - 1);
         if (ret == -1) {
                 strncpy (out_buf, "(unknown)", buf_size);
