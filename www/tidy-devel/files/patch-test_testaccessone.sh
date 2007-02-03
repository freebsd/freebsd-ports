--- test/testaccessone.sh.orig	Wed Mar 23 13:57:19 2005
+++ test/testaccessone.sh	Sat Feb  3 18:59:46 2007
@@ -71,7 +71,7 @@
 $TIDY -f $MSGFILE --accessibility-check $ACCESSLEVEL -config $CFGFILE "$@" --gnu-emacs yes --tidy-mark no -o $TIDYFILE $INFILE
 STATUS=$?
 
-if [ `grep -c -e ' \['$TESTEXPECTED'\]: ' $MSGFILE` -eq 0 ]
+if [ `grep -c -e ' \['$TESTEXPECTED'\]: ' $MSGFILE` = 0 ]
 then
   echo "--- test '$TESTEXPECTED' not detected in file '$INFILE'"
   cat $MSGFILE
