--- src/pipes.c.bak	Tue Sep 11 08:58:44 2001
+++ src/pipes.c	Mon Nov 11 02:11:49 2002
@@ -194,7 +194,7 @@
      makeblock(&temp,Stdfilled);
      tmemmove(temp.p,Stdout,Stdfilled);
      readdyn(&temp,&Stdfilled,Stdfilled+backlen+1);
-     Stdout=realloc(Stdout,&Stdfilled+1);
+     Stdout=realloc(Stdout,Stdfilled+1);
      tmemmove(Stdout,temp.p,Stdfilled+1);
      freeblock(&temp);
      retStdout(Stdout,pwait&&pipw,!backblock);
