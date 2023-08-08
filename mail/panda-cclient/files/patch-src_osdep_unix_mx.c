--- src/osdep/unix/mx.c.orig	2022-04-17 00:12:02 UTC
+++ src/osdep/unix/mx.c
@@ -98,8 +98,8 @@ long mx_append_msg (MAILSTREAM *stream,char *flags,MES
 long mx_append_msg (MAILSTREAM *stream,char *flags,MESSAGECACHE *elt,
 		    STRING *st,SEARCHSET *set);
 
-int mx_select (struct direct *name);
-int mx_numsort (const void *d1,const void *d2);
+int mx_select (const struct direct *name);
+int mx_numsort (const struct direct **d1,const struct direct **d2);
 char *mx_file (char *dst,char *name);
 long mx_lockindex (MAILSTREAM *stream);
 void mx_unlockindex (MAILSTREAM *stream);
@@ -1110,7 +1110,7 @@ long mx_append_msg (MAILSTREAM *stream,char *flags,MES
  * Returns: T to use file name, NIL to skip it
  */
 
-int mx_select (struct direct *name)
+int mx_select (const struct direct *name)
 {
   char c;
   char *s = name->d_name;
@@ -1125,10 +1125,9 @@ int mx_select (struct direct *name)
  * Returns: negative if d1 < d2, 0 if d1 == d2, postive if d1 > d2
  */
 
-int mx_numsort (const void *d1,const void *d2)
+int mx_numsort (const struct direct **d1,const struct direct **d2)
 {
-  return atoi ((*(struct direct **) d1)->d_name) -
-    atoi ((*(struct direct **) d2)->d_name);
+  return atoi ((*d1)->d_name) - atoi ((*d2)->d_name);
 }
 
 
