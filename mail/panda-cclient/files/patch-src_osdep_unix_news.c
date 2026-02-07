--- src/osdep/unix/news.c.orig	2022-04-17 00:12:02 UTC
+++ src/osdep/unix/news.c
@@ -76,8 +76,8 @@ MAILSTREAM *news_open (MAILSTREAM *stream);
 long news_delete (MAILSTREAM *stream,char *mailbox);
 long news_rename (MAILSTREAM *stream,char *old,char *newname);
 MAILSTREAM *news_open (MAILSTREAM *stream);
-int news_select (struct direct *name);
-int news_numsort (const void *d1,const void *d2);
+int news_select (const struct direct *name);
+int news_numsort (const struct direct **d1,const struct direct **d2);
 void news_close (MAILSTREAM *stream,long options);
 void news_fast (MAILSTREAM *stream,char *sequence,long flags);
 void news_flags (MAILSTREAM *stream,char *sequence,long flags);
@@ -402,7 +402,7 @@ MAILSTREAM *news_open (MAILSTREAM *stream)
  * Returns: T to use file name, NIL to skip it
  */
 
-int news_select (struct direct *name)
+int news_select (const struct direct *name)
 {
   char c;
   char *s = name->d_name;
@@ -417,10 +417,9 @@ int news_select (struct direct *name)
  * Returns: negative if d1 < d2, 0 if d1 == d2, postive if d1 > d2
  */
 
-int news_numsort (const void *d1,const void *d2)
+int news_numsort (const struct direct **d1,const struct direct **d2)
 {
-  return atoi ((*(struct direct **) d1)->d_name) -
-    atoi ((*(struct direct **) d2)->d_name);
+  return atoi ((*d1)->d_name) - atoi ((*d2)->d_name);
 }
 
 
