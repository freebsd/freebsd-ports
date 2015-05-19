Patch imported from Debian (Thibaut Paumard)
Fixes crash at startup

--- play/unix/slinks.c.orig	2015-05-19 17:19:00 UTC
+++ play/unix/slinks.c
@@ -101,7 +101,7 @@ u_find_exe(const char *argv0)
       }
       if (wkspc[j-1] == '/') s = 0;
       else s = 1, wkspc[j] = '/';
-      for (; j<k+i && j+s<P_WKSIZ ; j++) wkspc[j+s] = argv0[j-k];
+      for (; j<k+i+1 && j+s<P_WKSIZ ; j++) wkspc[j+s] = argv0[j-k];
       if (u_executable_file(wkspc) >= 0) break;
       k = 0;
       c = path[0];
