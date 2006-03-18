--- modules/timeplace.c.orig	Sun Feb 19 18:54:46 2006
+++ modules/timeplace.c	Sun Feb 19 19:07:05 2006
@@ -32,7 +32,21 @@
 #include "config.h"
 #endif
 
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+
 #include "module.h"
+
+struct cons_t {
+        int *tuples;
+        int tuplenum;
+        int ppb;        /* Periods per block */
+};
+
+static struct cons_t *con=NULL;
+static int connum=0;
+static int periods;
 
 int module_fitness(chromo **c, ext **e, slist **s)
 {
