--- guile-gnome/gnomeg.c.orig	Thu May  1 02:35:47 2003
+++ guile-gnome/gnomeg.c	Thu May  1 02:40:20 2003
@@ -433,7 +433,7 @@
 	SCM arg;
 	EXTRACT_SCM(info->args, arg);
 	SCM_ASSERT (SCM_NIMP(arg) && SCM_REALP(arg), arg, "inexact expected", s_gtk_dialog_cauldron);
-	*x = SCM_REALPART(arg);
+	*x = SCM_REAL_VALUE (arg);
 	break;
     }
     case GTK_CAULDRON_TYPE_DOUBLE_P: {
@@ -445,7 +445,7 @@
 	info->num_data++;
 	info->data_array = g_renew(CauldronVarItem, info->data_array, info->num_data);
 	info->data_array[info->num_data - 1].type = type;
-	**x = SCM_REALPART(arg);
+	**x = SCM_REAL_VALUE(arg);
 	break;
     }
     case GTK_CAULDRON_TYPE_CALLBACK: {
@@ -494,7 +494,9 @@
 	    tmp = SCM_MAKINUM(info->data_array[i].var.i);
 	    break;
 	case GTK_CAULDRON_TYPE_DOUBLE_P:
+	    /*
 	    tmp = scm_makdbl(info->data_array[i].var.d, 0.0);
+	    */
 	    break;
 	}
 	ret = scm_cons(tmp, ret);
