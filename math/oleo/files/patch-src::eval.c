--- src/eval.c.org	Sat Jul 19 13:42:11 2003
+++ src/eval.c	Sat Jul 19 13:47:43 2003
@@ -565,7 +565,7 @@
 	case CONST_NINF:
 	case CONST_NAN:
 	  p->type = TYP_FLT;
-	  p->Float = (byte == CONST_INF) ? __plinf : ((byte == CONST_NINF) ? __neinf : __nan);
+	  p->Float = (byte == CONST_INF) ? __plinf : ((byte == CONST_NINF) ? __neinf : ___nan);
 	  break;
 
 	case VAR:
