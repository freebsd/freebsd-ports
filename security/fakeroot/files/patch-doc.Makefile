--- doc/Makefile.am      Tue Sep  2 06:00:59 2003
+++ doc/Makefile.am   Thu Mar 11 13:23:43 2004
@@ -1,5 +1,4 @@
 AUTOMAKE_OPTIONS=foreign
-SUBDIRS = es fr sv
 
 man_MANS = faked.1 fakeroot.1
 
--- doc/Makefile.in      Sun Feb 22 23:18:19 2004
+++ doc/Makefile.in   Thu Mar 11 13:23:47 2004
@@ -161,7 +161,6 @@
 target_os = @target_os@
 target_vendor = @target_vendor@
 AUTOMAKE_OPTIONS = foreign
-SUBDIRS = es fr sv
 man_MANS = faked.1 fakeroot.1
 
 #another automake bug workaround
