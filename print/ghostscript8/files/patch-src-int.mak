--- src/int.mak.orig	2007-07-02 02:18:18.000000000 +0900
+++ src/int.mak	2008-01-11 08:28:14.000000000 +0900
@@ -988,7 +988,7 @@
 # unix-inst.mak uses this macro, problems should surface when testing installed
 # versions.
 #		Note: gs_cet.ps is only needed to match Adobe CPSI defaults
-EXTRA_INIT_FILES= Fontmap cidfmap xlatmap FAPI FCOfontmap-PCLPS2 gs_cet.ps
+EXTRA_INIT_FILES= Fontmap cidfmap xlatmap FAPI FCOfontmap-PCLPS2 gs_cet.ps FAPIcidfmap FAPIconfig FAPIfontmap
 
 #	The init files are put in the lib/ directory (gs_init.ps + EXTRA_INIT_FILES)
 #	Resource files go into Resource/...
