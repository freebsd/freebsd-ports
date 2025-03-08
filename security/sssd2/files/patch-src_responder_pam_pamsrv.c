Can be removed in FreeBSD 14

--- src/responder/pam/pamsrv.c.orig	2026-01-14 15:01:42 UTC
+++ src/responder/pam/pamsrv.c
@@ -484,7 +484,11 @@ int main(int argc, const char *argv[])
      */
     sss_getenv(NULL, "LISTEN_PID", NULL, &env_listen_pid);
     sss_getenv(NULL, "LISTEN_FDS", NULL, &env_listen_fds);
+#ifdef HAVE_CLEARENV
     ret = clearenv();
+#else
+    ret = 0;
+#endif
     if (ret != 0) {
         fprintf(stderr, "Failed to clear env.\n");
         return 1;
