--- gcalctool/get.c.orig	Thu Nov 27 05:29:52 2003
+++ gcalctool/get.c	Sat Dec  6 17:50:52 2003
@@ -125,7 +125,6 @@
 {
     char *radix_char;
 
-    setlocale(LC_NUMERIC, "");
     radix_char = nl_langinfo(RADIXCHAR);
 
     return(radix_char[0]);
@@ -220,8 +219,9 @@
 {
     char *tsep_char;
 
-    setlocale(LC_NUMERIC, "");
     tsep_char = nl_langinfo(THOUSEP);
+    if (!*tsep_char)
+        return ' ';
 
     return(tsep_char[0]);
 }
@@ -231,6 +231,7 @@
 init_vars()    /* Setup default values for various variables. */
 {
     int acc, i, n, size;
+    char lrc;
 
     v->accuracy      = 9;      /* Initial accuracy. */
     v->show_zeroes   = FALSE;  /* Don't show trailing zeroes. */
@@ -253,6 +254,8 @@
 
     read_str(&v->iconlabel, _("calculator"));  /* Default icon label. */
 
+    lrc = v->radix_char;
+    v->radix_char = '.';
     MPstr_to_num("0.621", DEC, v->MPcon_vals[0]);  /* kms/hr <=> miles/hr. */
     MPstr_to_num("1.4142135623", DEC, v->MPcon_vals[1]);  /* square root of 2 */
     MPstr_to_num("2.7182818284", DEC, v->MPcon_vals[2]);  /* e */
@@ -263,6 +266,7 @@
     MPstr_to_num("0.0353", DEC, v->MPcon_vals[7]);  /* grams <=> ounce. */
     MPstr_to_num("0.948",  DEC, v->MPcon_vals[8]);  /* Kjoules <=> BTU's. */
     MPstr_to_num("0.0610", DEC, v->MPcon_vals[9]);  /* cms3 <=> inches3. */
+    v->radix_char = lrc;
 
     n = 0;
     for (i = 0; i < MAXREGS; i++) {
