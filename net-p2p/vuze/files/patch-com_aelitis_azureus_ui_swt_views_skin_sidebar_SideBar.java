--- com/aelitis/azureus/ui/swt/views/skin/sidebar/SideBar.java.orig	2009-11-18 22:32:26.000000000 -0600
+++ com/aelitis/azureus/ui/swt/views/skin/sidebar/SideBar.java	2009-12-01 11:56:03.000000000 -0600
@@ -110,7 +110,7 @@
 	extends SkinView
 	implements UIUpdatable, ViewTitleInfoListener
 {
-	private static final boolean END_INDENT = Constants.isLinux || Constants.isWindows2000 || Constants.isWindows9598ME;
+	private static final boolean END_INDENT = Constants.isLinux || Constants.isFreeBSD || Constants.isWindows2000 || Constants.isWindows9598ME;
 	
 	private static final boolean USE_PAINTITEM = Utils.isCocoa;
 	
