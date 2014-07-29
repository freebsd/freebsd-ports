--- builds/unix/detect.mk.orig	2013-03-21 13:55:46.000000000 -0500
+++ builds/unix/detect.mk	2013-05-12 17:58:34.000000000 -0500
@@ -22,6 +22,9 @@
                      $(wildcard /usr/sbin/init) \
                      $(wildcard /dev/null) \
                      $(wildcard /hurd/auth))
+  # FreeBSD is "unix" so just mandate this to fix the build in
+  # jails that do not have init (see PR#113470).
+  is_unix := true
   ifneq ($(is_unix),)
 
     PLATFORM := unix
@@ -81,9 +84,9 @@
   ifdef must_configure
     ifneq ($(have_Makefile),)
       # we are building FT2 not in the src tree
-	      $(CONFIG_SHELL) $(TOP_DIR)/builds/unix/configure $(value CFG)
+      #      $(CONFIG_SHELL) $(TOP_DIR)/builds/unix/configure $(value CFG)
     else
-	      cd builds/unix; $(CONFIG_SHELL) ./configure $(value CFG)
+      #     cd builds/unix; $(CONFIG_SHELL) ./configure $(value CFG)
     endif
   endif
 
