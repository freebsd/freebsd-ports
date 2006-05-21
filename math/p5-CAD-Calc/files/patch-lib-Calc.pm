--- lib/CAD/Calc.pm	Fri Jan  6 22:25:54 2006
+++ lib/CAD/Calc.pm	Sun May 21 16:15:57 2006
@@ -1,7 +1,7 @@
 package CAD::Calc;
 our $VERSION = '0.25';
 
-use Math::Vec qw(NewVec :terse);
+use Math::Vec qw(:terse NewVec);
 use Math::Complex qw(acos);
 use Math::Round::Var;
 use Math::BigFloat;
