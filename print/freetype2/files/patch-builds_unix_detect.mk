--- builds/unix/detect.mk.orig	2015-03-11 01:47:10.000000000 -0400
+++ builds/unix/detect.mk	2015-06-16 05:45:17.176216000 -0400
@@ -22,6 +22,9 @@
                      $(wildcard /usr/sbin/init) \
                      $(wildcard /dev/null) \
                      $(wildcard /hurd/auth))
+  # FreeBSD is "unix" so just mandate this to fix the build in
+  # jails that do not have init (see PR#113470).
+  is_unix := true
   ifneq ($(is_unix),)
 
     PLATFORM := unix
@@ -81,12 +84,12 @@
   ifdef must_configure
     ifneq ($(have_Makefile),)
       # we are building FT2 not in the src tree
-	      CONFIG_SHELL="$(CONFIG_SHELL)" \
-	        $(CONFIG_SHELL) $(TOP_DIR)/builds/unix/configure $(value CFG)
+#	      CONFIG_SHELL="$(CONFIG_SHELL)" \
+#	        $(CONFIG_SHELL) $(TOP_DIR)/builds/unix/configure $(value CFG)
     else
-	      cd builds/unix; \
-	      CONFIG_SHELL="$(CONFIG_SHELL)" \
-	        $(CONFIG_SHELL) ./configure $(value CFG)
+#	      cd builds/unix; \
+#	      CONFIG_SHELL="$(CONFIG_SHELL)" \
+#	        $(CONFIG_SHELL) ./configure $(value CFG)
     endif
   endif
 
