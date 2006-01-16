--- growisofs.c_old	Mon Jan 16 06:09:41 2006
+++ growisofs.c	Mon Jan 16 12:02:04 2006
@@ -2194,7 +2194,9 @@
     nice(-20);
     /* I'd rather do it right after I allocate ring buffer and fire off
      * threads, but I'll be running without extra privileges by then:-( */
+#if !defined(__FreeBSD__) || __FreeBSD__ >= 5
     mlockall(MCL_CURRENT|MCL_FUTURE);
+#endif
 #endif
 
     mkisofs_argv = malloc ((argc+3)*sizeof(char *));
