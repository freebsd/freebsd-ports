--- src/totem.c.orig	Sat Oct 21 22:10:07 2006
+++ src/totem.c	Sat Oct 21 22:11:56 2006
@@ -339,7 +339,11 @@
 
 	g_object_get (G_OBJECT (totem->bvw),
 			"mediadev", &device, NULL);
+#if defined (__FreeBSD__)
+	cmd = g_strdup_printf ("cdcontrol -f %s eject", device);
+#else
 	cmd = g_strdup_printf ("eject %s", device);
+#endif
 	g_free (device);
 
 	if (g_spawn_command_line_sync (cmd, NULL, NULL, NULL, &err) == FALSE)
