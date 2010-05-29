--- support/build.make	2007-01-17 16:25:44.000000000 +0000
+++ support/build.make	2010-01-28 22:51:05.116780927 +0000
@@ -134,10 +134,6 @@
   endif
 endif # !SourceDir
 
-ifeq "$(COMOversion)$(ICCversion)$(GCCversion)" ""
-  $(error unknown C++ compiler)
-endif
-
 ifdef COMOversion
   addinclude = -I$(patsubst $/,%,$(dir $(1))) --preinclude $(notdir $(1))
   make_dep_opt := -MD --no_preproc_only
