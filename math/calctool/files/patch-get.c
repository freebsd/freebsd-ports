--- ./get.c.orig	1990-02-16 00:28:39.000000000 +0100
+++ ./get.c	2012-08-24 12:54:31.377915039 +0200
@@ -157,6 +157,7 @@
 }
 
 
+void
 get_helpfile(helpname)     /* Open helpfile if present. */
 char *helpname ;
 {
@@ -188,6 +189,7 @@
 }
 
 
+void
 get_rcfile(name)          /* Read .calctoolrc file. */
 char *name ;
 {
@@ -281,6 +283,7 @@
 }
 
 
+void
 read_rcfiles()   /* Read .calctoolrc's from home and current directories. */
 {
   char *home ;            /* Pathname for users home directory. */
