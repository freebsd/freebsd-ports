--- frontpage/version5.0/fp_install.sh.orig	Mon Apr 16 07:39:25 2001
+++ frontpage/version5.0/fp_install.sh	Sat Jun  7 21:00:21 2003
@@ -12,7 +12,7 @@
 main() {
     initialize
     step1                               # setup environment
-    step2                               # untar
+#    step2                               # untar
     $FPDIR/set_default_perms.sh         # Run the external permissions script.
     step3                               # upgrade/install
     
@@ -52,12 +52,13 @@
     echo 
     
     migrateoldconfig        || error   # Migrate old frontpage.cnf (if any)
-    change_server           || error   # upgrade httpd
+#    change_server           || error   # upgrade httpd
     upgradeexistingservers  || error   # Check to see if servers need upgrading
     upgrade="yes"
     chownexistingservers    || error   # Now chown the webs
     handlelanguage          || error   # configure some global settings
     installrootweb          || error   # Install the root web
+    installadminweb         || error   # Install the FrontPage Server Administration Web
     installnewsubwebs $PORT || error   # Install new servers
     installvirtualwebs      || error   # Install any virtual webs
 }
@@ -132,9 +133,11 @@
 {
     VERSION="5.0"
     PATH=".:/bin:/usr/bin:/sbin:/usr/sbin:/usr/ucb:/etc:/usr/bsd"
+    AP_TARGET=`PREFIX/sbin/apxs -q TARGET`
+    AP_CONFDIR=`PREFIX/sbin/apxs -q SYSCONFDIR`
     INSTALLDIRDEFAULT="/usr/local/frontpage"
     NEWHTTPDNEW="/usr/local/frontpage/version${VERSION}/apache-fp/httpd"
-    DEFAULTHTTPD="/usr/local/apache/sbin/httpd"
+    DEFAULTHTTPD="PREFIX/sbin/httpd"
     FPDIR="/usr/local/frontpage/version${VERSION}"
 
     case "`echo 'x\c'`" in
@@ -390,29 +393,9 @@
 {
     retval=0
     
-    cat <<EOF
-
-Where would you like to install the FrontPage Server Extensions.  If
-you select a location other than /usr/local/frontpage/ then a symbolic
-link will be created from /usr/local/frontpage/ to the location that
-is chosen.
-
-EOF
-    $echo "FrontPage Server Extensions directory [/usr/local/frontpage/]:  ${nnl}"
-    read installdir
-    
-    if [ "$installdir" = "" ]
-    then
         installdir=$INSTALLDIRDEFAULT
-    fi
     installdir=`dirname $installdir`/`basename $installdir`
 
-    if [ ! -d "$installdir" ]
-    then
-        echo "Creating $installdir" 
-        if mkdir "$installdir"
-        then
-            echo "Directory $installdir has been created." 
             if chmod "$prot" "$installdir"
             then
                 echo "Directory $installdir chmoded to $prot." 
@@ -420,22 +403,6 @@
                 echo "ERROR:  Unable to chmod $installdir to $prot." 
                 retval=1
             fi
-        else
-            echo "ERROR:  Unable to create $installdir!" 
-            retval=1
-        fi
-    else
-        echo "WARNING:  Directory $installdir already exists." 
-        echo "Installation will overwrite existing files." 
-        echo 
-        
-        myprompt 'yYnN' "Continue the installation (y/n)" "N"
-        echo 
-        if [ $answer = n ] || [ $answer = N ]
-        then
-            exit 0
-        fi
-    fi
     
     if [ "$installdir" != "/usr/local/frontpage" ]
     then
@@ -805,16 +772,22 @@
                 accessconffile="${configfiledir}${file}"
                 ;;
         esac
+	if [ ! -f $accessconffile ]
+	then
+	    echo "ERROR:  $accessconffile does not exist! Using $configfile instead."
+	    accessconffile=$configfile
+	fi
     else
         accessconffile="${configfiledir}access.conf"
         if [ ! -f $accessconffile ]
         then
+	    echo "ERROR: No AccessConfig directive found, add 'AccessConfig /dev/null' to $configfile"
             accessconffile=$configfile
         fi
     fi
     if [ "$accessconffile" != "" -a "$accessconffile" != "/dev/null" -a ! -f "$accessconffile" ]
     then
-        echo "$accessconffile does not exist."
+        echo "ERROR: $accessconffile does not exist!"
         return 1
     fi
 
@@ -1290,20 +1263,30 @@
     echo " " 
     
     webname="/"
+    defconfigfile="${AP_CONFDIR}/${AP_TARGET}.conf"
     
     configfile=""
     while ( [ "$configfile" = "" ] || [ ! -f $configfile ] )
     do
-        $echo "Server config filename:  ${nnl}" 
+        $echo "Server config filename:  [$defconfigfile] ${nnl}" 
         read configfile
+        if [ "$configfile" = "" ]
+        then
+            configfile=$defconfigfile
+        fi
     done
     httpdconfigfile=$configfile
     
+    defadmin="fpadmin"
     admin=""
     until [ "$admin" != "" ]
     do
-        $echo "FrontPage Administrator's user name:  ${nnl}" 
+        $echo "FrontPage Administrator's user name:  [$defadmin] ${nnl}" 
         read admin
+	if [ "$admin" = "" ]
+	then
+	    admin=$defadmin
+	fi
     done
     
     getHttpRootDirective $configfile Port
@@ -1316,9 +1299,23 @@
     done
     weconfigfile="${installdir}/we${port}.cnf"
     
+    getHttpRootDirective $configfile DocumentRoot
+    docroot=$param
+    if [ ! -d "$docroot" ]
+    then
+        echo "ERROR: $docroot does not exist!"
+        return 1
+    fi
+
     echo 
     getparam User $configfile $port "Getting User from "
     defwebowner=$param
+
+    if [ "$defwebowner" = "" ]
+    then
+	defwebowner=`$lsg ${docroot}${service} | $awk ' { print $3}'`
+    fi
+
     webowner=""
     until [ "$webowner" != "" ]
     do
@@ -1333,6 +1330,12 @@
     echo 
     getparam Group $configfile $port "Getting Group from "
     defgroup=$param
+
+    if [ "$defgroup" = "" ]
+    then
+	defgroup=`$lsg ${docroot}${service} | $awk ' { print $4}'`
+    fi
+
     webgroup=""
     until [ "$webgroup" != "" ]
     do
@@ -1450,6 +1453,119 @@
     return $retval
 }
 
+# Install the FrontPage Server Administration Web
+installadminweb()
+{
+    retval=0
+    
+    configfile=""
+    admin=""
+    port=""
+
+    echo
+    echo "Note: If you have not installed FrontPage Server Administration then you should do it now."
+    echo
+    myprompt 'yYnN' "Do you want to install FrontPage Server Administration (y/n)" "Y"
+    if [ $answer = n ] || [ $answer = N ]
+    then
+	echo "You have chosen not to install FrontPage Server Administration.  If you wish"
+	echo "to install it later, you will need to use the following command:"
+	echo
+	echo "${FPDIR}/owsadm.exe -o setadminport -p 10865 \\"
+	echo "	-s ${AP_CONFDIR}/${AP_TARGET}.conf -u <FP Admin user>"
+	echo
+	echo "The FrontPage Server Administration setup will require the following change"
+	echo "in ${AP_CONFDIR}/${AP_TARGET}.conf for <VirtualHost _default_:10865>:"
+	echo
+	echo "	AllowOverride AuthConfig Limit Indexes Options"
+	echo
+	echo "otherwise, the FrontPage Server Administration web will not allow you to login."
+	echo
+	echo "This will then make FrontPage Server Administration available at:"
+	echo
+	echo "	http://`hostname`:10865/fpadmcgi.exe"
+	echo
+        return $retval
+    fi
+
+    echo " "
+    echo "Installing FrontPage Server Administration..."
+    echo " "
+
+    defconfigfile="${AP_CONFDIR}/${AP_TARGET}.conf"
+
+    while ( [ "$configfile" = "" ] || [ ! -f $configfile ] )
+    do
+        $echo "Server config filename:  [$defconfigfile] ${nnl}"
+        read configfile
+        if [ "$configfile" = "" ]
+        then
+            configfile=$defconfigfile
+        fi
+    done
+    httpdconfigfile=$configfile
+
+    defadmin="fpadmin"
+    until [ "$admin" != "" ]
+    do
+        $echo "FrontPage Server Administration user name:  [$defadmin] ${nnl}"
+        read admin
+        if [ "$admin" = "" ]
+        then
+            admin=$defadmin
+        fi
+    done
+
+#   Need to determine if the FrontPage Server Administration Web was previously
+#   installed and to which port it was installed on.
+
+#    getHttpRootDirective $configfile Port
+#    port=$param
+
+    defport="10865"
+    until [ "$port" != "" ]
+    do
+        $echo "Enter the FrontPage Server Administration port number:  [$defport] ${nnl}"
+        read port
+	if [ "$port" = "" ]
+	then
+	    port=$defport
+	fi
+    done
+
+#    getHttpRootDirective $configfile DocumentRoot
+#    docroot=$param
+#    if [ ! -d "$docroot" ]
+#    then
+#        echo "ERROR: $docroot does not exist!"
+#        return 1
+#    fi
+
+    echo "Installing FrontPage Server Administration on port $port..."
+    echo
+    ${FPDIR}/bin/owsadm.exe -o setadminport -p $port -s $configfile -u $admin || 
+    {
+        echo "ERROR:  FrontPage Server Administration installation failed."
+        $echo "Hit enter to continue${nnl}"
+        read continue
+        return 1
+    }
+    echo
+    echo "FrontPage Server Administration is now available at:"
+    echo
+    echo "	http://`hostname`:${port}/fpadmcgi.exe"
+    echo
+    echo "The FrontPage Server Administration setup requires the following change"
+    echo "in ${AP_CONFDIR}/${AP_TARGET}.conf for <VirtualHost _default_:${port}>:"
+    echo
+    echo "	AllowOverride AuthConfig Limit Indexes Options"
+    echo
+    echo "otherwise, the FrontPage Server Administration web will not allow you to login."
+    echo
+
+    return $retval
+}
+
 # Install a web on a multihosted server
 installvirtualwebs()
 {
@@ -1464,7 +1580,7 @@
         return $retval
     fi
     
-    defaultconfigfile=$configfile
+    defaultconfigfile="${AP_CONFDIR}/${AP_TARGET}.conf"
     configfile=""
     while ( [ "$configfile" = "" ] || [ ! -f $configfile ] )
     do
@@ -1922,10 +2038,16 @@
                 resconffile="${configfiledir}${file}"
                 ;;
         esac
+	if [ ! -f $resconffile ]
+	then
+	    echo "ERROR:  $resconffile does not exist! Using $configfile instead."
+	    resconffile=$configfile
+	fi
     else
         resconffile="${configfiledir}srm.conf"
         if [ ! -f $resconffile ]
         then
+	    echo "ERROR: No ResourceConfig directive found, add 'ResourceConfig /dev/null' to $configfile"
             resconffile=$configfile
         fi
     fi
@@ -1999,7 +2121,7 @@
     
     param=`cat $configfile | $awk "
             /^[^#]* *< *${virtualhost}/,/^[^#]* *< *\/${virtualhost}/ { next }
-            /^[^#]* *${mc_string}[ $TAB]/  { print \\\$2 }"` 
+            /^[^#]* *${mc_string}[ $TAB]/  { print \\\$2 }" | sed -e 's/"//g'` 
             
     return 0
 }
@@ -2050,7 +2172,7 @@
                                     print ARRAY[i] 
                                 }
                             }
-                    } "`
+                    } " | sed -e 's/"//g'`
     
     if [ "$param" = "" ]
     then
