--- test.sh.orig	Sun Nov 16 20:30:24 2003
+++ test.sh	Sun Nov 16 20:30:40 2003
@@ -165,7 +165,7 @@
 
 rm -rf ${TO}
 mkdir -p ${FROM}2/dir/subdir
-cp -a ${FROM}/dir/subdir/subsubdir ${FROM}2/dir/subdir
+cp -pR ${FROM}/dir/subdir/subsubdir ${FROM}2/dir/subdir
 cp ${FROM}/dir/* ${FROM}2/dir 2>/dev/null
 runtest "excludes" 'checkit "$RSYNC -vv -Hlrt --delete --include /dir/ --include /dir/\* --include /dir/\*/subsubdir  --include /dir/\*/subsubdir/\*\* --exclude \*\* ${FROM}/dir ${TO}" ${FROM}2/ ${TO}'
 rm -r ${FROM}2
