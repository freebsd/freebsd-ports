--- file_cgf.c.orig	Thu Nov 24 13:58:48 2005
+++ file_cgf.c	Thu Nov  2 00:10:25 2006
@@ -188,7 +188,7 @@
   GSList *core_iter, *bond_iter;//,
   GSList *primary_cores = NULL;
   FILE *fp;
-  gint nr_primary_cores = 0, max_bonds = 0, bond_counter = 0, num_tokens = 0, offset_counter = 0;
+  gint nr_primary_cores = 0, max_bonds = 0, bond_counter = 0, num_tokens = 0, offset_counter = 0, total_bonds = 0;
    
   gint *nr_bonds = g_new(gint, g_slist_length(data->cores));
   
@@ -197,6 +197,9 @@
   
   gchar **buff;
   
+  gdouble *bond_strengths;
+  gint *bond_to_values, *bond_offsets;
+
   /* checks and open file */
   g_return_val_if_fail(data != NULL, 1);
   fp = fopen(filename, "wt");
@@ -208,8 +211,6 @@
   fprintf(fp, "alpha= %3.5f beta= %3.5f gamma= %3.5f\n", data->pbc[3] * R2D, data->pbc[4] * R2D, data->pbc[5] * R2D);
   fprintf(fp, "Spacegroup information:      SPGR = %-24s OPT = %i\n", data->sginfo.spacename, data->sginfo.cellchoice);
   
-  gint total_bonds = 0;
-  
   for (core_iter = data->cores; core_iter; core_iter = core_iter->next)
   {
     core = (struct core_pak *)core_iter->data;
@@ -229,9 +230,9 @@
     }
   }
   
-  gdouble * bond_strengths = g_new0(gdouble, total_bonds);
-  gint * bond_to_values =  g_new0(gint, total_bonds);
-  gint * bond_offsets = g_new0(gint, total_bonds * 3);
+  bond_strengths = g_new0(gdouble, total_bonds);
+  bond_to_values =  g_new0(gint, total_bonds);
+  bond_offsets = g_new0(gint, total_bonds * 3);
   
   fprintf(fp, "Nr of centres of mass: %i\n", nr_primary_cores);
   fprintf(fp, "Maximum connectivity: %i\n", max_bonds);
@@ -280,6 +281,8 @@
   gint *bondto; 
   gdouble *bond_offsets;
   gdouble *bond_strengths;
+
+  gint bondto_counter = 0, bond_offsets_counter = 0, total_bonds = 0;
   
   /* checks */
   g_return_val_if_fail(data != NULL, 1);
@@ -366,8 +369,6 @@
   bond_offsets = g_new(gdouble, nr_bond_lines * num_gu * 15);
   //bond_strengths = g_new(gdouble, nr_bond_lines * num_gu * 5);
   
-  gint bondto_counter = 0, bond_offsets_counter = 0;
-  
   /* create GUs a priori  */
   for (n = 0; n < num_gu; ++n)
   {
@@ -442,7 +443,6 @@
     fgetline(fp, line);
   }
 
-  gint total_bonds = 0;
   /* now we create new cores for each bond */
   w = 0;
   for (n = 0; n < num_gu; ++n)
