--- src/c_refform.cc.orig	2007-08-03 16:53:09.000000000 +0200
+++ c_refform.cc	2007-08-03 16:53:36.000000000 +0200
@@ -767,11 +767,11 @@
 }
 
 void reftype_cb(Widget w, XtPointer client_data, XtPointer call_data) {
-  int    rc;
+  intptr_t    rc;
   char   dt[80];
   int    answer=0;
 
-  rc= (int)client_data;
+  rc= (intptr_t)client_data;
   while(w && !XtIsWMShell(w)) w=XtParent(w);
   XtPopdown(w);
   XtDestroyWidget(w);
@@ -850,7 +850,7 @@
 }
 
 void reprint_cb(Widget w, XtPointer client_data, XtPointer call_data) {
-  if ((int)client_data==0) {
+  if ((intptr_t)client_data==0) {
     b.d->reprint=(char *)realloc(b.d->reprint,strlen("IN FILE")+1);
     strcpy(b.d->reprint, "IN FILE");
   }
