Index: programs/Xserver/xkb/xkbInit.c
===================================================================
RCS file: /home/ncvs/xfree/xc/programs/Xserver/xkb/xkbInit.c,v
retrieving revision 3.26
retrieving revision 3.27
diff -u -r3.26 -r3.27
--- programs/Xserver/xkb/xkbInit.c	9 Feb 2003 06:29:20 -0000	3.26
+++ programs/Xserver/xkb/xkbInit.c	17 Mar 2003 23:52:27 -0000	3.27
@@ -713,7 +713,7 @@
     if (names->types) names->types = _XkbDupString(names->types);
     if (names->compat) names->compat = _XkbDupString(names->compat);
     if (names->geometry) names->geometry = _XkbDupString(names->geometry);
-    if (names->symbols) names->geometry = _XkbDupString(names->symbols);
+    if (names->symbols) names->symbols = _XkbDupString(names->symbols);
 
     if (defs.model && defs.layout && rules) {
 	XkbComponentNamesRec	rNames;
