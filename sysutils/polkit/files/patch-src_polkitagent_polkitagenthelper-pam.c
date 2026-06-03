--- src/polkitagent/polkitagenthelper-pam.c.orig	2025-12-17 16:14:53 UTC
+++ src/polkitagent/polkitagenthelper-pam.c
@@ -38,7 +38,7 @@
 #    define SO_PEERPIDFD 0x404B
 #  elif defined(__sparc__)
 #    define SO_PEERPIDFD 0x0056
-#  else
+#  elif defined(__linux__)
 #    define SO_PEERPIDFD 77
 #  endif
 #endif
@@ -137,6 +137,7 @@ main (int argc, char *argv[])
       goto error;
     }
 
+#ifdef SO_PEERPIDFD
   /* We are socket activated and the socket has been set up as stdio/stdout, read user from it */
   if (argv[1] != NULL && strcmp (argv[1], "--socket-activated") == 0)
     {
@@ -177,6 +178,7 @@ main (int argc, char *argv[])
       uid = ucred.uid;
     }
   else
+#endif
     user_to_auth = argv[1];
 
   cookie = read_cookie (argc, argv);
