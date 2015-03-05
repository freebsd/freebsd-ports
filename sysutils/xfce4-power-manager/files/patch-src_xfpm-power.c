From: Eric Koegel <eric.koegel@gmail.com>
Date: Mon, 1 Sep 2014 20:19:15 +0300
Subject: [PATCH] Use XScreenSaverSuspend and XTestFakeKeyEvent (Bug 11083)

--- src/xfpm-power.c.orig	2014-12-01 11:33:52 UTC
+++ src/xfpm-power.c
@@ -63,6 +63,13 @@
 #include "xfpm-suspend.h"
 #include "xfpm-brightness.h"
 
+#ifdef HAVE_LIBXTST
+#include "X11/extensions/XTest.h"
+#endif
+
+#ifdef HAVE_LIBXSS
+#include <X11/extensions/scrnsaver.h>
+#endif  /* HAVE_LIBXSS */
 
 static void xfpm_power_finalize     (GObject *object);
 
@@ -112,6 +119,8 @@ struct XfpmPowerPrivate
     EggIdletime     *idletime;
 
     gboolean	     inhibited;
+    gboolean	     screensaver_inhibited;
+    gulong	     screensaver_id;
 
     XfpmNotify	    *notify;
 #ifdef ENABLE_POLKIT
@@ -886,10 +895,106 @@ xfpm_power_remove_device (XfpmPower *pow
     g_hash_table_remove (power->priv->hash, object_path);
 }
 
+static gboolean
+idle_reset_screen_saver (XfpmPower *power)
+{
+    Display *dpy = gdk_x11_get_default_xdisplay ();
+
+    TRACE("entering");
+
+    XResetScreenSaver (dpy);
+
+#ifdef HAVE_LIBXTST
+    /* keycode of 255 does not map to any actual key,
+     * this works for xscreensaver */
+    XTestFakeKeyEvent (dpy, 255, TRUE, 0);
+    XTestFakeKeyEvent (dpy, 255, FALSE, 0);
+#endif /* HAVE_LIBXTST */
+
+    XFlush (dpy);
+
+    /* continue until we're removed */
+    return TRUE;
+}
+
+static void
+screen_saver_suspend(XfpmPower *power, gboolean suspend)
+{
+#ifndef HAVE_LIBXSS
+    TRACE("!HAVE_XSS");
+#else
+    int event, dummy, major, minor;
+    Display *dpy = gdk_x11_get_default_xdisplay();
+
+    TRACE("entering");
+
+    if (XScreenSaverQueryExtension(dpy, &event, &dummy) != TRUE ||
+        XScreenSaverQueryVersion(dpy, &major, &minor) != TRUE)
+    {
+        XFPM_DEBUG ("XScreenSaverQueryExtension or XScreenSaverQueryVersion call failed");
+    }
+
+    /* XScreenSaverSuspend was introduced in MIT-SCREEN-SAVER 1.1 */
+    if (major < 1 || (major == 1 && minor < 1))
+    {
+        XFPM_DEBUG ("version %d.%d not supported", major, minor);
+    }
+
+    XFPM_DEBUG ("XScreenSaverSuspend: %s", suspend ? "TRUE" : "FALSE");
+    XScreenSaverSuspend(dpy, suspend);
+#endif /* HAVE_LIBXSS */
+
+    if (power->priv->screensaver_id != 0)
+    {
+        g_source_remove (power->priv->screensaver_id);
+        power->priv->screensaver_id = 0;
+    }
+
+    if (suspend)
+    {
+        /* Reset the screensaver timers every so often so they don't activate */
+        power->priv->screensaver_id = g_timeout_add_seconds (20,
+                                                             (GSourceFunc)idle_reset_screen_saver,
+                                                             power);
+    }
+}
+
 static void
 xfpm_power_inhibit_changed_cb (XfpmInhibit *inhibit, gboolean is_inhibit, XfpmPower *power)
 {
-    power->priv->inhibited = is_inhibit;
+    if (power->priv->inhibited != is_inhibit)
+    {
+        power->priv->inhibited = is_inhibit;
+
+        DBG ("is_inhibit %s, screensaver_inhibited %s, presentation_mode %s",
+	      power->priv->inhibited ? "TRUE" : "FALSE",
+	      power->priv->screensaver_inhibited ? "TRUE" : "FALSE",
+	      power->priv->presentation_mode ? "TRUE" : "FALSE");
+
+        /* If we are inhibited make sure we inhibit the screensaver too */
+        if (is_inhibit)
+        {
+            if (!power->priv->screensaver_inhibited)
+            {
+                screen_saver_suspend (power, TRUE);
+                power->priv->screensaver_inhibited = TRUE;
+            }
+        }
+        else
+        {
+            /* Or make sure we remove the screensaver inhibit */
+            if (power->priv->screensaver_inhibited && !power->priv->presentation_mode)
+            {
+                screen_saver_suspend (power, FALSE);
+                power->priv->screensaver_inhibited = FALSE;
+            }
+        }
+    }
+
+    DBG ("is_inhibit %s, screensaver_inhibited %s, presentation_mode %s",
+	 power->priv->inhibited ? "TRUE" : "FALSE",
+	 power->priv->screensaver_inhibited ? "TRUE" : "FALSE",
+	 power->priv->presentation_mode ? "TRUE" : "FALSE");
 }
 
 static void
