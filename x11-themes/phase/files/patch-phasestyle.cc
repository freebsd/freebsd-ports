--- phasestyle/phasestyle.cc.orig	Mon Jul  5 19:38:55 2004
+++ phasestyle/phasestyle.cc	Sun Jul 25 20:58:33 2004
@@ -1085,7 +1085,7 @@
       case KPE_SliderHandle: {
           const QSlider* slider = dynamic_cast<const QSlider*>(widget);
           if (slider) {
-              QColor color = (slider==hover_)
+              QColor color = ((QWidget*)slider==hover_)
                   ? group.button().light(contrast)
                   : group.button();
               if (slider->orientation() == Horizontal) {
@@ -1619,7 +1619,7 @@
 
           sunken = (active == SC_ComboBoxArrow);
           drawPhaseButton(painter, x, y, w, h, group,
-                          (combo==hover_)
+                          ((QWidget*)combo==hover_)
                           ? group.button().light(contrast)
                           : group.button(), sunken);
 
@@ -1774,7 +1774,7 @@
               if (reverse_) subrect.moveLeft(spin->upRect().left());
               drawPhaseBevel(painter, subrect.x(), subrect.y(),
                              subrect.width(), subrect.height(), group,
-                             (spin==hover_)
+                             ((QWidget*)spin==hover_)
                              ? group.button().light(contrast)
                              : group.button(), false, false, false);
           }
