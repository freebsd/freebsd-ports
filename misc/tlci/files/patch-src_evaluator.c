--- src/evaluator.c.orig	2023-06-11 19:02:44 UTC
+++ src/evaluator.c
@@ -192,7 +192,7 @@ void eval_init(jmp_buf* error_handler)
     memcpy(&on_error, error_handler, sizeof(jmp_buf));
 }
 /*********************************************************************************/
-string eval_get_error()
+string eval_get_error(void)
 {
     return (string) { .begin = error_msg, .len = strlen(error_msg) };
 }