@@ -1270,6 +1375,12 @@ xfpm_power_finalize (GObject *object)
 
     g_object_unref(power->priv->dpms);
 
+    if (power->priv->screensaver_id != 0)
+    {
+	g_source_remove (power->priv->screensaver_id);
+	power->priv->screensaver_id = 0;
+    }
+
     G_OBJECT_CLASS (xfpm_power_parent_class)->finalize (object);
 }
 
@@ -1375,24 +1486,49 @@ xfpm_power_change_presentation_mode (Xfp
     if (power->priv->presentation_mode == presentation_mode)
         return;
 
-    XFPM_DEBUG ("presentation mode %s, changing to %s",
-                power->priv->presentation_mode ? "TRUE" : "FALSE",
-                presentation_mode ? "TRUE" : "FALSE");
-
     power->priv->presentation_mode = presentation_mode;
 
     /* presentation mode inhibits dpms */
     xfpm_dpms_inhibit (power->priv->dpms, presentation_mode);
 
-    if (presentation_mode == FALSE)
+    DBG ("is_inhibit %s, screensaver_inhibited %s, presentation_mode %s",
+	 power->priv->inhibited ? "TRUE" : "FALSE",
+	 power->priv->screensaver_inhibited ? "TRUE" : "FALSE",
+	 power->priv->presentation_mode ? "TRUE" : "FALSE");
+
+    if (presentation_mode)
     {
-        EggIdletime *idletime;
+	/* presentation mode inhibits the screensaver */
+	if (!power->priv->screensaver_inhibited)
+	{
+	    screen_saver_suspend (power, TRUE);
+	    power->priv->screensaver_inhibited = TRUE;
+	}
+    }
+    else
+    {
+	EggIdletime *idletime;
+
+	/* make sure we remove the screensaver inhibit */
+	if (power->priv->screensaver_inhibited && !power->priv->inhibited)
+	{
+	    DBG("here");
+	    screen_saver_suspend (power, FALSE);
+	    power->priv->screensaver_inhibited = FALSE;
+	}
+
+	/* reset the timers */
         idletime = egg_idletime_new ();
         egg_idletime_alarm_reset_all (idletime);
 
         g_object_unref (idletime);
     }
 
+    DBG ("is_inhibit %s, screensaver_inhibited %s, presentation_mode %s",
+	 power->priv->inhibited ? "TRUE" : "FALSE",
+	 power->priv->screensaver_inhibited ? "TRUE" : "FALSE",
+	 power->priv->presentation_mode ? "TRUE" : "FALSE");
+
     xfpm_update_blank_time (power);
 }
 
