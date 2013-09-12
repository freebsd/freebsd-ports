--- org/gudy/azureus2/ui/swt/views/table/painted/TableViewPainted.java.orig	2013-09-10 23:18:13.000000000 +0200
+++ org/gudy/azureus2/ui/swt/views/table/painted/TableViewPainted.java	2013-09-10 23:18:56.000000000 +0200
@@ -2554,9 +2554,6 @@
 	}
 
 	private int getScrollbarsMode() {
-		if (hasGetScrollBarMode) {
-			return cTable.getScrollbarsMode();
-		}
 		return SWT.NONE;
 	}
 
