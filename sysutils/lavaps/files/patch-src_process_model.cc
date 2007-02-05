--- src/process_model.cc.orig	Tue Feb  6 00:59:53 2007
+++ src/process_model.cc	Tue Feb  6 01:00:42 2007
@@ -86,7 +86,7 @@
 void
 process_model::dump()
 {
-	cout << int(this) << " "<< pid_ << " " << uid_ << " " << cmd_.c_str() << " " <<
+	cout << size_t(this) << " "<< pid_ << " " << uid_ << " " << cmd_.c_str() << " " <<
 		endl;
 }
 
