--- setup.ml.orig	2014-04-26 21:42:25.000000000 +0200
+++ setup.ml	2014-04-26 21:42:34.000000000 +0200
@@ -6679,7 +6679,7 @@
             {
                pre_command = [(OASISExpr.EBool true, None)];
                post_command =
-                 [(OASISExpr.EBool true, Some (("make", ["post-conf"])))]
+                 [(OASISExpr.EBool true, Some (("gmake", ["post-conf"])))]
             };
           build_type = (`Build, "ocamlbuild", Some "0.4");
           build_custom =
@@ -7856,7 +7856,7 @@
                            (OASISExpr.EFlag "docs", true)
                         ];
                       doc_install = [(OASISExpr.EBool true, true)];
-                      doc_install_dir = "$docdir/api";
+                      doc_install_dir = "$stagedir$docdir/api";
                       doc_title = "API reference for GSL";
                       doc_authors = [];
                       doc_abstract = None;
