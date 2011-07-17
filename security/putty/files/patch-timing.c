--- ../timing.c.orig	2011-07-17 13:40:59.000000000 +0200
+++ ../timing.c	2011-07-17 13:41:13.000000000 +0200
@@ -41,7 +41,7 @@
      * Failing that, compare on the other two fields, just so that
      * we don't get unwanted equality.
      */
-#ifdef __LCC__
+#if defined(__LCC__) || defined(__clang__)
     /* lcc won't let us compare function pointers. Legal, but annoying. */
     {
 	int c = memcmp(&a->fn, &b->fn, sizeof(a->fn));
