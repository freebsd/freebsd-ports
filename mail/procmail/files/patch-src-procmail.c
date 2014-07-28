--- src/procmail.c.bak	Tue Sep 11 08:59:14 2001
+++ src/procmail.c	Sun Aug  3 05:34:55 2003
@@ -652,7 +652,7 @@
 	      nrcond= -1;
 	   if(tolock)		 /* clear temporary buffer for lockfile name */
 	      free(tolock);
-	   for(i=maxindex(flags);i;i--)			  /* clear the flags */
+	   for(i=maxindex(flags);i>=0;i--)                   /* clear the flags */
 	      flags[i]=0;
 	   for(tolock=0,locknext=0;;)
 	    { chp=skpspace(chp);
