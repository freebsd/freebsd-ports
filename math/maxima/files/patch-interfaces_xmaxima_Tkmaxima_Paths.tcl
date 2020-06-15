--- interfaces/xmaxima/Tkmaxima/Paths.tcl.orig	2020-06-08 10:58:28 UTC
+++ interfaces/xmaxima/Tkmaxima/Paths.tcl
@@ -302,6 +302,8 @@ proc setMaxDir {} {
 		set maxima_priv(pReferenceToc) [file join $dir html maxima_toc.html]
 	    }
 	}
+    } elseif {[file isdir [set dir [file join %%DOCSDIR%%]]]} {
+	set maxima_priv(pReferenceToc) [file join $dir maxima_toc.html]
     } else {
 	tide_notify [M [mc "Documentation not found in '%s'"] \
 			 [file native  $maxima_priv(maxima_verpkgdatadir)]]
