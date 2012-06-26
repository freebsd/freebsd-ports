Index: lib/tinderlib.sh
===================================================================
RCS file: /space/cvs/marcuscom-cvs/portstools/tinderbox/lib/tinderlib.sh,v
retrieving revision 1.69
diff -u -r1.69 tinderlib.sh
--- lib/tinderlib.sh	20 Jun 2012 20:47:42 -0000	1.69
+++ lib/tinderlib.sh	26 Jun 2012 19:42:23 -0000
@@ -664,7 +664,7 @@
 
     for r in ${reqs} ; do
         if [ "${use_pkgng}" = "yes" ]; then 
-            if [ -z $(pkg info -q ${r}) ]; then
+            if [ -z $(pkg info -qgO ${r}) ]; then
                 missing="${missing} ${r}"
                 error=1
             fi
