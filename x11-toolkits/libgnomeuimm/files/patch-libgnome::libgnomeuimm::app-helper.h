--- libgnomeui/libgnomeuimm/app-helper.h.orig	Wed Jul 23 11:41:05 2003
+++ libgnomeui/libgnomeuimm/app-helper.h	Wed Jul 23 11:41:37 2003
@@ -53,7 +53,7 @@
 /*** Derived GnomeUIInfo
  * Note: When deriving this, you must not add any fields or add any virtuals
  */
-class Info : protected GnomeUIInfo
+class Info : public GnomeUIInfo
 {
   friend class InfoData;
   friend class Array<Info>;
