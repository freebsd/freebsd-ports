--- css.c.orig	Tue Mar 28 10:25:11 2006
+++ css.c	Tue Mar 28 10:25:41 2006
@@ -40,6 +40,7 @@
       while(fgets(buf,MAXLEN,fp_in)!=NULL)
          fputs(buf,fp_ou);
       fputs("</style>\n",fp_ou);
+      fclose(fp_in);
       return;
    }
 
