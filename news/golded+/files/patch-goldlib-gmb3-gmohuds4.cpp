--- goldlib/gmb3/gmohuds4.cpp.orig	2011-12-15 12:17:48.000000000 +0700
+++ goldlib/gmb3/gmohuds4.cpp	2011-12-15 12:18:02.000000000 +0700
@@ -29,7 +29,7 @@
 //  ------------------------------------------------------------------
 
 template <class msgn_t, class rec_t, class attr_t, class board_t, class last_t, bool __HUDSON>
-void _HudsWide<msgn_t, rec_t, attr_t, board_t, last_t, __HUDSON>::update_netecho(char* __name, msgn_t __hdridx, int __delete)
+void _HudsWide<msgn_t, rec_t, attr_t, board_t, last_t, __HUDSON>::update_netecho(const char* __name, msgn_t __hdridx, int __delete)
 {
   GFTRK("HudsUpdateNetEcho");
 
