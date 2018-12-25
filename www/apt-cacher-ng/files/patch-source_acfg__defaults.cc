--- source/acfg_defaults.cc.orig	2018-09-07 13:02:18 UTC
+++ source/acfg_defaults.cc
@@ -40,6 +40,9 @@ string pfilepat(".*(\\.(u|d)?deb|\\.rpm|\\.drpm|\\.dsc
     "|\\.asc$" // all remaining PGP signatures. Assuming that volatile ones are matched below.
     "|changelogs/pool/.*/changelog.txt$" // packages.ultimediaos.com
     "|/objects/.*/.*\\.(dirtree|filez|commit|commitmeta)|/repo/deltas/.*" // FlatPak
+    "|(base|doc|games|kernel|lib32|ports|src)\\.txz$" // FreeBSD releases
+    "|(packagesite|meta)\\.txz?$" // FreeBSD packagesite
+    "|\\.txz(\\.sig)?$" // FreeBSD package/signature
 ")$");
 
 string svfilepat("/development/rawhide/.*"
@@ -66,7 +69,7 @@ string vfilepat(INFOLDER
 		"|\\.o" // https://bugs.launchpad.net/ubuntu/+source/apt-cacher-ng/+bug/1078224
 		"|Components-.*yml" COMPOPT // DEP-11 aka AppStream"
 		"|icons-[x0-9]+\\.tar" COMPOPT
-		"|(latest|pub)\\.ssl" // FreeBSD
+		"|(latest|pub|snapshot)\\.ssl|[0-9a-f]{64}.tgz|MANIFEST|/ports-distfiles/.*" // FreeBSD
 		")$" // end of filename-only patterns
 
 		"|/dists/.*/installer-[^/]+/[^0-9][^/]+/images/.*" // d-i stuff but not containing a date (year number) in the revision directory (like "current", "beta", ...)
