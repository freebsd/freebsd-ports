--- hashtab.c.orig	2011-01-03 05:51:12.000000000 +0100
+++ hashtab.c	2011-02-02 07:26:44.000000000 +0100
@@ -418,7 +418,7 @@
    if (nptr!=NULL)
    {
       if (type==OBJ_GRP) nptr->flag=OBJ_GRP;
-      else if (isinglist(hidden_urls,nptr->string)!=NULL)
+      else if (isinlist(hidden_urls,nptr->string)!=NULL)
                          nptr->flag=OBJ_HIDE;
    }
    return nptr==NULL;
