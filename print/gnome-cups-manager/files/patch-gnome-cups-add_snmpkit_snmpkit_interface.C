--- gnome-cups-add/snmpkit/snmpkit_interface.C.orig	Fri Aug  6 23:58:14 2004
+++ gnome-cups-add/snmpkit/snmpkit_interface.C	Fri Aug  6 23:58:36 2004
@@ -508,7 +508,7 @@
 void **sk_table_get(SNMPTABLE *st){
   std::list<void*> vals;
   from_c(st)->get(vals);
-  void **retval=new (void*)[vals.size()+1];
+  void **retval=new void* [vals.size()+1];
   retval[vals.size()]=NULL;
   int i=0;
   for(std::list<void*>::iterator cur=vals.begin();cur!=vals.end();cur++,i++)
