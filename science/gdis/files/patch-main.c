--- main.c.orig	Tue Nov  4 15:08:29 2003
+++ main.c	Wed Dec 31 02:11:54 2003
@@ -433,6 +433,12 @@
     }
   }
 
+#ifdef INSTALL
+strcpy(sysenv.elem_file, INSTALL);
+strcat(sysenv.elem_file, DIR_SEP);
+strcat(sysenv.elem_file, ELEM_FILE);
+#endif
+
 /* defaults */
 sysenv.povray_exe = g_strdup("povray");
 sysenv.convert_exe = g_strdup("convert");
