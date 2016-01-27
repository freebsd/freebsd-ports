--- src/lsof.cpp.orig	2015-09-25 13:36:19.000000000 +0200
+++ src/lsof.cpp	2016-01-09 12:32:53.892273000 +0100
@@ -140,8 +140,9 @@
 
         void update_count(unsigned count)
         {
-            string s = static_cast<std::ostringstream&>(std::ostringstream() << count).str();
-            gtk_label_set_text(this->count, s.c_str());
+	    std::ostringstream ss;
+	    ss << count;;
+            gtk_label_set_text(this->count, ss.str().c_str());
         }
 
 
