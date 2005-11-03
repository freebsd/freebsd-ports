--- libqalculate/Number.cc.orig	Thu Nov  3 18:27:14 2005
+++ libqalculate/Number.cc	Thu Nov  3 18:28:15 2005
@@ -2389,7 +2389,7 @@
 				if(po.indicate_infinite_series && !infinite_series) {
 					remainders.push_back(remainder);
 				}
-				remainder *= base;
+				remainder = remainder * base;
 				div = cln::truncate2(remainder, d);
 				remainder2 = div.remainder;
 				remainder = div.quotient;
@@ -2398,7 +2398,7 @@
 					started = !cln::zerop(remainder);
 				}
 				if(started) {
-					num *= base;	
+					num = num * base;	
 					num += remainder;
 				}
 				l10++;
@@ -2417,7 +2417,7 @@
 			}
 			remainders.clear();
 			if(!exact && !infinite_series) {
-				remainder *= base;
+				remainder = remainder * base;
 				div = cln::truncate2(remainder, d);
 				remainder2 = div.remainder;
 				remainder = div.quotient;
