--- src/gdome_cpp_smart/basic/GdomeSmartDOMDOMStringAux.cc.orig	Wed Jul 10 13:54:33 2002
+++ src/gdome_cpp_smart/basic/GdomeSmartDOMDOMStringAux.cc	Wed Jul 10 13:55:19 2002
@@ -47,7 +47,7 @@
 	int           save_width = o.width(4);
 	o << ch;
 	o.fill(save_fill);
-	o.setf(save_flags);
+	o.setf((std::_Ios_Fmtflags)save_flags);
 	o.width(save_width);
       }
     }
