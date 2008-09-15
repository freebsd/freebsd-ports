--- xdiskusage.C.orig	2008-09-15 19:21:03.000000000 +0000
+++ xdiskusage.C	2008-09-15 19:23:54.000000000 +0000
@@ -988,7 +988,7 @@
 void OutputWindow::sort_cb(Fl_Widget* o, void*v) {
   OutputWindow* d = (OutputWindow*)(o->window());
   int (*compare)(const Node*, const Node*);
-  switch ((int)v) {
+  switch ((unsigned long)v) {
   case 's': compare = largestfirst; break;
   case 'r': compare = smallestfirst; break;
   case 'a': compare = alphabetical; break;
@@ -1001,7 +1001,7 @@
 
 void OutputWindow::columns_cb(Fl_Widget* o, void*v) {
   OutputWindow* d = (OutputWindow*)(o->window());
-  int n = (int)v;
+  unsigned long n = (unsigned long)v;
   ::ncols = n;
   if (n == d->ncols) return;
   if (d->current_depth > d->root_depth+n-1) {
