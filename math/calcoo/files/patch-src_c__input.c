
$FreeBSD$

--- src/c_input.c.orig	Sun Jun  2 20:50:25 2002
+++ src/c_input.c	Tue Jun  4 23:28:14 2002
@@ -118,10 +118,15 @@
 
 void call_dot(void)
 {
-	if(cpu->last_action != ACTION_INPUT) {
-		cpu->y = cpu->x;
+	if (cpu->last_action != ACTION_INPUT) {
+		if ((cpu->rpn_mode)
+		    && (cpu->last_action == ACTION_ENTER)) {
+			push_stack();
+			cpu->y = cpu->x;
+		}
 		reset_input();
 		cpu->last_action = ACTION_INPUT;
+		cpu_to_output();
 	}
 
 	if (cpu->d->input_field == INPUT_FIELD_INT) {
