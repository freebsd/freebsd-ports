--- tools/htpython.sh.orig	Thu Apr 15 09:17:47 2004
+++ tools/htpython.sh	Mon Aug 21 11:02:14 2006
@@ -27,12 +27,13 @@
 
 webroot=${1-$PWD}
 prefix=${2-/usr/local/nav/apache/webroot}
+pylibdir=$(realpath ${prefix}/../../lib/python)
 
 echo Working from $webroot
 cd $webroot
 candidates=`find . -name '.htaccess' -type f -printf "%P\00" | xargs -0 grep -li "SetHandler.*python-program"`
 for cand in $candidates; do
-  ppath="PythonPath \"sys.path+['${prefix}/`dirname ${cand}`']\""
+  ppath="PythonPath \"sys.path+['${prefix}/`dirname ${cand}`', '${pylibdir}']\""
   if grep -iq "^PythonPath" ${cand}; then
       perl -pi -e "s%^PythonPath.*$%${ppath}%i" ${cand} && echo Replaced ${ppath}
   else
