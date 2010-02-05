--- ./source4/script/installmisc.sh.orig	2010-01-11 05:35:28.000000000 +0000
+++ ./source4/script/installmisc.sh	2010-01-24 21:49:26.000000000 +0000
@@ -29,10 +29,10 @@
     if egrep 'sys.path.insert.*bin/python' $f > /dev/null; then
         if [ "$PYTHON_PATH_NEEDS_FIXING" = "yes" ]; then
             # old systems don't have sed -i :-(
-            sed "s|\(sys.path.insert.*\)bin/python\(.*\)$|\1$PYTHONDIR\2|g" < $f > $f.$$ || exit 1
+            sed "1,1 s|#!.*python.*|#!$PYTHON|; s|\(sys.path.insert.*\)bin/python\(.*\)$|\1$PYTHONDIR\2|g" < $f > $f.$$ || exit 1
         else
             # old systems don't have sed -i :-(
-            sed "s|\(sys.path.insert.*\)bin/python\(.*\)$||g" < $f > $f.$$ || exit 1
+            sed "1,1 s|#!.*python.*|#!$PYTHON|; s|\(sys.path.insert.*\)bin/python\(.*\)$||g" < $f > $f.$$ || exit 1
         fi
         mv -f $f.$$ $f || exit 1
         chmod +x $f
