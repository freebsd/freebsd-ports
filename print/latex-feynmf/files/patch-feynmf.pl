--- feynmf.pl	Mon Jan 26 03:58:28 2004
+++ feynmf.pl	Mon Jan 26 03:58:57 2004
@@ -373,7 +373,7 @@
 			maybe_run "$gftopk_prog $gf" if $gftopk_prog;
 		    }
 		}
-		close (<LOG>);
+		close (LOG);
 	    }
 	}
     }
