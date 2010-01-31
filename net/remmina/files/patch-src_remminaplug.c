--- src/remminaplug.c.orig	2010-01-21 00:08:01.000000000 +0800
+++ src/remminaplug.c	2010-01-30 21:45:32.000000000 +0800
@@ -466,7 +466,9 @@
 void
 remmina_plug_set_display (RemminaPlug *gp, gint display)
 {
+#ifdef HAVE_LIBSSH
     if (gp->ssh_tunnel->localdisplay) g_free (gp->ssh_tunnel->localdisplay);
     gp->ssh_tunnel->localdisplay = g_strdup_printf ("unix:%i", display);
+#endif
 }
 
