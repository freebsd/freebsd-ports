--- gtk.m4.orig	Fri Feb  9 22:56:43 2001
+++ gtk.m4	Fri Feb  9 22:57:20 2001
@@ -37,7 +37,7 @@
      fi
   fi
 
-  AC_PATH_PROG(GTK_CONFIG, gtk-config, no)
+  AC_PATH_PROG(GTK_CONFIG, gtk-config, gtk12-config, no)
   min_gtk_version=ifelse([$1], ,0.99.7,$1)
   AC_MSG_CHECKING(for GTK - version >= $min_gtk_version)
   no_gtk=""
