--- par.c.orig	2025-01-24 19:16:10 UTC
+++ par.c
@@ -21,6 +21,9 @@ This is ANSI C code (C89).
 #include <stdlib.h>
 #include <string.h>
 
+#include <sys/capsicum.h>
+#include <errno.h>
+
 #undef NULL
 #define NULL ((void *) 0)
 
@@ -724,6 +727,11 @@ int main(int argc, const char * const *argv)
   errmsg_t errmsg = { '\0' };
   lineprop *props = NULL, *firstprop, *nextprop;
   FILE *errout;
+
+  if (cap_enter() == -1 && errno != ENOSYS) {
+    strcpy(errmsg, "unable to enter sandbox\n");
+    goto parcleanup;
+  }
 
 /* Set the current locale from the environment: */
 
