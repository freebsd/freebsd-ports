--- toc/src/toc-extract.c.orig	Sun May 26 17:12:20 2002
+++ toc/src/toc-extract.c	Sun May 26 17:12:54 2002
@@ -97,6 +97,9 @@
 
 		stack_el = find_first_element (context, element_list);
 
+		if (stack_el == NULL)
+		    return;
+
 		if (!stack_el->ignore)
 		{
 			print_indent(context->depth);
@@ -189,6 +192,9 @@
 	element_list = list_prepend (element_list, (void *) (SECT5));
 
 	stack_el = find_first_element (context, element_list);
+
+	if (stack_el == NULL)
+	    return;
 	
 	if (stack_el->title_output)
 	{
