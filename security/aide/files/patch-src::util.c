--- src/util.c.orig	Wed May 29 01:04:27 2002
+++ src/util.c	Tue Oct 29 04:03:55 2002
@@ -357,6 +357,7 @@
 }
 
 
+#if 0
 /* Like strstr but only do search for maximum of n chars.
    haystack does not have to be NULL terminated
    needle has to be NULL terminated. NULL in needle is not used in compare.
@@ -392,6 +393,7 @@
   /* If we get this far no match was found so we return NULL */
   return NULL;
 }
+#endif /* 0 */
 
 /* We need these dummy stubs to fool the linker into believing that
    we do not need them at link time */
