--- Makefile.PL.orig	2013-10-24 16:00:49.000000000 +0900
+++ Makefile.PL	2013-10-24 16:08:32.000000000 +0900
@@ -13,9 +13,9 @@
 else
 {
     # assume some compatible Linux
-    $options{LD}   = "g++";
-    $options{CC}   = "g++";
-    $options{LIBS} = "-lstdc++ -losp";
+    $options{LD}   = "c++";
+    $options{CC}   = "c++";
+    $options{LIBS} = "-L%%LOCALBASE%%/lib -lstdc++ -losp";
 }
  WriteMakefile(

@@ -26,6 +26,10 @@
       Test::Exception => 0,
       File::Temp      => 0,
     },
+    PM		      => {
+      'lib/SGML/Parser/OpenSP.pm' => '$(INST_LIB)/SGML/Parser/OpenSP.pm',
+      'lib/SGML/Parser/OpenSP/Tools.pm' => '$(INST_LIB)/SGML/Parser/OpenSP/Tools.pm'
+    },
     ($] >= 5.005 ?
       (ABSTRACT_FROM  => 'lib/SGML/Parser/OpenSP.pm',
        AUTHOR         => 'Bjoern Hoehrmann <bjoern@hoehrmann.de>') : ()),
