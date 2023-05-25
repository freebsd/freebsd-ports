--- src/parser.rs.orig	2023-05-25 00:49:21 UTC
+++ src/parser.rs
@@ -101,7 +101,9 @@ impl Parser {
                             #[cfg(unix)]
                                 {
                                     fields.push(Expr::field(Field::Mode));
+                                    #[cfg(feature = "users")]
                                     fields.push(Expr::field(Field::User));
+                                    #[cfg(feature = "users")]
                                     fields.push(Expr::field(Field::Group));
                                 }
 
