--- src/Expr.cc.orig	2013-09-21 12:56:00.000000000 -0700
+++ src/Expr.cc	2013-09-21 12:56:38.000000000 -0700
@@ -2389,7 +2389,7 @@
 	if ( IsError() )
 		return;
 
-	if ( ! is_assignable(op->Type()) )
+	if ( ! ::is_assignable(op->Type()) )
 		ExprError("illegal assignment target");
 	else
 		SetType(op->Type()->Ref());
