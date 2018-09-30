--- sary/builder.c.orig	2005-01-28 08:50:24 UTC
+++ sary/builder.c
@@ -45,7 +45,7 @@ struct _SaryBuilder{
     gpointer		progress_func_data;
 };
 
-static SaryInt	index		(SaryBuilder	*builder, 
+static SaryInt	sary_index	(SaryBuilder	*builder, 
 				 SaryProgress	*progress,
 				 SaryWriter	*writer);
 static void	progress_quiet	(SaryProgress	*progress);
@@ -124,7 +124,7 @@ sary_builder_index (SaryBuilder *builder)
 			  builder->progress_func, 
 			  builder->progress_func_data);
 
-    count = index(builder, progress, writer);
+    count = sary_index(builder, progress, writer);
 
     sary_progress_destroy(progress);
     sary_writer_destroy(writer);
@@ -219,7 +219,7 @@ sary_builder_connect_progress (SaryBuilder *builder,
 }
 
 static SaryInt
-index (SaryBuilder *builder, SaryProgress *progress, SaryWriter *writer)
+sary_index (SaryBuilder *builder, SaryProgress *progress, SaryWriter *writer)
 {
     gchar *bof, *cursor;
     SaryInt count;
