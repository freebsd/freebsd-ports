--- rdf.c.orig	Sat Jul 19 05:08:36 2003
+++ rdf.c	Sat Jul 19 05:09:00 2003
@@ -445,8 +445,8 @@
   printf("calculate_rdf(): a = %f b = %f c = %f alpha = %f beta = %f gamma = %f\n",
             model->pbc[0], model->pbc[1], model->pbc[2],
             model->pbc[3], model->pbc[4], model->pbc[5]);
-  printf("calculate_rdf(): latmat[0] = %f latmat[1] = %f latmat[2] = %f
-          \ncalculate_rdf(): latmat[3] = %f latmat[4] = %f latmat[5] = %f
+  printf("calculate_rdf(): latmat[0] = %f latmat[1] = %f latmat[2] = %f\
+          \ncalculate_rdf(): latmat[3] = %f latmat[4] = %f latmat[5] = %f\
           \ncalculate_rdf(): latmat[6] = %f latmat[7] = %f latmat[8] = %f\n",
             model->latmat[0], model->latmat[1], model->latmat[2],
             model->latmat[3], model->latmat[4], model->latmat[5],
