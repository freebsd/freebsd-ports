--- JIT/Compiler.pm~	Fri May  7 12:58:37 2004
+++ JIT/Compiler.pm	Fri May  7 12:58:39 2004
@@ -87,6 +87,18 @@
 use Inline C => Config => OPTIMIZE => "$optimize", DIRECTORY => "$self->{package_dir}" $inline_debug;
 use Inline C => <<'CODE_END';
 
+#ifndef SvPV_nolen
+#   define SvPV_nolen(sv) ((SvFLAGS(sv) & (SVf_POK)) == SVf_POK ? SvPVX(sv) : sv_2pv_nolen(sv))
+    static char *
+    sv_2pv_nolen(register SV *sv)
+    {   
+        STRLEN n_a;
+        return sv_2pv(sv, &n_a);
+    }
+#endif
+
+#define get_hv(name,create) perl_get_hv(name,create)
+
 END
 
   # print out code
