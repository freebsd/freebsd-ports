--- src/readstat_variable.c.orig	2023-02-20 19:09:20 UTC
+++ src/readstat_variable.c
@@ -5,7 +5,7 @@ static readstat_value_t make_double_value(double dval)
 static readstat_value_t make_blank_value(void);
 static readstat_value_t make_double_value(double dval);
 
-static readstat_value_t make_blank_value() {
+static readstat_value_t make_blank_value(void) {
     readstat_value_t value = { .is_system_missing = 1, .v = { .double_value = NAN }, .type = READSTAT_TYPE_DOUBLE };
     return value;
 }
