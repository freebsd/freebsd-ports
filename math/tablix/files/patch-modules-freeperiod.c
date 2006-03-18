--- modules/freeperiod.c.orig	Sat Feb 18 11:49:49 2006
+++ modules/freeperiod.c	Sat Feb 18 11:52:43 2006
@@ -188,25 +188,28 @@
 
 int module_precalc(moduleoption *opt) 
 {
+	int i;
+	int timeid, teachid;
+	tupleinfo *tup;
+	domain *dom;
+	struct tlist *tnext;
+
 	if ( exclnum == 0 && texcl == NULL )
 	{
 		info(_("module '%s' has been loaded, but not used"), "freeperiod.so");
 		return 0;
 	}
 	
-	int i;
-	int timeid, teachid;
 	timeid = restype_find( "time" )->typeid; 
 	teachid = restype_find( "teacher" )->typeid;
-	tupleinfo *tup = dat_tuplemap;
-	domain *dom;
+	tup = dat_tuplemap;
 	for ( i = 0; i < dat_tuplenum; i++ )
 	{
+		struct tlist *tt;
 		dom = tup[i].dom[timeid];
 		if(excl!=NULL) {
 			domain_del( dom, excl, exclnum );
 		}
-		struct tlist *tt;
 		if ( ( tt = find_texcl( dat_tuplemap[i].resid[teachid] ) ) )
 			domain_del( dom, tt->frees, tt->freenum );
 	}
@@ -215,7 +218,6 @@
 		free(excl);
 	}
 	
-	struct tlist *tnext;
 	while(texcl!=NULL) {
 		tnext=texcl->next;
 		free( texcl->frees );
@@ -228,10 +230,10 @@
 
 int module_init(moduleoption *opt) 
 {
-	precalc_new(module_precalc);
-
 	int d,p;
 	moduleoption *result;
+
+	precalc_new(module_precalc);
 
 	texcl = NULL;
 	excl = NULL;
