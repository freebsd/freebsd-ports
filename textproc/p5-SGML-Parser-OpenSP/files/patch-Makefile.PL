--- Makefile.PL.orig	2010-02-07 23:33:39.000000000 +0900
+++ Makefile.PL	2010-02-07 23:34:03.000000000 +0900
@@ -15,7 +15,7 @@
     # assume some compatible Linux
     $options{LD}   = "g++";
     $options{CC}   = "g++";
-    $options{LIBS} = "-lstdc++ -losp";
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
