--- sysdep/unix/krt.c.orig	Mon Jun  7 18:51:23 2004
+++ sysdep/unix/krt.c	Thu May 12 20:41:53 2005
@@ -639,6 +639,7 @@
 	  return;
 	}
 #endif
+	    ;
     }
   rte_free(e);
 }
