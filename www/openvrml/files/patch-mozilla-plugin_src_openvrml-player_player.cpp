--- mozilla-plugin/src/openvrml-player/player.cpp.orig	Tue Nov 15 00:16:02 2005
+++ mozilla-plugin/src/openvrml-player/player.cpp	Tue Nov 15 00:21:07 2005
@@ -22,14 +22,14 @@
 # include <boost/lexical_cast.hpp>
 # include <boost/spirit.hpp>
 # include <boost/spirit/phoenix.hpp>
+# include <openvrml/browser.h>
+# include <openvrml/gl/viewer.h>
 # include <unistd.h>
 # include <argp.h>
 # include <X11/keysym.h>
 # include <gdk/gdkx.h>
 # include <gtk/gtk.h>
 # include <gtk/gtkgl.h>
-# include <openvrml/browser.h>
-# include <openvrml/gl/viewer.h>
 
 namespace {
 
