
$FreeBSD$

--- ext/amatch.c.orig
+++ ext/amatch.c
@@ -86,9 +86,10 @@
     if (TYPE(strings) == T_STRING) {                                \
         return match_function(amatch, strings);                     \
     } else {                                                        \
-        Check_Type(strings, T_ARRAY);                               \
         int i;                                                      \
-        VALUE result = rb_ary_new2(RARRAY(strings)->len);           \
+	VALUE result;						    \
+        Check_Type(strings, T_ARRAY);                               \
+        result = rb_ary_new2(RARRAY(strings)->len);           \
         for (i = 0; i < RARRAY(strings)->len; i++) {                \
             VALUE string = rb_ary_entry(strings, i);                \
             if (TYPE(string) != T_STRING) {                         \
@@ -949,8 +950,8 @@
     if (TYPE(strings) == T_STRING) {
         result = PairDistance_match(amatch, strings, regexp, use_regexp);
     } else {
-        Check_Type(strings, T_ARRAY);
         int i;
+        Check_Type(strings, T_ARRAY);
         result = rb_ary_new2(RARRAY(strings)->len);
         for (i = 0; i < RARRAY(strings)->len; i++) {
             VALUE string = rb_ary_entry(strings, i);
