--- filter.h.orig	2019-02-22 18:41:46 UTC
+++ filter.h
@@ -44,7 +44,7 @@
 
 struct filter_item {
     char * eval;
-} * filters;
+};
 
 void show_filters();
 void add_filter(char * criteria);
