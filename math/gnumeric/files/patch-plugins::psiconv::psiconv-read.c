--- plugins/psiconv/psiconv-read.c.orig	Sun Sep 19 16:43:32 2004
+++ plugins/psiconv/psiconv-read.c	Sun Sep 19 16:44:35 2004
@@ -301,7 +301,7 @@
 	/*	case psiconv_formula_mark_opend: */
 		default:
 	/*		kind = -1; */
-	/*		break;     */
+			break;
 	}
 
 	if (kind == -1) {
@@ -336,6 +336,7 @@
 			v = value_new_cellrange(cr1,cr2,1,1);
 			break;
 		default:
+			break;
 		}
 		if (!v)
 			return NULL;
@@ -407,6 +408,7 @@
 				return NULL;
 			return parse_subexpr(psi_form1);
 		default:
+			break;
 		}
 	}
 		
