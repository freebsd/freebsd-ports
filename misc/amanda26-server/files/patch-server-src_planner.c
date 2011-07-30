--- server-src/planner.c.orig	2011-06-25 22:52:39.000000000 +0200
+++ server-src/planner.c	2011-06-25 22:54:23.000000000 +0200
@@ -431,7 +431,7 @@
 	    amfree(qhname);
 	    dumpfile_free_data(&file);
 	}
-	g_slist_free_full(holding_list);
+	_slist_free_full(holding_list, g_free);
 	holding_list = NULL;
     }
     g_fprintf(stderr, _("ENDFLUSH\n"));
