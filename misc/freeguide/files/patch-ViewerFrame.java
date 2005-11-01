$FreeBSD$

--- src/program/gui/viewer/ViewerFrame.java	Thu Oct 27 00:18:55 2005
+++ src/program/gui/viewer/ViewerFrame.java	Thu Oct 27 00:34:18 2005
@@ -1502,7 +1502,7 @@
         String[] cmds = Utils.substitute(
             FreeGuide.prefs.commandline.getStrings( "browser_command" ),
             "%filename%",
-            programme.getLink().toString().replace("%","%%") );
+            programme.getLink().toString().replaceAll("%","%%") );
             
         Utils.execNoWait(cmds);
 
