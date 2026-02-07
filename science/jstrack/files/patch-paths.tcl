--- paths.tcl.orig	2014-01-14 11:09:14.000000000 +0100
+++ paths.tcl	2014-01-14 11:09:48.000000000 +0100
@@ -41,7 +41,7 @@
 # Typical location (multi-user use) for WinXX systems
 #    set install_dir c:/jstrack
 # install_dir value determined by autoconfig.tcl:
-set install_dir "/home/jim/src/jstrack"
+set install_dir "%%PREFIX%%/lib/jstrack"
 # Directory for storm data (must be an absolute path, e.g.,
 # /usr/local/lib/jstrack or $install_dir/tracker/storms).
 #
