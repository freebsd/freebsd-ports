--- nslcd/invalidator.c.orig	2021-11-15 19:40:49 UTC
+++ nslcd/invalidator.c
@@ -1,7 +1,7 @@
 /*
    invalidator.c - functions for invalidating external caches
 
-   Copyright (C) 2013-2014 Arthur de Jong
+   Copyright (C) 2013-2022 Arthur de Jong
 
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
@@ -97,6 +97,9 @@ static void exec_invalidate(const char *db)
   {
     case 0: /* we are the child */
       /* close all file descriptors */
+#ifdef HAVE_CLOSEFROM
+      closefrom(0);
+#else
       i = sysconf(_SC_OPEN_MAX) - 1;
       /* if the system does not have OPEN_MAX just close the first 32 and
          hope we have closed enough */
@@ -104,6 +107,7 @@ static void exec_invalidate(const char *db)
         i = 32;
       for (; i >= 0; i--)
         close(i);
+#endif
       /* execute command */
 #ifdef HAVE_EXECVPE
       execvpe(argv[0], argv, newenviron);
