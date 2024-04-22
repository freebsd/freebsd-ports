--- src/mutil.ml.orig	2024-02-11 18:31:48 UTC
+++ src/mutil.ml
@@ -95,7 +95,7 @@ value decline case s =
       | '>' -> String.sub s ibeg (i + 1 - ibeg) ^ loop (i + 1) (i + 1)
       | _ -> loop ibeg (i + 1) ]
 ;
-end ELSE declare
+end; ELSE declare
 (* [decline] has been deprecated since version 5.00
    compatibility code: *)
 value colon_to_at_word s ibeg iend =
@@ -158,7 +158,7 @@ value decline case s =
     (if not (String.contains s ':') then s else colon_to_at s)
 ;
 (* end compatibility code *)
-end END;
+end; END;
 
 value nominative s =
   match rindex s ':' with
