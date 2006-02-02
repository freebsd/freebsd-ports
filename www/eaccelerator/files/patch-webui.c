--- webui.c.orig	Sun Jul 10 10:12:33 2005
+++ webui.c	Thu Feb  2 09:40:00 2006
@@ -263,7 +263,7 @@ static void dump_zval (zval * v, int com
 		ZEND_PUTS ("constant('");
 		goto string_dump;
 	case IS_CONSTANT_ARRAY:
-		ZEND_PUTS ("constatnt_array(");
+		ZEND_PUTS ("constant_array(");
 		goto array_dump;
 	default:
 		zend_printf ("unknown(%d)", v->type);
@@ -271,21 +271,26 @@ static void dump_zval (zval * v, int com
 }
 
 static const char *color_list[] = {
-	"#FF0000",
-	"#00FF00",
-	"#0000FF",
-	"#FFFF00",
-	"#00FFFF",
-	"#FF00FF",
-	"#800000",
-	"#008000",
-	"#000080",
-	"#808000",
-	"#008080",
-	"#800080"
+    /* color from irc */
+    /* 0  // "#ffffff",          white                    */
+    /* 1  // "#000000",          black                    */
+    /* 4  */ "#ff0000",         /* light red                */
+    /* 7  */ "#fc7f00",         /* orange                   */
+    /* 6  */ "#9c009c",         /* magenta                  */
+    /* 5  */ "#7f0000",         /* red                      */
+    /* 9  */ "#00fc00",         /* light green (lime)       */
+    /* 10 */ "#009393",         /* cyan                     */
+    /* 12 */ "#0000fc",         /* light blue               */
+    /* 13 */ "#ff00ff",         /* light magenta (pink)     */    
+    /* 2  */ "#00007f",         /* blue                     */
+    /* 3  */ "#009300",         /* green                    */
+    /* 8  // "#ffff00",        yellow                   */
+    /* 11 // "#00ffff",        light cyan (aqua)        */ 
+    /* 14 */ "#7f7f7f",         /* grey                     */
+    /* 15 */ "#d2d2d2"          /* light grey (silver)      */
 };
 
-static char const *color (int num)
+static const char *color (int num)
 {
 	return color_list[num % (sizeof (color_list) / sizeof (char *))];
 }
@@ -322,6 +327,11 @@ static void print_file_line (char *p, in
 	while (line > 0 && *p) {
 		if (*p == '\n') {
 			line--;
+        } else if (*p == '\r') {
+            line--;
+            if (p[1] == '\n') {
+                p++;
+            }
 		} else if (line == 1) {
 			if (*p == '<')
 				zend_printf ("&lt;");
@@ -343,6 +353,9 @@ static void dump_op_array (eaccelerator_
 	unsigned last_line = 0;
 
 #ifdef ZEND_ENGINE_2
+#ifdef ZEND_ENGINE_2_1
+    zend_printf ("last_var = %u, ", p->last_var);
+#endif
 	zend_printf ("T = %u, size = %u\n, brk_count = %u, file = %s<br>\n",
 				 p->T, p->last, p->last_brk_cont, p->filename);
 #else
@@ -367,9 +380,25 @@ static void dump_op_array (eaccelerator_
 			ZEND_PUTS ("&nbsp;</td></tr>\n");
 			q = q->pListNext;
 		}
-		ZEND_PUTS ("<tbody></table><br>\n");
+		ZEND_PUTS ("</tbody></table><br>\n");
 	}
-
+#ifdef ZEND_ENGINE_2_1
+    if (p->last_var) {
+        int i;
+        
+        ZEND_PUTS("<table border=\"0\" cellpadding=\"3\" cellspacing=\"1\" width=\"600\" bgcolor=\"#000000\" align=\"center\" style=\"table-layout:fixed\">\n");
+        ZEND_PUTS("<thead valign=\"middle\" bgcolor=\"#9999cc\"><tr><th width=\"200\">Compiled variable</th><th width=\"200\">Len</th><th width=\"200\">Hash</th></tr></thead>\n");
+        ZEND_PUTS("<tbody valign=\"top\" bgcolor=\"#cccccc\" style=\"word-break:break-all\">\n");
+        
+        for (i = 0; i < p->last_var; i ++) {
+            zend_printf ("<tr><td bgcolor=\"#ccccff\">$%s&nbsp;</td>", p->vars[i].name);
+            zend_printf ("<td bgcolor=\"#ccccff\">%u&nbsp;</td>", p->vars[i].name_len);
+            zend_printf ("<td bgcolor=\"#ccccff\">%u&nbsp;</td></tr>\n", p->vars[i].hash_value);
+        }
+        ZEND_PUTS ("</tbody></table><br>\n");
+    }
+#endif
+    
 	if (p->opcodes) {
 		int n = 0;
 		opline = p->opcodes;
@@ -377,20 +406,20 @@ static void dump_op_array (eaccelerator_
 
 		filebuf = get_file_contents (p->filename);
 
-		ZEND_PUTS
-			("<table border=\"0\" cellpadding=\"3\" cellspacing=\"1\" width=\"900\" bgcolor=\"#000000\" align=\"center\" style=\"table-layout:fixed\">\n");
-		ZEND_PUTS
-			("<thead valign=\"middle\" bgcolor=\"#9999cc\"><tr><th width=\"40\">N</th><th width=\"160\">OPCODE</th><th width=\"160\">EXTENDED_VALUE</th><th width=\"220\">OP1</th><th width=\"220\">OP2</th><th width=\"80\">RESULT</th></tr></thead>\n");
-		ZEND_PUTS
-			("<tbody valign=\"top\" bgcolor=\"#cccccc\" style=\"word-break:break-all; font-size: x-small\">\n");
+		ZEND_PUTS("<table border=\"0\" cellpadding=\"3\" cellspacing=\"1\" width=\"900\" bgcolor=\"#000000\" align=\"center\" style=\"table-layout:fixed\">\n");
+		ZEND_PUTS("<thead valign=\"middle\" bgcolor=\"#9999cc\"><tr><th width=\"40\">N</th><th width=\"160\">OPCODE</th><th width=\"160\">EXTENDED_VALUE</th><th width=\"220\">OP1</th><th width=\"220\">OP2</th><th width=\"80\">RESULT</th></tr></thead>\n");
+		ZEND_PUTS("<tbody valign=\"top\" bgcolor=\"#cccccc\" style=\"word-break:break-all; font-size: x-small\">\n");
+        
 		for (; opline < end; opline++) {
 			const opcode_dsc *op = get_opcode_dsc (opline->opcode);
 
-			while (last_line < opline->lineno) {
-				last_line++;
-				zend_printf
-					("<tr><td colspan=6 bgcolor=black><pre><font color=#80ff80>");
-				print_file_line (filebuf, last_line);
+			if (last_line < opline->lineno) {
+				zend_printf("<tr><td colspan=6 bgcolor=black><pre><font color=#80ff80>");
+				while (last_line < opline->lineno) {
+                    last_line++;
+                    print_file_line(filebuf, last_line);
+                    ZEND_PUTS("\n");
+                }
 				zend_printf ("</font></pre></td></tr>\n");
 			}
 
@@ -459,6 +488,7 @@ static void dump_op_array (eaccelerator_
 					} else {
 						ZEND_PUTS ("<td>&nbsp; </td>");
 					}
+#ifndef ZEND_ENGINE_2_1
 				} else if (opline->opcode == ZEND_UNSET_DIM_OBJ) {
 					if (opline->extended_value == ZEND_UNSET_DIM) {
 						ZEND_PUTS ("<td>ZEND_UNSET_DIM </td>");
@@ -468,6 +498,7 @@ static void dump_op_array (eaccelerator_
 						ZEND_PUTS ("<td>&nbsp; </td>");
 					}
 #endif
+#endif
 				} else if (opline->extended_value != 0) {
 					zend_printf ("<td>%ld </td>", opline->extended_value);
 				} else {
@@ -479,7 +510,13 @@ static void dump_op_array (eaccelerator_
 					 n, opline->opcode, opline->extended_value);
 				op = get_opcode_dsc (0);
 			}
-
+#ifdef ZEND_ENGINE_2_1
+            if (opline->op1.op_type == IS_CV) {
+                zend_printf("<td><font color=%s>$cv%u(%s)</font> </td>", 
+                        color (opline->op1.u.var), opline->op1.u.var,
+                        p->vars[opline->op1.u.var].name);
+            } else
+#endif
 			if ((op->ops & OP1_MASK) == OP1_OPLINE) {
 				zend_printf
 					("<td><font color=%s>opline(%d)</font> </td>",
@@ -586,7 +623,13 @@ static void dump_op_array (eaccelerator_
 						("<td>UNKNOWN NODE %d </td>", opline->op1.op_type);
 				}
 			}
-
+#ifdef ZEND_ENGINE_2_1
+            if (opline->op2.op_type == IS_CV) {
+                zend_printf("<td><font color=%s>$cv%u(%s)</font> </td>",
+                        color (opline->op2.u.var), opline->op2.u.var,
+                        p->vars[opline->op2.u.var].name);
+            } else 
+#endif
 			if ((op->ops & OP2_MASK) == OP2_OPLINE) {
 				zend_printf
 					("<td><font color=%s>opline(%d)</font> </td>",
@@ -674,7 +717,14 @@ static void dump_op_array (eaccelerator_
 						("<td>UNKNOWN NODE %d </td>", opline->op2.op_type);
 				}
 			}
-
+#ifdef ZEND_ENGINE_2_1
+            if (opline->result.op_type == IS_CV) {
+                zend_printf("<td><font color=%s>$cv%u(%s)</font> </td>",
+                        color (opline->result.u.var), opline->result.u.var,
+                        p->vars[opline->result.u.var].name);
+            } else 
+#endif
+    
 			switch (op->ops & RES_MASK) {
 			case RES_STD:
 				if (opline->result.op_type == IS_CONST) {
@@ -1833,7 +1883,7 @@ PHP_FUNCTION (eaccelerator)
 	}
 
 	{
-		char *s = php_get_uname ();
+		char *s = php_get_uname ('a');
 		zend_printf ("<nobr>%s</nobr>\n", s);
 		efree (s);
 	}
