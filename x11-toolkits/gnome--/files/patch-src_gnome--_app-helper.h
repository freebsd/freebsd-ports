--- src/gnome--/app-helper.h.orig	Sun Jul 27 13:56:52 2003
+++ src/gnome--/app-helper.h	Sun Jul 27 14:00:25 2003
@@ -40,7 +40,7 @@
 template<class T_Info>
 class Array;
 
-class Info : protected GnomeUIInfo
+class Info : public GnomeUIInfo
 {
   /* Note when deriving this, you must not add any fields nor may you
      add any virtuals */
