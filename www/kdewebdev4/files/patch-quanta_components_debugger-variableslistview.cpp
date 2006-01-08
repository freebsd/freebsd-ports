--- quanta/components/debugger/variableslistview.cpp.orig	Tue Dec 20 16:15:57 2005
+++ quanta/components/debugger/variableslistview.cpp	Tue Dec 20 16:20:08 2005
@@ -215,7 +215,7 @@
   item->setText(VariablesListViewColumns::Name, oldvar->name());
   item->setText(VariablesListViewColumns::Type, oldvar->typeName());
   item->setText(VariablesListViewColumns::Size, oldvar->sizeName());
-  item->setText(VariablesListViewColumns::Value, (newvar->isScalar() ? oldvar->value() : ""));
+  item->setText(VariablesListViewColumns::Value, (newvar->isScalar() ? oldvar->value() : QString()));
   
 }
 
