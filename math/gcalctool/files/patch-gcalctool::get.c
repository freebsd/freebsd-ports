--- gcalctool/get.c.orig	Thu Dec 25 00:15:16 2003
+++ gcalctool/get.c	Thu Dec 25 00:22:50 2003
@@ -242,6 +242,7 @@
 init_vars()    /* Setup default values for various variables. */
 {
     int acc, i, n, size;
+    char *loc_radix;
 
     v->accuracy      = 9;      /* Initial accuracy. */
     v->show_zeroes   = FALSE;  /* Don't show trailing zeroes. */
@@ -264,6 +265,8 @@
 
     read_str(&v->iconlabel, _("calculator"));  /* Default icon label. */
 
+    loc_radix = v->radix;
+    v->radix = ".";
     MPstr_to_num("0.621", DEC, v->MPcon_vals[0]);  /* kms/hr <=> miles/hr. */
     MPstr_to_num("1.4142135623", DEC, v->MPcon_vals[1]);  /* square root of 2 */
     MPstr_to_num("2.7182818284", DEC, v->MPcon_vals[2]);  /* e */
@@ -274,6 +277,7 @@
     MPstr_to_num("0.0353", DEC, v->MPcon_vals[7]);  /* grams <=> ounce. */
     MPstr_to_num("0.948",  DEC, v->MPcon_vals[8]);  /* Kjoules <=> BTU's. */
     MPstr_to_num("0.0610", DEC, v->MPcon_vals[9]);  /* cms3 <=> inches3. */
+    v->radix = loc_radix;
 
     n = 0;
     for (i = 0; i < MAXREGS; i++) {
