--- kernel/alloc.c.orig	Sat Mar 15 15:29:43 2003
+++ kernel/alloc.c	Thu Dec  9 03:31:56 2004
@@ -79,6 +79,9 @@
 #    undef real_free
 #    define real_free our_free16
 
+
+#  elif defined(__FreeBSD__)
+     p = malloc(n);
 #  elif defined(HAVE_MEMALIGN)
      p = memalign(MIN_ALIGNMENT, n);
 
