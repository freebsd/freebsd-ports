--- src/ov-grad.cc-orig	2012-03-30 23:31:24.000000000 +0000
+++ src/ov-grad.cc	2012-03-30 23:31:56.000000000 +0000
@@ -71,10 +71,10 @@
 
 void octave_gradient::print (std::ostream& os, bool pr_as_read_syntax) const 
 {
-	x ().print_with_name (os, "value", true);
+	x ().print_with_name (os, "value");
 	// print (partial) derivative(s),
 	// following convention i-th row = nabla(x_i)T
-	jacobian ().print_with_name (os, "(partial) derivative(s)", true);
+	jacobian ().print_with_name (os, "(partial) derivative(s)");
 }
 
 octave_value_list octave_gradient::dotref (const octave_value_list& idx) 
