--- scsilib/libschily/format.c.orig	2003-10-18 13:26:50 UTC
+++ scsilib/libschily/format.c
@@ -166,6 +166,7 @@ format(fun, farg, fmt, args)
 	Ulong res;
 	char *rfmt;
 	f_args	fa;
+	va_list vl;
 
 	fa.outf = fun;
 	fa.farg = farg;
@@ -432,6 +433,7 @@ format(fun, farg, fmt, args)
 		case 'r':			/* recursive printf */
 		case 'R':			/* recursive printf */
 			rfmt  = va_arg(args, char *);
+			va_copy(vl, args);
 			/*
 			 * I don't know any portable way to get an arbitrary
 			 * C object from a var arg list so I use a
@@ -446,7 +448,8 @@ format(fun, farg, fmt, args)
 			 * It would be nice to have something like
 			 * __va_arg_list() in stdarg.h
 			 */
-			count += format(fun, farg, rfmt, __va_arg_list(args));
+			count += format(fun, farg, rfmt, vl);
+			va_end(vl);
 			continue;
 
 		case 'n':
