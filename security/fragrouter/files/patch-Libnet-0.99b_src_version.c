--- Libnet-0.99b/src/version.c.orig	2022-11-08 17:22:34 UTC
+++ Libnet-0.99b/src/version.c
@@ -44,5 +44,5 @@ __print_vers(void)
     /*
      *  We don't check for error cos we really don't care.
      */
-    write(STDOUT_FILENO, banner, sizeof(banner - 1));
+    write(STDOUT_FILENO, banner, sizeof(banner) - 1);
 }
