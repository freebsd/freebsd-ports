--- handlers.c.orig	2012-03-26 06:25:08 UTC
+++ handlers.c
@@ -34,7 +34,6 @@
 #include <signal.h>
 #include <assert.h>
 #include <setjmp.h>
-#include <alloca.h>
 #include <strings.h>            /*lint -esym(526,strcasecmp) */
 #include <string.h>
 #include <stdbool.h>
@@ -123,9 +122,9 @@ bool handler__set(globals_t * vars, char
         } else {
             /* there is a '=', value+1 points to value string. */
 
-            /* use strndupa() to copy the matchids into a new buffer */
+            /* use strndup() to copy the matchids into a new buffer */
             settings[block].matchids =
-                strndupa(argv[block + 1],
+                strndup(argv[block + 1],
                          (size_t) (settings[block].value++ - argv[block + 1]));
         }
 
@@ -161,7 +160,7 @@ bool handler__set(globals_t * vars, char
 
             /* remove any delay suffix from the value */
             settings[block].value =
-                strndupa(settings[block].value,
+                strndup(settings[block].value,
                          (size_t) (delay - settings[block].value));
         }                       /* if (strchr('/')) */
     }                           /* for(block...) */
@@ -207,7 +206,7 @@ bool handler__set(globals_t * vars, char
                 unsigned num = 0;
 
                 /* create local copy of the matchids for strtok() to modify */
-                lmatches = strdupa(settings[block].matchids);
+                lmatches = strdup(settings[block].matchids);
 
                 /* now seperate each match, spearated by commas */
                 while ((id = strtok(lmatches, ",")) != NULL) {
@@ -545,7 +544,7 @@ bool handler__dregion(globals_t * vars, 
     if (*argv[1] == '!') {
         invert = true;
         /* create a copy of the argument for strtok(), +1 to skip '!' */
-        block = strdupa(argv[1] + 1);
+        block = strdup(argv[1] + 1);
         
         /* check for lone '!' */
         if (*block == '\0') {
@@ -561,7 +560,7 @@ bool handler__dregion(globals_t * vars, 
         
     } else {
         invert = false;
-        block = strdupa(argv[1]);
+        block = strdup(argv[1]);
     }
 
     /* loop for every number specified, eg "1,2,3,4,5" */
