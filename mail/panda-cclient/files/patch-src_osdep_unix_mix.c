--- src/osdep/unix/mix.c.orig	2022-04-17 00:12:02 UTC
+++ src/osdep/unix/mix.c
@@ -123,7 +123,7 @@ long mix_rename (MAILSTREAM *stream,char *old,char *ne
 long mix_create (MAILSTREAM *stream,char *mailbox);
 long mix_delete (MAILSTREAM *stream,char *mailbox);
 long mix_rename (MAILSTREAM *stream,char *old,char *newname);
-int mix_rselect (struct direct *name);
+int mix_rselect (const struct direct *name);
 MAILSTREAM *mix_open (MAILSTREAM *stream);
 void mix_close (MAILSTREAM *stream,long options);
 void mix_abort (MAILSTREAM *stream);
@@ -138,8 +138,8 @@ long mix_expunge (MAILSTREAM *stream,char *sequence,lo
 long mix_ping (MAILSTREAM *stream);
 void mix_check (MAILSTREAM *stream);
 long mix_expunge (MAILSTREAM *stream,char *sequence,long options);
-int mix_select (struct direct *name);
-int mix_msgfsort (const void *d1,const void *d2);
+int mix_select (const struct direct *name);
+int mix_msgfsort (const struct direct **d1,const struct direct **d2);
 long mix_addset (SEARCHSET **set,unsigned long start,unsigned long size);
 long mix_burp (MAILSTREAM *stream,MIXBURP *burp,unsigned long *reclaimed);
 long mix_burp_check (SEARCHSET *set,size_t size,char *file);
@@ -585,7 +585,7 @@ long mix_rename (MAILSTREAM *stream,char *old,char *ne
  * Returns: T if mix file name, NIL otherwise
  */
 
-int mix_rselect (struct direct *name)
+int mix_rselect (const struct direct *name)
 {
   return mix_dirfmttest (name->d_name);
 }
@@ -1150,7 +1150,7 @@ long mix_expunge (MAILSTREAM *stream,char *sequence,lo
  * ".mix" with no suffix was used by experimental versions
  */
 
-int mix_select (struct direct *name)
+int mix_select (const struct direct *name)
 {
   char c,*s;
 				/* make sure name has prefix */
@@ -1169,10 +1169,10 @@ int mix_select (struct direct *name)
  * Returns: -1 if d1 < d2, 0 if d1 == d2, 1 d1 > d2
  */
 
-int mix_msgfsort (const void *d1,const void *d2)
+int mix_msgfsort (const struct direct **d1,const struct direct **d2)
 {
-  char *n1 = (*(struct direct **) d1)->d_name + sizeof (MIXNAME) - 1;
-  char *n2 = (*(struct direct **) d2)->d_name + sizeof (MIXNAME) - 1;
+  char *n1 = (*d1)->d_name + sizeof (MIXNAME) - 1;
+  char *n2 = (*d2)->d_name + sizeof (MIXNAME) - 1;
   return compare_ulong (*n1 ? strtoul (n1,NIL,16) : 0,
 			*n2 ? strtoul (n2,NIL,16) : 0);
 }
