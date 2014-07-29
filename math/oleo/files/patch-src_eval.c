--- src/eval.c.orig	Wed Jul 14 23:06:00 2004
+++ src/eval.c	Wed Jul 14 23:11:06 2004
@@ -78,7 +78,11 @@
 RETSIGTYPE math_sig ();
 #endif
 
-int fls (long);
+#if __FreeBSD_version < 502112
+int local_fls (long);
+#define fls local_fls
+#endif
+
 #ifdef SMALLEVAL
 int __to_flt (struct value *);
 int __to_int (struct value *);
@@ -565,7 +569,7 @@
 	case CONST_NINF:
 	case CONST_NAN:
 	  p->type = TYP_FLT;
-	  p->Float = (byte == CONST_INF) ? __plinf : ((byte == CONST_NINF) ? __neinf : __nan);
+	  p->Float = (byte == CONST_INF) ? __plinf : ((byte == CONST_NINF) ? __neinf : ___nan);
 	  break;
 
 	case VAR:
@@ -1540,7 +1544,7 @@
 }
 
 int
-fls (num)
+local_fls (num)
      long num;
 {
   int ret = 1;
