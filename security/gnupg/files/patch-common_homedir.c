--- common/homedir.c.orig	2021-10-01 12:44:06 UTC
+++ common/homedir.c
@@ -68,7 +68,9 @@
  * text was read.  */
 #if __linux__
 # define MYPROC_SELF_EXE "/proc/self/exe"
-#else /* Assume *BSD*/
+#elif defined(__NetBSD__)
+# define MYPROC_SELF_EXE "/proc/curproc/exe"
+#else /* Assume other BSDs */
 # define MYPROC_SELF_EXE "/proc/curproc/file"
 #endif
 
@@ -495,13 +497,13 @@ unix_rootdir (int want_sysconfdir)
           if (nread < 0)
             {
               err = gpg_error_from_syserror ();
-              log_info ("error reading symlink '%s': %s\n",
-                        MYPROC_SELF_EXE, gpg_strerror (err));
               buffer[0] = 0;
               if ((name = getenv ("GNUPG_BUILD_ROOT")) && *name == '/')
                 {
                   /* Try a fallback for systems w/o a supported /proc
-                   * file system.  */
+                   * file system if we are running a regression test.  */
+                  log_info ("error reading symlink '%s': %s\n",
+                            MYPROC_SELF_EXE, gpg_strerror (err));
                   xfree  (buffer);
                   buffer = xstrconcat (name, "/bin/gpgconf", NULL);
                   log_info ("trying fallback '%s'\n", buffer);
