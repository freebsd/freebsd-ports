--- Makefile.PL.orig	2014-11-06 23:22:21.312462152 +0900
+++ Makefile.PL	2014-11-06 23:24:03.092462770 +0900
@@ -280,6 +280,9 @@
 
     # removed or changed (1.x.x)
     qw/query_rest query_scan query_snip/,
+
+    # workaround
+    qw/selector_func proc_set_selector text_vprintf/,
   ); # end of %todo
 
   my %inout = (
@@ -437,6 +440,9 @@
       print $out $_, "\t", $extra{$_}, "\n";
     }
     print $out <<'TYPEMAP';
+grn_selector_func       T_OPAQUE_
+unsigned int *  T_OPAQUE_
+va_list T_OPAQUE_
 
 INPUT
 T_GRN_CTX
