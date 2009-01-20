--- patch-modules__gui__qt4__qt4.cpp begins here ---
diff -up vlc-0.9.8a/modules/gui/qt4/qt4.cpp.embedded vlc-0.9.8a/modules/gui/qt4/qt4.cpp
--- modules/gui/qt4/qt4.cpp.embedded	2008-12-05 02:27:20.000000000 +0100
+++ modules/gui/qt4/qt4.cpp	2008-12-05 02:27:27.000000000 +0100
@@ -213,7 +213,7 @@ vlc_module_begin();
 
         set_callbacks( OpenDialogs, Close );
 
-#if 0
+#if 1
     add_submodule();
         set_capability( "vout window", 50 );
         set_callbacks( WindowOpen, WindowClose );
--- patch-modules__gui__qt4__qt4.cpp ends here ---