@@ -615,7 +617,7 @@
   v = (char **)scm_must_malloc ((c+1) * sizeof(char**), "make-argv");
   for (i = 0; i < c; i++, list = SCM_CDR (list))
     {
-      if (SCM_IMP (SCM_CAR (list)) || SCM_NSTRINGP (SCM_CAR (list)))
+      if (SCM_IMP (SCM_CAR (list)) || !SCM_STRINGP (SCM_CAR (list)))
 	{
 	  scm_must_free ((char *)v);
 	  return;
@@ -1150,9 +1152,9 @@
 	    }
 	  else if (!strcmp (keystr, "accel-key"))
 	    {
-	      if (!SCM_ICHRP(val))
+	      if (!SCM_CHARP(val))
 		uiinfo_error ("not a character", val);
-	      info->accelerator_key = SCM_ICHR(val);
+	      info->accelerator_key = SCM_CHAR(val);
 	    }
 	  else if (!strcmp (keystr, "accel-mods"))
 	    {
@@ -1271,14 +1273,14 @@
 	/* utilities */
 
 #if 0
-	scm_make_gsubr("gnome-libdir-file", 1, 0, 0, guile_gnome_libdir_file);
-	scm_make_gsubr("gnome-datadir-file", 1, 0, 0, guile_gnome_datadir_file);
-	scm_make_gsubr("gnome-pixmap-file", 1, 0, 0, guile_gnome_pixmap_file);
-	scm_make_gsubr("gnome-unconditional-libdir-file", 1, 0, 0, guile_gnome_unconditional_libdir_file);
-	scm_make_gsubr("gnome-unconditional-datadir-file", 1, 0, 0, guile_gnome_unconditional_datadir_file);
-	scm_make_gsubr("gnome-unconditional-pixmap-file", 1, 0, 0, guile_gnome_unconditional_pixmap_file);
+	scm_c_define_gsubr("gnome-libdir-file", 1, 0, 0, guile_gnome_libdir_file);
+	scm_c_define_gsubr("gnome-datadir-file", 1, 0, 0, guile_gnome_datadir_file);
+	scm_c_define_gsubr("gnome-pixmap-file", 1, 0, 0, guile_gnome_pixmap_file);
+	scm_c_define_gsubr("gnome-unconditional-libdir-file", 1, 0, 0, guile_gnome_unconditional_libdir_file);
+	scm_c_define_gsubr("gnome-unconditional-datadir-file", 1, 0, 0, guile_gnome_unconditional_datadir_file);
+	scm_c_define_gsubr("gnome-unconditional-pixmap-file", 1, 0, 0, guile_gnome_unconditional_pixmap_file);
 
-	scm_make_gsubr("gnome-config-get-string", 1, 0, 0, guile_gnome_config_get_string);
+	scm_c_define_gsubr("gnome-config-get-string", 1, 0, 0, guile_gnome_config_get_string);
 #endif
 
 	/* FIXME: this should really be done via `gnome.defs'.  But
@@ -1287,31 +1289,31 @@
 	   arguments here.  I named the function "gnome-about" and not
 	   "gnome-about-new" so that the latter can be used by the
 	   .defs file without changing anything.  */
-	scm_make_gsubr("gnome-about", 5, 0, 1, guile_gnome_about);
+	scm_c_define_gsubr("gnome-about", 5, 0, 1, guile_gnome_about);
 
-	scm_make_gsubr(sgnome_init_hack, 3, 0, 0, guile_gnome_init_hack);
-	scm_make_gsubr (s_gnome_canvas_item_set, 1, 0, 1, sgtk_gnome_canvas_item_set);
-	scm_make_gsubr (s_gnome_canvas_item_new, 2, 0, 1, sgtk_gnome_canvas_item_new);
+	scm_c_define_gsubr(sgnome_init_hack, 3, 0, 0, guile_gnome_init_hack);
+	scm_c_define_gsubr (s_gnome_canvas_item_set, 1, 0, 1, sgtk_gnome_canvas_item_set);
+	scm_c_define_gsubr (s_gnome_canvas_item_new, 2, 0, 1, sgtk_gnome_canvas_item_new);
 
 	/* I don't think this should use gnome.defs - it's one of a
            kind interface, and iterators are not Schemish */
 
-	scm_make_gsubr (s_gnome_config_foreach, 1, 0, 0, sgtk_gnome_config_foreach);
-	scm_make_gsubr (s_gnome_config_map, 1, 0, 0, sgtk_gnome_config_map);
-	scm_make_gsubr (s_gnome_config_private_foreach, 1, 0, 0, sgtk_gnome_config_private_foreach);
-	scm_make_gsubr (s_gnome_config_private_map, 1, 0, 0, sgtk_gnome_config_private_map);
-	scm_make_gsubr (s_gnome_config_sections_foreach, 1, 0, 0, sgtk_gnome_config_sections_foreach);
-	scm_make_gsubr (s_gnome_config_sections_map, 1, 0, 0, sgtk_gnome_config_sections_map);
-	scm_make_gsubr (s_gnome_config_private_sections_foreach, 1, 0, 0, sgtk_gnome_config_private_sections_foreach);
-	scm_make_gsubr (s_gnome_config_private_sections_map, 1, 0, 0, sgtk_gnome_config_private_sections_map);
+	scm_c_define_gsubr (s_gnome_config_foreach, 1, 0, 0, sgtk_gnome_config_foreach);
+	scm_c_define_gsubr (s_gnome_config_map, 1, 0, 0, sgtk_gnome_config_map);
+	scm_c_define_gsubr (s_gnome_config_private_foreach, 1, 0, 0, sgtk_gnome_config_private_foreach);
+	scm_c_define_gsubr (s_gnome_config_private_map, 1, 0, 0, sgtk_gnome_config_private_map);
+	scm_c_define_gsubr (s_gnome_config_sections_foreach, 1, 0, 0, sgtk_gnome_config_sections_foreach);
+	scm_c_define_gsubr (s_gnome_config_sections_map, 1, 0, 0, sgtk_gnome_config_sections_map);
+	scm_c_define_gsubr (s_gnome_config_private_sections_foreach, 1, 0, 0, sgtk_gnome_config_private_sections_foreach);
+	scm_c_define_gsubr (s_gnome_config_private_sections_map, 1, 0, 0, sgtk_gnome_config_private_sections_map);
 #ifdef CAULDRON_TAKES_PARENT
-	scm_make_gsubr (s_gtk_dialog_cauldron, 4, 0, 1, sgtk_gtk_dialog_cauldron);
+	scm_c_define_gsubr (s_gtk_dialog_cauldron, 4, 0, 1, sgtk_gtk_dialog_cauldron);
 #else
-	scm_make_gsubr (s_gtk_dialog_cauldron, 3, 0, 1, sgtk_gtk_dialog_cauldron);
+	scm_c_define_gsubr (s_gtk_dialog_cauldron, 3, 0, 1, sgtk_gtk_dialog_cauldron);
 #endif
 	uiinfo_macro_translator =
 	  scm_permanent_object (scm_cons (SCM_BOOL_F, SCM_EOL));
-	scm_make_gsubr (s_gnome_uiinfo_set_translator, 1, 0, 0,
+	scm_c_define_gsubr (s_gnome_uiinfo_set_translator, 1, 0, 0,
 			sgtk_gnome_uiinfo_set_translator);
 
 }
