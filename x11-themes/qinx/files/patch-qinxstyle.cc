--- qinxstyle/qinxstyle.cc.orig	Sun Jul 25 21:12:29 2004
+++ qinxstyle/qinxstyle.cc	Sun Jul 25 21:12:51 2004
@@ -1677,7 +1677,7 @@
           }
 
           PrimitiveElement element;
-          QColor color = (spin==hover_)
+          QColor color = ((QWidget*)spin==hover_)
               ? group.button().light(contrast)
               : group.button();
 
