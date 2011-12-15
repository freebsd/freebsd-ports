--- goldlib/gmb3/gmohuds.h.orig	2011-12-15 12:15:21.000000000 +0700
+++ goldlib/gmb3/gmohuds.h	2011-12-15 12:17:29.000000000 +0700
@@ -252,9 +252,9 @@
 
   void realloc_pm_scan();
 
-  void update_netecho(char* __name, msgn_t __hdridx, int __delete);
+  void update_netecho(const char* __name, msgn_t __hdridx, int __delete);
 
-  void test_open(gfile &__file, char* __fname, int __oaccess);
+  void test_open(gfile &__file, const char* __fname, int __oaccess);
   void raw_open(int __oaccess=0, int __all=true);
   void raw_close();
   void refresh();
