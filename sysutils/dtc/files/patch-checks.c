--- checks.c.orig	2017-12-05 20:24:45 UTC
+++ checks.c
@@ -972,7 +972,7 @@ static void check_property_phandle_args(struct check *
 	int cell, cellsize = 0;
 
 	if (prop->val.len % sizeof(cell_t)) {
-		FAIL(c, dti, "property '%s' size (%d) is invalid, expected multiple of %ld in node %s",
+		FAIL(c, dti, "property '%s' size (%d) is invalid, expected multiple of %zu in node %s",
 		     prop->name, prop->val.len, sizeof(cell_t), node->fullpath);
 		return;
 	}
@@ -1163,7 +1163,7 @@ static void check_interrupts_property(struct check *c,
 		return;
 
 	if (irq_prop->val.len % sizeof(cell_t))
-		FAIL(c, dti, "property '%s' size (%d) is invalid, expected multiple of %ld in node %s",
+		FAIL(c, dti, "property '%s' size (%d) is invalid, expected multiple of %zu in node %s",
 		     irq_prop->name, irq_prop->val.len, sizeof(cell_t),
 		     node->fullpath);
 
