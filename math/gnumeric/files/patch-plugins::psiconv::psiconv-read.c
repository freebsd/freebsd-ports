
$FreeBSD$

--- plugins/psiconv/psiconv-read.c	2001/10/09 12:39:33	1.1
+++ plugins/psiconv/psiconv-read.c	2001/10/09 12:51:24
@@ -420,7 +420,7 @@
 
 	formula = psiconv_get_formula (psi_formulas, psi_cell->ref_formula);
 
-	return (formula != NULL) ?  return parse_subexpr (formula) : NULL;
+	return (formula != NULL) ? parse_subexpr (formula) : NULL;
 }
 
 static void
@@ -429,27 +429,27 @@
 {
 	Cell *cell;
 	Value *val;
-	ExprTree *tree;
+	ExprTree *tree = NULL;
 	psiconv_formula psi_formula;
 
 	cell = sheet_cell_fetch (sheet, psi_cell->column, psi_cell->row);
 	if (!cell)
 		return;
 
-	val = value_new_from_psi_cell (psi_cell);
+	val = value_new_from_psi_cell (cell, psi_cell);
 
 	if (psi_cell->calculated)
-		expr = expr_new_from_formula (psi_cell, psi_formulas);
+		tree = expr_new_from_formula (psi_cell, psi_formulas);
 
-	if (expr != NULL) {
+	if (tree != NULL) {
 		/* TODO : is there a notion of parse format ?
 		 * How does it store a user entered date ?
 		 */
-		if (value != NULL)
-			cell_set_expr_and_value (cell, expr, val, NULL, TRUE);
+		if (val != NULL)
+			cell_set_expr_and_value (cell, tree, val, NULL, TRUE);
 		else
-			cell_set_expr (cell, expr, NULL);
-	} else if (value != NULL) {
+			cell_set_expr (cell, tree, NULL);
+	} else if (val != NULL) {
 		/* TODO : is there a notion of parse format ?
 		 * How does it store a user entered date ?
 		 */
