--- src/gpm-cell-aray.c.orig	2009-10-24 19:59:07.000000000 -0400
+++ src/gpm-cell-array.c	2009-10-24 19:59:50.000000000 -0400
@@ -355,7 +355,8 @@ gpm_cell_array_update (GpmCellArray *cel
 	 * get an with batteries which have a very small charge unit and consequently
 	 * a very high charge. Fixes bug #327471 */
 	if (unit->kind == GPM_CELL_UNIT_KIND_PRIMARY &&
-	    unit->charge_current > 0 && unit->charge_last_full > 0) {
+	    unit->charge_current > 0 && unit->charge_last_full > 0 &&
+	    unit->percentage > 1) {
 		gfloat pc = 100.0f * ((gfloat)unit->charge_current /
 				(gfloat)unit->charge_last_full);
 		if (pc < 0.0f) {
