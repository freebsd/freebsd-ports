Index: etc/pkgtools.sh
===================================================================
--- etc/pkgtools.sh	(revision 1046)
+++ etc/pkgtools.sh	(working copy)
@@ -17,7 +17,7 @@
 
 pkgtools_start() {
     if [ -d "$pkgtools_libdir" ]; then
-	echo /sbin/ldconfig -m "$pkgtools_libdir"
+	/sbin/ldconfig -m "$pkgtools_libdir"
     fi
 }
 
