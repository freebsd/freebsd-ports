
# HG changeset patch
# User Jorge Arellano Cid  <jcid@dillo.org>
# Date 1416942594 0
# Node ID 630f02e6341e2ee830de042a811a62491c0a7a56
# Parent  5edad033981ff7dfc1886586dd0ef0c252d86fa3
Fix a problem with FLTK's fl_oldfocus variable

http://lists.dillo.org/pipermail/dillo-dev/2014-November/010299.html

and, from commit text for changeset eb902ac9fc66
"Starting with fltk-1.3.3, we can't use fl_oldfocus, this patch
fixes this problem.

IOW. this patch is necessary to link with fltk-1.3.3."

diff -r 5edad033981f -r 630f02e6341e dw/fltkviewbase.cc
--- dw/fltkviewbase.cc.orig	Wed Apr 09 16:32:52 2014 -0300
+++ dw/fltkviewbase.cc	Tue Nov 25 19:09:54 2014 +0000
@@ -27,8 +27,6 @@
 #include <stdio.h>
 #include "../lout/msg.h"
 
-extern Fl_Widget* fl_oldfocus;
-
 using namespace lout::object;
 using namespace lout::container::typed;
 
@@ -364,7 +362,9 @@
       }
       return 1;
    case FL_UNFOCUS:
-      focused_child = fl_oldfocus;
+      // FLTK delivers UNFOCUS to the previously focused widget
+      if (find(Fl::focus()) < children())
+         focused_child = Fl::focus(); // remember the focused child!
       return 0;
    case FL_KEYBOARD:
       if (Fl::event_key() == FL_Tab)

