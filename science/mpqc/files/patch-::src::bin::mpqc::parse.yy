--- src/bin/mpqc/parse.yy.orig	Mon Nov 18 17:18:27 2002
+++ src/bin/mpqc/parse.yy	Mon Nov 18 17:18:43 2002
@@ -117,6 +117,7 @@
             ;
 
 molecule:       molecule_options_list atoms
+            ;
 
 atoms:          atoms atom
             |
@@ -124,6 +125,7 @@
 
 atom:           string string string string atom_options_list
                                                 { add_atom($1,$2,$3,$4); }
+            ;
 
 atom_options_list:
                 T_BEG_OPT atom_options T_END_OPT
