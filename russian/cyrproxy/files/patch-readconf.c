--- readconf.c.orig	Sat May  3 18:57:22 1997
+++ readconf.c	Tue Oct 28 02:46:38 2003
@@ -648,7 +648,7 @@
 	  retval=NULL;							\
 	  while(list!=NULL)						\
 	    {								\
-	      if(list->##fieldn == compval)				\
+	      if(list->fieldn == compval)				\
 		retval=list;						\
 	      list=list->chain;						\
 	    }								\
