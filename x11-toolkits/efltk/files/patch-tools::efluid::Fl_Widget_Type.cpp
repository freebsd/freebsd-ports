--- tools/efluid/Fl_Widget_Type.cpp.orig	Sat Feb 28 06:03:16 2004
+++ tools/efluid/Fl_Widget_Type.cpp	Sat Feb 28 06:05:38 2004
@@ -1890,7 +1890,7 @@
 
     if (member_of && !callback().empty() && !is_name(callback())) {
         const char* cn = callback_name();
-        const char* ut = user_data_type().empty() ? "void*" : user_data_type();
+        const char* ut = user_data_type().empty() ? Fl_String("void*") : user_data_type();
         write_public(0);
         write_h("%sinline void %s_i(%s*, %s);\n", indent(), cn, subclass, ut);
         write_h("%sstatic void %s(%s*, %s);\n", indent(), cn, subclass, ut);
