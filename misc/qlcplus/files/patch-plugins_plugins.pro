- disable plugins that don't build on FreeBSD

--- plugins/plugins.pro.orig	2023-05-18 18:44:50 UTC
+++ plugins/plugins.pro
@@ -16,8 +16,8 @@ TEMPLATE = subdirs
  !macx:!win32:SUBDIRS += dmx4linux
  SUBDIRS              += velleman
  SUBDIRS              += enttecwing
- SUBDIRS              += hid
- !macx:!win32:SUBDIRS += spi
+# SUBDIRS              += hid
+# !macx:!win32:SUBDIRS += spi
  SUBDIRS              += os2l
  #!macx:!win32:SUBDIRS += uart
  #!macx:!win32:SUBDIRS += gpio
