--- config.mk.orig	2024-03-25 05:36:59 UTC
+++ config.mk
@@ -98,10 +98,10 @@ PKGS += gthread-2.0
 # Packages required to build luakit.
 PKGS += gtk+-3.0
 PKGS += gthread-2.0
-PKGS += webkit2gtk-4.1
+PKGS += webkit2gtk-4.0
 PKGS += sqlite3
 PKGS += $(LUA_PKG_NAME)
-PKGS += javascriptcoregtk-4.1
+PKGS += javascriptcoregtk-4.0

 # Check user has correct packages installed (and found by pkg-config).
 PKGS_OK := $(shell $(PKG_CONFIG) --print-errors --exists $(PKGS) && echo 1)
