--- kmess/kmessview.h.orig	Sun Jun  4 15:46:03 2006
+++ kmess/kmessview.h	Sun Jun  4 15:59:14 2006
@@ -187,6 +187,7 @@
       private:
         KMessView   *kmessView_;
     };
+    friend class ToolTip;
 
     // Reference to the current tooltip
     ToolTip         *toolTip_;
