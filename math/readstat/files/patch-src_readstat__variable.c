--- src/readstat_variable.c.orig	2023-02-19 12:39:09 UTC
+++ src/readstat_variable.c
@@ -2,7 +2,7 @@
 #include <stdlib.h>
 #include "readstat.h"
 
-static readstat_value_t make_blank_value();
+static readstat_value_t make_blank_value(void);
 static readstat_value_t make_double_value(double dval);
 
 static readstat_value_t make_blank_value() {
