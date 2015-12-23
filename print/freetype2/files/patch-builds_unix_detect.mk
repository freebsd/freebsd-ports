--- builds/unix/detect.mk.orig	2015-09-25 07:58:57.000000000 +0200
+++ builds/unix/detect.mk	2015-10-04 12:35:05.733855000 +0200
@@ -22,6 +22,9 @@
                      $(wildcard /usr/sbin/init) \
                      $(wildcard /dev/null) \
                      $(wildcard /hurd/auth))
+  # FreeBSD is "unix" so just mandate this to fix the build in
+  # jails that do not have init (see PR#113470).
+  is_unix := true
   ifneq ($(is_unix),)
 
     PLATFORM := unix
@@ -80,10 +83,10 @@
   ifdef must_configure
     ifneq ($(have_Makefile),)
       # we are building FT2 not in the src tree
-	        $(TOP_DIR)/builds/unix/configure $(value CFG)
+#	        $(TOP_DIR)/builds/unix/configure $(value CFG)
     else
-	      cd builds/unix; \
-	        ./configure $(value CFG)
+#	      cd builds/unix; \
+#	        ./configure $(value CFG)
     endif
   endif
 
