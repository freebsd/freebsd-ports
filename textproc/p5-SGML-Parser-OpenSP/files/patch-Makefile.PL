--- Makefile.PL.orig	2007-07-29 03:05:27.000000000 +0800
+++ Makefile.PL	2007-07-29 03:06:38.000000000 +0800
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
