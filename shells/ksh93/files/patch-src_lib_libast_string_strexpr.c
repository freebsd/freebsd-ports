--- src/lib/libast/string/strexpr.c.orig	2017-11-30 22:35:04 UTC
+++ src/lib/libast/string/strexpr.c
@@ -44,7 +44,7 @@
 #define peekchr(ex)	(*(ex)->nextchr)
 #define ungetchr(ex)	((ex)->nextchr--)
 
-#define error(ex,msg)	return(seterror(ex,msg))
+#define err(ex,msg)	return(seterror(ex,msg))
 
 typedef struct				/* expression handle		*/
 {
@@ -87,7 +87,7 @@ expr(register Expr_t* ex, register int p
 	case 0:
 		ungetchr(ex);
 		if (!precedence) return(0);
-		error(ex, "more tokens expected");
+		err(ex, "more tokens expected");
 	case '-':
 		n = -expr(ex, 13);
 		break;
@@ -113,17 +113,17 @@ expr(register Expr_t* ex, register int p
 		case 0:
 			goto done;
 		case ')':
-			if (!precedence) error(ex, "too many )'s");
+			if (!precedence) err(ex, "too many )'s");
 			goto done;
 		case '(':
 			n = expr(ex, 1);
 			if (getchr(ex) != ')')
 			{
 				ungetchr(ex);
-				error(ex, "closing ) expected");
+				err(ex, "closing ) expected");
 			}
 		gotoperand:
-			if (operand) error(ex, "operator expected");
+			if (operand) err(ex, "operator expected");
 			operand = 1;
 			continue;
 		case '?':
@@ -140,7 +140,7 @@ expr(register Expr_t* ex, register int p
 				if (getchr(ex) != ':')
 				{
 					ungetchr(ex);
-					error(ex, ": expected for ? operator");
+					err(ex, ": expected for ? operator");
 				}
 				if (n)
 				{
@@ -189,7 +189,7 @@ expr(register Expr_t* ex, register int p
 			break;
 		case '=':
 		case '!':
-			if (peekchr(ex) != '=') error(ex, "operator syntax error");
+			if (peekchr(ex) != '=') err(ex, "operator syntax error");
 			if (precedence > 7) goto done;
 			getchr(ex);
 			x = expr(ex, 8);
@@ -237,7 +237,7 @@ expr(register Expr_t* ex, register int p
 			if (precedence > 11) goto done;
 			x = expr(ex, 12);
 			if (c == '*') n *= x;
-			else if (x == 0) error(ex, "divide by zero");
+			else if (x == 0) err(ex, "divide by zero");
 			else if (c == '/') n /= x;
 			else n %= x;
 			break;
@@ -246,15 +246,15 @@ expr(register Expr_t* ex, register int p
 			pos = --ex->nextchr;
 			if (isdigit(c)) n = strton(ex->nextchr, &ex->nextchr, NiL, 0);
 			else if (ex->convert) n = (*ex->convert)(ex->nextchr, &ex->nextchr, ex->handle);
-			if (ex->nextchr == pos) error(ex, "syntax error");
+			if (ex->nextchr == pos) err(ex, "syntax error");
 			goto gotoperand;
 		}
 		if (ex->errmsg) return(0);
-		if (!operand) error(ex, "operand expected");
+		if (!operand) err(ex, "operand expected");
 	}
  done:
 	ungetchr(ex);
-	if (!operand) error(ex, "operand expected");
+	if (!operand) err(ex, "operand expected");
 	return(n);
 }
 
