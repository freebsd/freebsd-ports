--- gui_siesta.c.orig	Mon Oct 16 10:59:37 2006
+++ gui_siesta.c	Thu Nov  2 00:30:56 2006
@@ -58,10 +58,10 @@
 /*************************/
 void gui_siesta_dialog(void)
 {
-    siestafileWRITE = FALSE;
     GtkWidget *window;
     gpointer dialog;
     struct model_pak *model;
+    siestafileWRITE = FALSE;
 
     model = sysenv.active_model;
 
@@ -797,6 +797,8 @@
 struct model_pak * model;
 struct core_pak *core_i;
 struct core_pak *core_j;
+GtkWidget *hbox, *vbox, *vbox2, *window;
+GtkWidget *dialog, *frame;
 
 
     model = sysenv.active_model;
@@ -826,8 +828,6 @@
 
     num_lines = 3*2*num_atoms*num_atoms;
 
-    GtkWidget *hbox, *vbox, *vbox2, *window;
-    GtkWidget *dialog, *frame;
     /* Create the widgets */
 
     /* request a dialog */
@@ -844,6 +844,10 @@
         FILE *fp, *matout;
 
         gchar * modelFCname, *modelFCnameCSV;
+        gdouble correction;
+        gint temp_int;
+        gdouble freq_i, freq_ii;
+        gint sizeofeig;
 
         modelFCname = g_strdup_printf("%s/%s.FC", sysenv.cwd, model->basename);
         modelFCnameCSV = g_strdup_printf("%s.csv", modelFCname);
@@ -1102,7 +1106,6 @@
     //         enddo
     //       enddo
 
-        gdouble correction;
         for (i=0; i<num_atoms; i++)
         {
             for (j=0; j<num_atoms; j++)
@@ -1219,13 +1222,11 @@
             model->siesta.sorted_eig_values[i] = i;
         }
 
-        gint temp_int;
-        gdouble freq_i, freq_ii;
 
 /*
         gint sizeofeig = model->siesta.eigen_values->dim;
 */
-        gint sizeofeig = mesch_dim_get(model->siesta.eigen_values);
+        sizeofeig = mesch_dim_get(model->siesta.eigen_values);
 
 
         for (j=sizeofeig-1; j>1; j--)
@@ -1350,10 +1351,10 @@
 {
     //evil active model call - evil evil evil
     struct model_pak *model;
-    model = sysenv.active_model;
-
     gchar *buff;
 
+    model = sysenv.active_model;
+
     buff = g_strdup(gtk_entry_get_text(GTK_ENTRY(GTK_COMBO(data)->entry)));
     if (g_ascii_strncasecmp("Verlet", buff, 6) == 0)
         model->siesta.md_type_of_run = VERLET_MDRUN;
@@ -1747,6 +1748,9 @@
 
     for (i=0; i<total_files; i++)
     {
+        //grab current grid_config_pak
+        struct grid_config_pak * grid_pak;
+
         //set the range for md_fc_first, and md_fc_last
         model->siesta.md_fc_first = i* model->siesta.atoms_per_job + 1;
         model->siesta.md_fc_last = i * model->siesta.atoms_per_job + model->siesta.atoms_per_job;
@@ -1763,9 +1767,6 @@
         // call the fdf save bit....
         file_save_as(filename, model);
 
-        //grab current grid_config_pak
-        struct grid_config_pak * grid_pak;
-
         //get job directory
         siesta_make_runscript(model->basename, sysenv.cwd, grid_pak);
 
@@ -1851,12 +1852,11 @@
     int i, jobID;
     int total_files;
     gchar * filename, * orig_basename, *queuepath, *jobID_string;
+    struct grid_config_pak * grid_pak;
 
     total_files = model->num_atoms / model->siesta.atoms_per_job +1;
 
     orig_basename = g_strdup(model->basename);
-
-    struct grid_config_pak * grid_pak;
 
     //default jobstorage dir??
     //"$homedir/.gdis_jobs/  ?
