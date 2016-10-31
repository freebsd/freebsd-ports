--- setup.ml.orig	2015-11-18 15:14:41 UTC
+++ setup.ml
@@ -6717,7 +6717,7 @@ let setup_t =
             {
                pre_command = [(OASISExpr.EBool true, None)];
                post_command =
-                 [(OASISExpr.EBool true, Some (("make", ["post-conf"])))]
+                 [(OASISExpr.EBool true, Some (("gmake", ["post-conf"])))]
             };
           build_type = (`Build, "ocamlbuild", Some "0.4");
           build_custom =
@@ -7914,7 +7914,7 @@ let setup_t =
                            (OASISExpr.EFlag "docs", true)
                         ];
                       doc_install = [(OASISExpr.EBool true, true)];
-                      doc_install_dir = "$docdir/api";
+                      doc_install_dir = "$stagedir$docdir/api";
                       doc_title = "API reference for GSL";
                       doc_authors = [];
                       doc_abstract = None;
