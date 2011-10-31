--- ./src/widgets/cclineedit.cpp	2011/08/31 19:42:34	1250623
+++ ./src/widgets/cclineedit.cpp	2011/09/02 16:27:48	1250995
@@ -582,7 +582,7 @@
 }
 
 #define SIZE_LIMITED_NAME sizeLimitedName( (_cc&&_cc->_tableView)?_cc->_tableView->font():QFont(), \
-    (_cc&&_cc->_tableView)? ((_cc->_tableView->width()/2-50)): 900000000000)
+    (_cc&&_cc->_tableView)? ((_cc->_tableView->width()/2-50)): INT_MAX)
 
 void SVCCLineEdit::fillKstObjects()
 {
