--- iiimsf/lib/iml/fop.c.orig	Wed Apr 26 11:16:43 2006
+++ iiimsf/lib/iml/fop.c	Wed Apr 26 11:22:55 2006
@@ -995,7 +995,9 @@
 	break;
     case F_SETFD:
     case F_SETFL:
+#if __BSD_VISIBLE || __XSI_VISIBLE || __POSIX_VISIBLE >= 200112
     case F_SETOWN:
+#endif
 	arg_int = va_arg(ap, int);
 	rv = func(fopc, file->value, cmd, arg_int);
 	break;
