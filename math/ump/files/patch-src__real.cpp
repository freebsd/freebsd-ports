--- src/real.cpp.orig
+++ src/real.cpp
@@ -764,7 +764,7 @@
 }
 
 // converts a Real to a fraction
-Real frac(const Real &val, int32 highest_bottom_value) throw(error_obj)
+Real frac(const Real &val, int32 highest_bottom_value = 1000) throw(error_obj)
 {
 	if( highest_bottom_value < 1 )
 		THROW_ERROR( ErrorType_Domain, _("Domain error: Value out of range.") );
