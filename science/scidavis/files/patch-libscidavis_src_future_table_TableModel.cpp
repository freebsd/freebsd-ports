--- libscidavis/src/future/table/TableModel.cpp.orig	2018-10-17 03:28:35 UTC
+++ libscidavis/src/future/table/TableModel.cpp
@@ -101,11 +101,11 @@ QVariant TableModel::data(const QModelIn
 					postfix = " " + tr("(masked)");
 				if(col_ptr->isInvalid(row))
 					return QVariant(tr("invalid cell (ignored in all operations)","tooltip string for invalid rows") + postfix);
-				[[fallthrough]]
+				[[fallthrough]];
 		case Qt::EditRole:
 				if(!d_formula_mode && col_ptr->isInvalid(row))
 					return QVariant();
-				 [[fallthrough]]
+				 [[fallthrough]];
 		case Qt::DisplayRole:
 			{
 				if(d_formula_mode)
