--- nslcd/daemonize.c.orig	2022-10-11 18:31:44 UTC
+++ nslcd/daemonize.c
@@ -1,7 +1,7 @@
 /*
    daemoninze.c - functions for properly daemonising an application
 
-   Copyright (C) 2014-2015 Arthur de Jong
+   Copyright (C) 2014-2022 Arthur de Jong
 
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
@@ -43,15 +43,19 @@ void daemonize_closefds(void)
 
 void daemonize_closefds(void)
 {
-  int i;
   /* close all file descriptors (except stdin/out/err) */
+#ifdef HAVE_CLOSEFROM
+  closefrom(3);
+#else
+  int i;
   i = sysconf(_SC_OPEN_MAX) - 1;
   /* if the system does not have OPEN_MAX just close the first 32 and
      hope we closed enough */
   if (i < 0)
     i = 32;
-  for (; i > 3; i--)
+  for (; i > 2; i--)
     close(i);
+#endif
 }
 
 void daemonize_redirect_stdio(void)
