--- lily/parser.yy.orig	Thu Feb  5 19:50:36 2004
+++ lily/parser.yy	Thu Feb  5 19:50:42 2004
@@ -893,7 +893,7 @@
 		scm_gc_unprotect_object ($2->self_scm ());
 		$$ = unsmob_music (res);
 		scm_gc_protect_object (res);
-		$$->set_spot (THIS->here_input())
+		$$->set_spot (THIS->here_input());
 	}
 	| PARTCOMBINE Music Music {
 		static SCM proc;
