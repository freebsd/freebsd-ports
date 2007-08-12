--- taskfunc.c.bak	2007-08-12 18:49:55.000000000 +0200
+++ taskfunc.c	2007-08-12 18:51:16.000000000 +0200
@@ -38,13 +38,13 @@
 {
 	ManItem ** buffer;
 	int i,j,count;
-	int display_section_ID;
+	intptr_t display_section_ID;
 
 	pthread_mutex_lock(&context_lock);
-	switch ((int)context->get_value("display_section_policy")) {
+	switch ((intptr_t)context->get_value("display_section_policy")) {
 	case 0: display_section_ID = ~0;break;
-	case 1: display_section_ID = ~(int)(context->get_value("display_section"));break;
-	case 2: display_section_ID = (int)context->get_value("display_section"); break;
+	case 1: display_section_ID = ~(intptr_t)(context->get_value("display_section"));break;
+	case 2: display_section_ID = (intptr_t)context->get_value("display_section"); break;
 	default: fprintf(stderr,"warning: init_man_data: \"display_section_policy\" "
 					 "have invalid value %d",context->get_value("display_section_policy"));
 	display_section_ID = ~0;
