--- src/osdep/unix/mh.c.orig	2022-04-17 00:12:02 UTC
+++ src/osdep/unix/mh.c
@@ -100,8 +100,8 @@ long mh_append (MAILSTREAM *stream,char *mailbox,appen
 	      long options);
 long mh_append (MAILSTREAM *stream,char *mailbox,append_t af,void *data);
 
-int mh_select (struct direct *name);
-int mh_numsort (const void *d1,const void *d2);
+int mh_select (const struct direct *name);
+int mh_numsort (const struct direct **d1,const struct direct **d2);
 char *mh_file (char *dst,char *name);
 long mh_canonicalize (char *pattern,char *ref,char *pat);
 void mh_setdate (char *file,MESSAGECACHE *elt);
@@ -1191,7 +1191,7 @@ long mh_append (MAILSTREAM *stream,char *mailbox,appen
  * Returns: T to use file name, NIL to skip it
  */
 
-int mh_select (struct direct *name)
+int mh_select (const struct direct *name)
 {
   char c;
   char *s = name->d_name;
@@ -1206,10 +1206,9 @@ int mh_select (struct direct *name)
  * Returns: negative if d1 < d2, 0 if d1 == d2, postive if d1 > d2
  */
 
-int mh_numsort (const void *d1,const void *d2)
+int mh_numsort (const struct direct **d1,const struct direct **d2)
 {
-  return atoi ((*(struct direct **) d1)->d_name) -
-    atoi ((*(struct direct **) d2)->d_name);
+  return atoi ((*d1)->d_name) - atoi ((*d2)->d_name);
 }
 
 
