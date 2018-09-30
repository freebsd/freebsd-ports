--- src/mksary.c.orig	2004-06-11 18:57:28 UTC
+++ src/mksary.c
@@ -59,7 +59,7 @@ CodesetFunc codeset_func_tab[] = {
 static SaryIpointFunc	dispatch_codeset_func	(const gchar *codeset);
 static SaryBuilder*	new_builder		(const gchar *file_name, 
 						 const gchar *array_name);
-static void		index			(SaryBuilder *builder,
+static void		mk_index		(SaryBuilder *builder,
 						 const gchar *file_name,
 						 const gchar *array_name);
 static void		sort			(SaryBuilder *builder,
@@ -149,7 +149,7 @@ new_builder (const gchar *file_name, const gchar *arra
 }
 
 static void
-index (SaryBuilder *builder,
+mk_index (SaryBuilder *builder,
        const gchar *file_name, 
        const gchar *array_name)
 {
@@ -186,7 +186,7 @@ index_and_sort (SaryBuilder *builder,
 		const gchar *file_name, 
 		const gchar *array_name)
 {
-    index(builder, file_name, array_name);
+    mk_index(builder, file_name, array_name);
     sort(builder, file_name, array_name);
 }
 
@@ -358,7 +358,7 @@ parse_options (int argc, char **argv)
 	    show_help();
 	    break;
 	case 'i':
-	    process = index;
+	    process = mk_index;
 	    break;
 	case 'l':
 	    ipoint_func = sary_ipoint_line;
