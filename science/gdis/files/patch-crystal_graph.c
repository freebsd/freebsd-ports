--- crystal_graph.c.orig	Thu Nov 24 15:07:31 2005
+++ crystal_graph.c	Thu Nov  2 00:00:23 2006
@@ -110,6 +110,9 @@
 gdouble run_gulp(GSList *cores, gchar *species)
 {
   struct model_pak *new_model, *result_model;  
+  gchar *cmd;
+  gdouble result;
+
   new_model = g_malloc(sizeof(struct model_pak));
   result_model = g_malloc(sizeof(struct model_pak));
     
@@ -128,13 +131,13 @@
   new_model->periodic = 0;
   
   write_gulp(new_model->gulp.temp_file, new_model);
-  gchar * cmd = g_strdup_printf("%s < %s > %s", sysenv.gulp_path, 
+  cmd = g_strdup_printf("%s < %s > %s", sysenv.gulp_path, 
                                 new_model->gulp.temp_file, new_model->gulp.out_file);
   system(cmd);
   g_free(cmd);
   
   read_gulp_output(new_model->gulp.out_file, result_model);
-  gdouble result = result_model->gulp.energy;
+  result = result_model->gulp.energy;
   model_free(new_model);
   model_free(result_model);
 
@@ -156,6 +159,9 @@
   gint b_images =(gint) model->monty.image_y + 0.5;
   gint c_images =(gint) model->monty.image_z + 0.5;
   
+  gint nr_molecules;
+  gdouble * single_energies;
+
   /* checks */ 
   g_return_val_if_fail(sysenv.gulp_path != NULL, 4);
   g_return_val_if_fail(model != NULL, 1);
@@ -165,7 +171,7 @@
     gui_text_show(ERROR, "Can not calculate a crystal graph for non crystalline models");
     return 3;
   }
-  gint nr_molecules = g_slist_length(model->moles);
+  nr_molecules = g_slist_length(model->moles);
   /* initialize the key chunk to hold the maximum number of  */
   key_chunk = g_mem_chunk_create(gint, 
                                  nr_molecules * nr_molecules *(2*a_images+1)*(2*b_images+1)*(2*c_images+1),
@@ -180,7 +186,7 @@
   type_dreiding_gasteiger(model, DREIDING);
   
   /* calculate the single energies */
-  gdouble * single_energies = g_new0(gdouble, nr_molecules);
+  single_energies = g_new0(gdouble, nr_molecules);
   
   for (mol_iter = model->moles; mol_iter; mol_iter = mol_iter->next)
   {
@@ -218,12 +224,13 @@
             if (pair != NULL)
             {              
               gdouble *key_ptr;
+              gchar * combination;
               key_ptr = g_chunk_new(gdouble, key_chunk);
               *key_ptr = run_gulp(pair, model->gulp.species);
               *key_ptr *= 96.48474; //eV --> kJ / mol
               *key_ptr -= single_energies[m1];
               *key_ptr -= single_energies[m2];
-              gchar * combination = g_strdup_printf(" %i - %i [ %i %i %i ]", m1+1, m2+1, x,y,z);
+              combination = g_strdup_printf(" %i - %i [ %i %i %i ]", m1+1, m2+1, x,y,z);
               g_tree_insert(tree, key_ptr, combination);
             }
           }
