--- ./index/io.c.orig	2000-08-14 23:03:58.000000000 +0000
+++ ./index/io.c	2014-01-27 21:40:18.000000000 +0000
@@ -360,7 +360,7 @@
 
 
 
-read_filters(index_dir, dofilter)
+void read_filters(index_dir, dofilter)
 char	*index_dir;
 int	dofilter;
 {
@@ -1450,7 +1450,7 @@
 	return e->index;
 }
 
-insert_filename(name, name_index)
+void insert_filename(name, name_index)
 	char	*name;
 	int	name_index;
 {
@@ -1502,7 +1502,7 @@
 	(*pe)->index = name_index;
 }
 
-change_filename(name, len, index, newname)
+void change_filename(name, len, index, newname)
 	char	*name;
 	int	len;
 	int	index;
@@ -1524,7 +1524,7 @@
 	return;
 }
 
-delete_filename(name, name_index)
+void delete_filename(name, name_index)
 	char	*name;
 	int	name_index;
 {
