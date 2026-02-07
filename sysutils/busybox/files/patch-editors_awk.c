--- editors/awk.c.orig	2021-11-28 21:53:43 UTC
+++ editors/awk.c
@@ -3238,7 +3238,7 @@ static var *evaluate(node *op, var *res)
 				if (op1)
 					syntax_error("Too many arguments");
 			{
-#if RAND_MAX >= 0x7fffffff
+#if RAND_MAX >= 0x7ffffffd
 				uint32_t u = ((uint32_t)rand() << 16) ^ rand();
 				uint64_t v = ((uint64_t)rand() << 32) | u;
 				/* the above shift+or is optimized out on 32-bit arches */
