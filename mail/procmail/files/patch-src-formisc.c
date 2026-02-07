--- src/formisc.c.orig	2001-06-29 10:20:45.000000000 +0800
+++ src/formisc.c	2014-09-12 00:58:12.989105253 +0800
@@ -84,12 +84,11 @@
 	case '"':*target++=delim='"';start++;
       }
      ;{ int i;
-	do
+	while(*start)
 	   if((i= *target++= *start++)==delim)	 /* corresponding delimiter? */
 	      break;
 	   else if(i=='\\'&&*start)		    /* skip quoted character */
 	      *target++= *start++;
-	while(*start);						/* anything? */
       }
      hitspc=2;
    }
@@ -104,7 +103,7 @@
 }
 							    /* append to buf */
 void loadbuf(text,len)const char*const text;const size_t len;
-{ if(buffilled+len>buflen)			  /* buf can't hold the text */
+{ while(buffilled+len>buflen)			  /* buf can't hold the text */
      buf=realloc(buf,buflen+=Bsize);
   tmemmove(buf+buffilled,text,len);buffilled+=len;
 }
