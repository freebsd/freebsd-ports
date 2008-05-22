diff -Naur libqalculate/Number.cc libqalculate/Number.cc
--- libqalculate/Number.cc	2007-05-18 04:03:22.000000000 -0400
+++ libqalculate/Number.cc	2008-02-02 11:06:15.000000000 -0500
@@ -28,6 +28,7 @@
 
 using namespace cln;
 
+/*
 void cln::cl_abort() {
 	CALCULATOR->error(true, "CLN Error: see terminal output (probably too large or small floating point number)", NULL);
 	if(CALCULATOR->busy()) {
@@ -36,7 +37,7 @@
 		exit(0);
 	}
 }
-
+*/
 string printCL_I(cl_I integ, int base = 10, bool display_sign = true, BaseDisplay base_display = BASE_DISPLAY_NORMAL, bool lower_case = false) {
 	if(base == BASE_ROMAN_NUMERALS) {
 		if(!zerop(integ) && integ < 10000 && integ > -10000) {
