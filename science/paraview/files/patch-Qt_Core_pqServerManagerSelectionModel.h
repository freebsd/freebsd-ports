--- Qt/Core/pqServerManagerSelectionModel.h.orig	2011-04-13 16:16:49.000000000 +0000
+++ Qt/Core/pqServerManagerSelectionModel.h
@@ -68,7 +68,7 @@ public:
     Clear          = QItemSelectionModel::Clear,
     Select         = QItemSelectionModel::Select,
     Deselect       = QItemSelectionModel::Deselect, 
-    ClearAndSelect = Clear | Select
+    ClearAndSelect = static_cast<int>(Clear) | static_cast<int>(Select)
   };
   Q_DECLARE_FLAGS(SelectionFlags, SelectionFlag)
 
