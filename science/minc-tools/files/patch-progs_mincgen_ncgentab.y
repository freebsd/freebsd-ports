--- progs/mincgen/ncgentab.y.orig	2015-09-11 19:22:24 UTC
+++ progs/mincgen/ncgentab.y
@@ -275,14 +275,14 @@ attdecl:        att
 		       /* shrink space down to what was really needed */
 		       att_space = erealloc(att_space, valnum*nctypesize(valtype));
 		       atts[natts].val = att_space;
-		       if (STREQ(atts[natts].name, _FillValue) &&
+		       if (STREQ(atts[natts].name, NC_FillValue) &&
 			   atts[natts].var != NC_GLOBAL) {
 			   nc_putfill(atts[natts].type,
 				       atts[natts].val,
 				       &vars[atts[natts].var].fill_value);
 			   if(atts[natts].type != vars[atts[natts].var].type) {
 			       derror("variable %s: %s type mismatch",
-				      vars[atts[natts].var].name, _FillValue);
+				      vars[atts[natts].var].name, NC_FillValue);
 			   }
 		       }
 		       natts++;
