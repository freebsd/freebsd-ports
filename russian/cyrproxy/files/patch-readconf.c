--- readconf.c.orig	Wed Sep  3 18:51:28 2003
+++ readconf.c	Wed Sep  3 18:51:40 2003
@@ -648,7 +648,7 @@
 	  retval=NULL;							\
 	  while(list!=NULL)						\
 	    {								\
-	      if(list->##fieldn == compval)				\
+	      if((list->##fieldn) == compval)				\
 		retval=list;						\
 	      list=list->chain;						\
 	    }								\
