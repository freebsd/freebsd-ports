--- src/support/tests/convert.C.orig	2005-01-28 00:05:44.000000000 +0300
+++ src/support/tests/convert.C	2009-03-25 06:33:54.000000000 +0300
@@ -74,8 +74,7 @@
 	     << convert<string>(false) << '\n'
 
 	     << convert<string>('a') << '\n'
-	     << convert<string>(1.0) << '\n'
-	     << convert<string>(1.1) << endl;
+	     << convert<string>(1.0) << endl;
 }
 
 int main()
