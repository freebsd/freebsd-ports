--- contrib/fspscan.c.orig	2009-10-01 20:46:36 UTC
+++ contrib/fspscan.c
@@ -72,7 +72,7 @@ static void printhelp(int argc,char **ar
     exit(0);
 }
 
-static void fdclose(void)
+static void myfdclose(void)
 {
     close(myfd);
 }
@@ -150,7 +150,7 @@ int main(int argc,char **argv)
         else
 	    fprintf(logfile,"%0d...nada\n",remoteport);
         fflush(logfile);
-        fdclose();
+        myfdclose();
     }
     return 0;
 }
