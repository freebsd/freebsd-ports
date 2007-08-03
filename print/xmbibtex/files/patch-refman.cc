--- src/refman.cc.orig	2007-08-03 16:51:55.000000000 +0200
+++ refman.cc	2007-08-03 16:52:33.000000000 +0200
@@ -260,7 +260,7 @@
   static Widget fsb_load, ftype, fsb_save, fsb_print;
   XmStringTable str_list;
 
-  switch((int)client_data) {
+  switch((intptr_t)client_data) {
   case 0:    // .................................new;
     XmListDeleteAllItems(liste);
     key=(unsigned long *)realloc(key, sizeof(unsigned long));
@@ -377,7 +377,7 @@
   ref    =new char[100];
   str_list=(XmStringTable) XtMalloc(sizeof(XmString));
 
-  switch((int)client_data) {
+  switch((intptr_t)client_data) {
   case 0:  // ................................add new reference
     b.ClearDummy();
     b.d->doctype=(char *)realloc(b.d->doctype, sizeof("article")+1);
@@ -540,7 +540,7 @@
   gefunden[0]= 0;
   ref        = new char[100];
 
-  switch((int)client_data) {
+  switch((intptr_t)client_data) {
   case 0:    // ................................. search in all fields;
     i=0;
     XtSetArg(args[i], XmNtitle, "Search all fields"); i++;
