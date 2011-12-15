--- goldlib/gmb3/gmohuds2.cpp.orig	2011-12-15 12:13:53.000000000 +0700
+++ goldlib/gmb3/gmohuds2.cpp	2011-12-15 12:14:22.000000000 +0700
@@ -48,7 +48,7 @@
 //  ------------------------------------------------------------------
 
 template <class msgn_t, class rec_t, class attr_t, class board_t, class last_t, bool __HUDSON>
-void _HudsWide<msgn_t, rec_t, attr_t, board_t, last_t, __HUDSON>::test_open(gfile &__file, char* __fname, int __oaccess)
+void _HudsWide<msgn_t, rec_t, attr_t, board_t, last_t, __HUDSON>::test_open(gfile &__file, const char* __fname, int __oaccess)
 {
   GFTRK("HudsTestOpen");
 
