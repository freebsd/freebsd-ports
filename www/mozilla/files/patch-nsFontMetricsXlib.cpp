$FreeBSD$

As reported by Mikko Rapeli and Tom Vogt at
http://bugzilla.mozilla.org/show_bug.cgi?id=115788 and
http://bugzilla.mozilla.org/show_bug.cgi?id=150339 the X server can
abort when Mozilla requests a huge (scalable) font.  This is also
likely to happen to the X font server, or to Xvnc.

This patch is from
http://bugzilla.mozilla.org/attachment.cgi?id=87432&action=view
.

--- gfx/src/xlib/nsFontMetricsXlib.cpp	Tue Jun 11 16:20:31 2002
+++ gfx/src/xlib/nsFontMetricsXlib.cpp	Thu Jun 13 00:05:47 2002
@@ -99,6 +99,12 @@
 #undef USER_DEFINED
 #define USER_DEFINED "x-user-def"
 
+// This is the scaling factor that we keep fonts limited to against
+// the display size.  If a pixel size is requested that is more than
+// this factor larger than the height of the display, it's clamped to
+// that value instead of the requested size.
+#define FONT_MAX_FONT_SCALE 2
+
 #undef NOISY_FONTS
 #undef REALLY_NOISY_FONTS
 
@@ -1480,7 +1486,12 @@
 
   float app2dev;
   mDeviceContext->GetAppUnitsToDevUnits(app2dev);
+
   mPixelSize = NSToIntRound(app2dev * mFont->size);
+  // Make sure to clamp the pixel size to something reasonable so we
+  // don't make the X server blow up.
+  mPixelSize = PR_MIN(XHeightOfScreen(xxlib_rgb_get_screen(gXlibRgbHandle)) * FONT_MAX_FONT_SCALE, mPixelSize);
+
   mStretchIndex = 4; // Normal
   mStyleIndex = mFont->style;
 
