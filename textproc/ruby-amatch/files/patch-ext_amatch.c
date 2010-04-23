--- ext/amatch.c.orig	2009-08-26 02:35:48.000000000 +0200
+++ ext/amatch.c	2010-04-23 12:48:35.000000000 +0200
@@ -89,9 +89,10 @@
     if (TYPE(strings) == T_STRING) {                                \
         return match_function(amatch, strings);                     \
     } else {                                                        \
-        Check_Type(strings, T_ARRAY);                               \
         int i;                                                      \
-        VALUE result = rb_ary_new2(RARRAY_LEN(strings));            \
+        VALUE result;                                               \
+        Check_Type(strings, T_ARRAY);                               \
+        result = rb_ary_new2(RARRAY_LEN(strings));                  \
         for (i = 0; i < RARRAY_LEN(strings); i++) {                 \
             VALUE string = rb_ary_entry(strings, i);                \
             if (TYPE(string) != T_STRING) {                         \
@@ -1098,8 +1099,8 @@
     if (TYPE(strings) == T_STRING) {
         result = PairDistance_match(amatch, strings, regexp, use_regexp);
     } else {
-        Check_Type(strings, T_ARRAY);
         int i;
+        Check_Type(strings, T_ARRAY);
         result = rb_ary_new2(RARRAY_LEN(strings));
         for (i = 0; i < RARRAY_LEN(strings); i++) {
             VALUE string = rb_ary_entry(strings, i);
