--- src/readstat_variable.c.orig	2020-08-25 16:29:50 UTC
+++ src/readstat_variable.c
@@ -2,10 +2,10 @@
 #include <stdlib.h>
 #include "readstat.h"
 
-static readstat_value_t make_blank_value();
+static readstat_value_t make_blank_value(void);
 static readstat_value_t make_double_value(double dval);
 
-static readstat_value_t make_blank_value() {
+static readstat_value_t make_blank_value(void) {
     readstat_value_t value = { .is_system_missing = 1, .v = { .double_value = NAN }, .type = READSTAT_TYPE_DOUBLE };
     return value;
 }
