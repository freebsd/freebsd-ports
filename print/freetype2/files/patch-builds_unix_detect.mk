--- builds/unix/detect.mk.orig	2019-02-23 09:06:06 UTC
+++ builds/unix/detect.mk
@@ -22,6 +22,9 @@ ifeq ($(PLATFORM),ansi)
                      $(wildcard /usr/sbin/init) \
                      $(wildcard /dev/null) \
                      $(wildcard /hurd/auth))
+  # FreeBSD is "unix" so just mandate this to fix the build in
+  # jails that do not have init (see PR#113470).
+  is_unix := true
   ifneq ($(is_unix),)
 
     PLATFORM := unix
@@ -86,10 +89,10 @@ ifeq ($(PLATFORM),unix)
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
 
