--- g10/openfile.c.orig	Tue Nov 28 07:13:53 2006
+++ g10/openfile.c	Tue Nov 28 07:18:30 2006
@@ -144,8 +144,8 @@
 
     s = _("Enter new filename");
 
-    n = strlen(s) + namelen + 10;
     defname = name && namelen? make_printable_string( name, namelen, 0): NULL;
+    n = strlen(s) + (defname?strlen (defname):0) + 10;
     prompt = xmalloc(n);
     if( defname )
 	sprintf(prompt, "%s [%s]: ", s, defname );
