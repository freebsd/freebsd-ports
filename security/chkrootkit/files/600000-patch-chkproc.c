--- chkproc.c.orig	Fri Nov 24 12:03:25 2006
+++ chkproc.c	Fri Nov 24 12:04:43 2006
@@ -334,18 +334,6 @@
          }
 #endif
       }
-      else 
-      {
-         errno = 0;
-         getpriority(PRIO_PROCESS, i);
-         if (!errno)
-         {
-            retdir++;
-            if (verbose)
-	       printf ("PID %5d(%s): not in getpriority readdir output\n", i, buf);
-	 }
-      }
-
    }
    if (retdir)
       printf("You have % 5d process hidden for readdir command\n", retdir);
