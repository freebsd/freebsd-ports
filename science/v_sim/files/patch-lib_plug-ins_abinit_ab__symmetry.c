--- lib/plug-ins/abinit/ab_symmetry.c.orig	2020-07-07 14:26:13 UTC
+++ lib/plug-ins/abinit/ab_symmetry.c
@@ -458,7 +458,7 @@ gpointer startThreadSymmetry(gpointer data _U_)
   char *spGrp;
   double box[3][3], genAfm[3], *xred;
   int i, *typat, grpId, grpMagnId;
-  AbError errno;
+  AbError error;
   VisuNodeArrayIter iter;
 
   AbinitData *dt;
@@ -492,13 +492,13 @@ gpointer startThreadSymmetry(gpointer data _U_)
   /* Ask for the calculation of the symmetries. */
   DBG_fprintf(stderr, "AB symmetry(%p): Ready to get symmetries from ABINIT.\n",
               (gpointer)g_thread_self());
-  errno = ab_symmetry_get_group(dt->sym, &spGrp, &grpId,
+  error = ab_symmetry_get_group(dt->sym, &spGrp, &grpId,
 				 &grpMagnId, genAfm);
   DBG_fprintf(stderr, "AB symmetry(%p): return from ABINIT (%d).\n",
-              (gpointer)g_thread_self(), errno);
-  if (errno == AB_NO_ERROR || errno == AB_ERROR_SYM_BRAVAIS_XRED)
+              (gpointer)g_thread_self(), error);
+  if (error == AB_NO_ERROR || errno == AB_ERROR_SYM_BRAVAIS_XRED)
     g_free(spGrp);
-  else if (errno != AB_ERROR_SYM_NOT_PRIMITIVE)
+  else if (error != AB_ERROR_SYM_NOT_PRIMITIVE)
     dt->error = g_error_new(TOOL_FILE_FORMAT_ERROR, TOOL_FILE_FORMAT_ERROR_METHOD,
                             "An error occured in ABINIT plug-in.");
   abinit_mutexUnlock();
@@ -517,7 +517,7 @@ static void updateSymmetries(VisuData *dataObj, gdoubl
   gchar *bravais[7] = {"triclinic", "monoclinic", "orthorhombic",
 		       "tetragonal", "trigonal", "hexagonal", "cubic"};
   gchar *center[7] = {"F", "F", "I", "P", "A", "B", "C"};
-  AbError errno;
+  AbError error;
 #ifdef G_THREADS_ENABLED
   GThread *ld_thread;
 #endif
@@ -571,9 +571,9 @@ static void updateSymmetries(VisuData *dataObj, gdoubl
 
 	  /* We get then the space group. */
           DBG_fprintf(stderr, "AB symmetry: get group.\n");
-	  errno = ab_symmetry_get_group(sym, &spGrp, &grpId,
+	  error = ab_symmetry_get_group(sym, &spGrp, &grpId,
 					 &grpMagnId, genAfm);
-	  if (errno == AB_NO_ERROR || errno == AB_ERROR_SYM_BRAVAIS_XRED)
+	  if (error == AB_NO_ERROR || errno == AB_ERROR_SYM_BRAVAIS_XRED)
 	    {
 	      str = g_strdup_printf("%s (#%d)", spGrp, grpId);
 	      gtk_label_set_text(GTK_LABEL(lblSymId), str);
@@ -629,7 +629,7 @@ static void updateSymmetries(VisuData *dataObj, gdoubl
 
 	  /* If the bravais lattice doesn't match with the xred bravais
 	     lattice, we print a message. */
-	  if (errno == AB_ERROR_SYM_BRAVAIS_XRED)
+	  if (error == AB_ERROR_SYM_BRAVAIS_XRED)
 	    gtk_widget_show(lblSymWarning);
 	  else
 	    gtk_widget_hide(lblSymWarning);
