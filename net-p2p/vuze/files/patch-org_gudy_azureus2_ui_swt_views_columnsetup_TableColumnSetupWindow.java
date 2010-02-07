--- org/gudy/azureus2/ui/swt/views/columnsetup/TableColumnSetupWindow.java.orig	2009-04-09 00:37:38.000000000 -0500
+++ org/gudy/azureus2/ui/swt/views/columnsetup/TableColumnSetupWindow.java	2009-07-11 09:51:14.000000000 -0500
@@ -137,7 +137,7 @@
 
 				tableColumn = (TableColumnCore) row.getDataSource();
 
-				if (event.image != null && !Constants.isLinux) {
+				if (event.image != null && (!Constants.isLinux || !Constants.isFreeBSD)) {
 					try {
   					GC gc = new GC(event.image);
   					try {
@@ -391,7 +391,7 @@
 
 		expandFilters.addListener(SWT.Expand, new Listener() {
 			public void handleEvent(Event event) {
-				Utils.execSWTThreadLater(Constants.isLinux ? 250 : 0, new AERunnable() {
+				Utils.execSWTThreadLater((Constants.isLinux || Constants.isFreeBSD) ? 250 : 0, new AERunnable() {
 					public void runSupport() {
 						shell.layout(true, true);
 					}
@@ -400,7 +400,7 @@
 		});
 		expandFilters.addListener(SWT.Collapse, new Listener() {
 			public void handleEvent(Event event) {
-				Utils.execSWTThreadLater(Constants.isLinux ? 250 : 0, new AERunnable() {
+				Utils.execSWTThreadLater((Constants.isLinux || Constants.isFreeBSD) ? 250 : 0, new AERunnable() {
 					public void runSupport() {
 						shell.layout(true, true);
 					}
