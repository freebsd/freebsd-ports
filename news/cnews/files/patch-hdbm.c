--- libc/hdbm.c.orig	1993-03-09 07:04:52.000000000 +0100
+++ libc/hdbm.c	2011-05-12 16:17:51.000000000 +0200
@@ -81,6 +81,7 @@
  * free all the memory associated with tbl, erase the pointers to it, and
  * invalidate tbl to prevent further use via other pointers to it.
  */
+void
 hdbmdestroy(tbl)
 register HASHTABLE *tbl;
 {
@@ -260,6 +261,7 @@
  * arguments.  hook is an attempt to allow side-effects and reentrancy at
  * the same time.
  */
+void
 hdbmwalk(tbl, nodefunc, hook)
 HASHTABLE *tbl;
 register int (*nodefunc)();
