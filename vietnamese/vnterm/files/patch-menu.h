--- menu.h.orig	Mon Aug 21 08:47:47 2000
+++ menu.h	Sat Feb 10 05:32:41 2001
@@ -94,6 +94,37 @@
 /*
  * items in vt100 mode menu
  */
+#ifndef NO_VIETNAMESE
+#define vtMenu_vnfilterkeyboard 0
+#define vtMenu_vnfilterscreen 1
+#define vtMenu_line3 2
+#define vtMenu_scrollbar 3
+#define vtMenu_jumpscroll 4
+#define vtMenu_reversevideo 5
+#define vtMenu_autowrap 6
+#define vtMenu_reversewrap 7
+#define vtMenu_autolinefeed 8
+#define vtMenu_appcursor 9
+#define vtMenu_appkeypad 10
+#define vtMenu_scrollkey 11
+#define vtMenu_scrollttyoutput 12
+#define vtMenu_allow132 13
+#define vtMenu_cursesemul 14
+#define vtMenu_visualbell 15
+#define vtMenu_marginbell 16
+#define vtMenu_altscreen 17
+#ifndef NO_ACTIVE_ICON
+#define vtMenu_activeicon 18
+#endif /* NO_ACTIVE_ICON */
+#define vtMenu_line1 19
+#define vtMenu_softreset 20
+#define vtMenu_hardreset 21
+#define vtMenu_clearsavedlines 22
+#define vtMenu_line2 23
+#define vtMenu_tekshow 24
+#define vtMenu_tekmode 25
+#define vtMenu_vthide 26
+#else /* NO_VIETNAMESE */
 #define vtMenu_scrollbar 0
 #define vtMenu_jumpscroll 1
 #define vtMenu_reversevideo 2
@@ -120,6 +151,7 @@
 #define vtMenu_tekshow 21
 #define vtMenu_tekmode 22
 #define vtMenu_vthide 23
+#endif /* NO_VIETNAMESE */
 
 /*
  * items in vt100 font menu
@@ -278,6 +310,24 @@
   update_menu_item (term->screen.vtMenu, \
 		    vtMenuEntries[vtMenu_tekshow].widget, \
 		    term->screen.Tshow)
+
+#ifndef NO_VIETNAMESE
+#define update_vnfilterkeyboard() \
+  update_menu_item (term->screen.vtMenu, \
+                    vtMenuEntries[vtMenu_vnfilterkeyboard].widget, \
+                    vn_filter_keyboard)
+
+/* Keep this around just for future reference */
+#define set_vnfilterimmediate_sensitivity(val) \
+  set_sensitivity (term->screen.vtMenu,\
+                   vtMenuEntries[vtMenu_vnfilterimmediate].widget, (val))
+
+#define update_vnfilterscreen() \
+  update_menu_item (term->screen.vtMenu, \
+                    vtMenuEntries[vtMenu_vnfilterscreen].widget, \
+                    vn_filter_screen)
+
+#endif /* NO_VIETNAMESE */
 
 #define update_vttekmode() { \
     update_menu_item (term->screen.vtMenu, \
