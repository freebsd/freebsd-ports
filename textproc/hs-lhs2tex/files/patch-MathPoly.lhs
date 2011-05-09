--- ./MathPoly.lhs.orig	2010-07-22 12:13:20.000000000 +0200
+++ ./MathPoly.lhs	2011-03-27 01:52:26.469094252 +0100
@@ -358,7 +358,7 @@
 >                                      (rn,rc) = findrel (n,c) rstack
 >                                      -- Schritt 3: Zeile auf Stack legen
 >                                      fstack  = (c,l) : rstack
->                                  in mkFromTo fstack rn n rc [fromToken $ TeX False (indent (rn,rc) (n,c))] p ls
+>                                  in mkFromTo fstack rn n rc [fromToken $ (TeX False (indent (rn,rc) (n,c))) :: Token] p ls
 >                                              
 >
 >         | c `elem` z          -> mkFromTo stack n (n ++ "E") c ts rs ls
