--- ged2gwb/ged2gwb.ml.orig	2024-02-11 19:27:48 UTC
+++ ged2gwb/ged2gwb.ml
@@ -603,7 +603,7 @@ value date_lexer =
 ;
 
 value date_lexer =
-  {Token.tok_func s = (make_date_lexing s, fun _ -> Token.dummy_loc);
+  {Token.tok_func s = (make_date_lexing s, Plexing.Locations.create());
    Token.tok_using = using_token; Token.tok_removing _ = ();
    Token.tok_match = tparse; Token.tok_text _ = "<tok>";
    Token.tok_comm = None}
