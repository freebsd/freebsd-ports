--- frontpage/version5.0/fp_install.sh.orig	Wed Jan 14 13:00:53 2004
+++ frontpage/version5.0/fp_install.sh	Sun Feb  6 18:34:34 2005
@@ -13,7 +13,7 @@
 main() {
     initialize
     step1                               # setup environment
-    step2                               # untar
+#    step2                               # untar
     $FPDIR/set_default_perms.sh         # Run the external permissions script.
     step3                               # upgrade/install
     
@@ -62,6 +62,7 @@
     chownexistingservers    || error   # Now chown the webs
     handlelanguage          || error   # configure some global settings
     installrootweb          || error   # Install the root web
+    installadminweb         || error   # Install the FrontPage Server Administration Web
     installnewsubwebs $PORT || error   # Install new servers
     installvirtualwebs      || error   # Install any virtual webs
 }
@@ -146,9 +147,10 @@
     NEWHTTPDNEW="/usr/local/frontpage/version${VERSION}/apache-fp/httpd"
     NEWMODFPSO1="/usr/local/frontpage/version${VERSION}/apache-fp/mod_frontpage.c"
     NEWMOFPSO2="/usr/local/frontpage/version${VERSION}/apache2/mod_frontpage.c"
-    DEFAULTHTTPD="/usr/local/apache/sbin/httpd"
     FPDIR="/usr/local/frontpage/version${VERSION}"
     APACHE_2_0_VERSION="2.0.40"
+    DEFAULTAPXS="/usr/local/apache/sbin/apxs"
+    DEFAULTVERSION="1.3"
     unset MORE
 
     case "`echo 'x\c'`" in
@@ -171,7 +173,9 @@
         SunOS*5.*sun4*)     machine="solaris" ;;
         SunOS*5.*i386*)     machine="solarisx86" ;;
         BSD/OS*)            machine="bsdi" ;;
-        FreeBSD*)           machine="freebsd" ;;
+        FreeBSD*)           machine="freebsd"
+                            DEFAULTAPXS="PREFIX/sbin/apxs"
+                            ;;
         *)              echo "ERROR:  Unsupported platform!  Uname is $system."
                         return 1
                          ;;
@@ -239,6 +243,32 @@
              *)
                 ;;
     esac
+
+    apxs_utility=""
+    while ( [ "$apxs_utility" = "" ] || [ ! -f "$apxs_utility" ] )
+    do
+        $echo "Where is the Apache apxs utility: [$DEFAULTAPXS] ${nnl}"
+        read apxs_utility
+        if [ "$apxs_utility" = "" ]
+        then
+            apxs_utility="${DEFAULTAPXS}"
+        fi
+    done
+    if [ ! -x "$apxs_utility" ]
+    then
+        echo "ERROR: Apache apxs utility not executable [$apxs_utility]"
+        return 1
+    else
+        AP_TARGET=`${apxs_utility} -q TARGET`
+        AP_CONFDIR=`${apxs_utility} -q SYSCONFDIR`
+        AP_LIBEXEC=`${apxs_utility} -q LIBEXECDIR`
+        AP_SBINDIR=`${apxs_utility} -q SBINDIR`
+    fi
+    DEFAULTCTL="${AP_SBINDIR}/apachectl"
+    DEFAULTHTTPD="${AP_SBINDIR}/${AP_TARGET}"
+    DEFAULTCFGFILE="${AP_CONFDIR}/${AP_TARGET}.conf"
+    NEWHTTPDNEW="${AP_SBINDIR}/${AP_TARGET}"
+    DEFAULTVERSION=`${NEWHTTPDNEW} -v | sed 's%^.*Apache/\([0-9]*\)\.\([0-9]*\).*%\1.\2%' | head -1`
 }
 
 # Compare two version numbers, including all sub-versions (such as 5.0.2.1234)
@@ -408,30 +438,10 @@
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
     # Normalize the name
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
@@ -439,22 +449,6 @@
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
@@ -478,7 +472,8 @@
 
 license() 
 {
-    untarlicense || error
+#    untarlicense || error
+    licensefile="DOCSDIR/LICENSE.TXT"
     echo "Please read the following license agreement (which can be found"
     echo "in $licensefile"
     echo
@@ -557,28 +552,36 @@
 #
 getapachevers()
 {
-    $echo "Which version of Apache will you be using? (1.3 or 2.0) ${nnl}"
-    read ApacheVers
+    ApacheVers=""
     while [ "$ApacheVers" != "1.3" -a "$ApacheVers" != "2.0" ]
     do
-      $echo "Please enter either '1.3' or '2.0'"
-      $echo "Which version of Apache will you be using? (1.3 or 2.0) ${nnl}"
+      $echo "Which version of Apache will you be using? (1.3 or 2.0) [${DEFAULTVERSION}] ${nnl}"
       read ApacheVers
+      if [ "$ApacheVers" = "" ]
+      then
+        ApacheVers=${DEFAULTVERSION}
+      fi
+      if [ "$ApacheVers" != "1.3" -a "$ApacheVers" != "2.0" ]
+      then
+        echo "Please enter either '1.3' or '2.0'"
+      fi
     done
 
     if [ "$ApacheVers" = "1.3" ]
     then
-        promptstring="Where is the current apache daemon located: [$HttpdFile] ${nnl}"
+        promptstring="Where is the current apache daemon located:"
+        DEFAULT=${DEFAULTHTTPD}
     else
-        promptstring="Where is the current apache control file (apachectl) located: [$HttpdFile] ${nnl}"
+        promptstring="Where is the current apache control file (apachectl) located:"
+        DEFAULT=${DEFAULTCTL}
     fi
        
     echo
     HttpdFile=""
     while ( [ "$HttpdFile" = "" ] || [ ! -x $HttpdFile ] )
     do
-        HttpdFile=$DEFAULTHTTPD
-        $echo $promptstring
+        HttpdFile=${DEFAULT}
+        $echo "$promptstring [$HttpdFile] ${nnl}"
         read location
         if [ "$location" != "" ]
         then
@@ -946,6 +949,56 @@
     return $retval
 }
 
+# 
+getconfigfile()
+{
+    weconfigfile="$1"
+
+    configfile=`grep -i "^serverconfig:" $weconfigfile | sed -e '
+                    s/serverconfig://g
+                    s/fakeconf.*\///'`
+
+    servertype=`grep -i "^servertype:" $weconfigfile | sed -e 's/servertype://g'`
+
+    if [ $httpdmajor -eq 2 ]
+    then
+        if [ "${servertype}" != "apache-2.0" ]
+        then
+            echo "Changing servertype from ${servertype} to apache-2.0"
+            echo "s,servertype:.*,servertype:apache-2.0,g" > $weconfigfile.sed
+            servertype="apache-2.0"
+        fi
+        if [ "${configfile}" != "${DEFAULTCFGFILE}" ]
+        then
+            echo "$configfile does not match location for httpd.conf in Apache 2.0"
+            myprompt 'yYnN' "Do you want to change to the Apache 2.0 httpd.conf file? (y/n)" "Y"
+            if [ $answer = y ] || [ $answer = Y ]
+            then
+                echo "s,serverconfig:.*,serverconfig:${DEFAULTCFGFILE},g" >> $weconfigfile.sed
+                configfile="${DEFAULTCFGFILE}"
+            fi
+            echo "Using $configfile"
+        fi
+        if [ -f "$weconfigfile.sed" ]
+        then
+            mv $weconfigfile $weconfigfile.bak
+            sed -f $weconfigfile.sed $weconfigfile.bak > $weconfigfile
+	    rm $weconfigfile.sed
+            if [ -s $weconfigfile ]
+            then
+                rm $weconfigfile.bak
+            fi
+        fi
+    fi
+
+    if [ ! -f "$configfile" ]
+    then
+        echo "$configfile does not exist."
+        return 1
+    fi
+
+}
+
 # examine weX.cnf file, make sure it is a patched apache server
 verifywebserver()
 {
@@ -964,27 +1017,22 @@
     port=$webport
     
     echo "Verifying web server configuration..."
-    
-    configfile=`grep -i "^serverconfig:" $weconfigfile | sed -e '
-                    s/serverconfig://g
-                    s/fakeconf.*\///'`
-    if [ ! -f "$configfile" ]
-    then
-        echo "$configfile does not exist."
-        return 1
-    fi
 
-    servertype=`grep -i "^servertype:" $weconfigfile | sed -e 's/servertype://g'`
+    getconfigfile $weconfigfile || return 1
+
     configfiledir=`dirname $configfile`"/"
 
     if [ $servertype != "apache-fp" ]
     then
-        echo "This version of FrontPage Server Extensions does not suppport"
-        echo "$servertype servers.  We only support patched apache servers."
-        echo "For more information about supported servers, please see" 
-        echo "the Server Extension Resource Kit (SERK), located at"
-        echo "http://www.microsoft.com/frontpage"
-        return 1
+        if [ $servertype != "apache-2.0" ]
+        then
+            echo "This version of FrontPage Server Extensions does not suppport"
+            echo "$servertype servers.  We only support patched apache servers."
+            echo "For more information about supported servers, please see" 
+            echo "the Server Extension Resource Kit (SERK), located at"
+            echo "http://www.microsoft.com/frontpage"
+            return 1
+        fi
     fi
 
     getdocroot $weconfigfile ||
@@ -993,28 +1041,41 @@
         return 1
     }
 
-    getHttpDirective $configfile AccessConfig $port
-    if [ "$param" != "" ]
+    # only Apache < 2.0 uses access.conf
+    if [ $httpdmajor -eq 1 ]
     then
-        case $param in
-            /dev/null) accessconffile=$configfile
-                ;;
-            /*) accessconffile=$param  # fully qualified pathname
-                ;;
-            *)  file=`basename $param`
-                accessconffile="${configfiledir}${file}"
-                ;;
-        esac
-    else
-        accessconffile="${configfiledir}access.conf"
-        if [ ! -f $accessconffile ]
+        getHttpDirective $configfile AccessConfig $port
+        if [ "$param" != "" ]
         then
-            accessconffile=$configfile
+            case $param in
+                /dev/null) accessconffile=$configfile
+                    ;;
+                /*) accessconffile=$param  # fully qualified pathname
+                    ;;
+                *)  file=`basename $param`
+                    accessconffile="${configfiledir}${file}"
+                    ;;
+            esac
+	    if [ ! -f $accessconffile ]
+	    then
+	        echo "ERROR:  $accessconffile does not exist! Using $configfile instead."
+	        accessconffile=$configfile
+	    fi
+        else
+            accessconffile="${configfiledir}access.conf"
+            if [ ! -f $accessconffile ]
+            then
+	        echo "ERROR: No AccessConfig directive found, add 'AccessConfig /dev/null' to $configfile"
+                accessconffile=$configfile
+            fi
         fi
+    else
+       accessconffile=$configfile
     fi
+
     if [ "$accessconffile" != "" -a "$accessconffile" != "/dev/null" -a ! -f "$accessconffile" ]
     then
-        echo "$accessconffile does not exist."
+        echo "ERROR: $accessconffile does not exist!"
         return 1
     fi
 
@@ -1088,7 +1149,7 @@
             echo "Skipping chown..."
         else
             servertype=`grep -i "^servertype:" $weconfigfile|sed -e 's/servertype://g'`
-            if [ "$servertype" != "apache-fp" ]
+            if [ "$servertype" != "apache-fp" -a "$servertype" != "apache-2.0" ]
             then
                 echo "Skipping non patched-apache web $weconfigfile"
             else
@@ -1120,10 +1181,9 @@
     echo 
     echo "Processing webs in port $webport..."
     echo 
-    
-    configfile=`grep -i "^serverconfig:" $weconfigfile | sed -e '
-                    s/serverconfig://g
-                    s/fakeconf.*\///'`
+
+    getconfigfile $weconfigfile || return 1
+
     configfiledir=`dirname $configfile`"/"
     
     getdocroot $weconfigfile ||
@@ -1364,10 +1424,9 @@
     port=$webport
     
     echo "Adding webs in port ${webport} to chown script..."
-    servertype=`grep -i "^servertype:" $weconfigfile|sed -e 's/servertype://g'`
-    configfile=`grep -i "^serverconfig:" $weconfigfile | sed -e '
-                s/serverconfig://g
-                s/fakeconf.*\///'`
+
+    getconfigfile $weconfigfile || return 1
+
     configfiledir=`dirname $configfile`"/"
     getdocroot $weconfigfile ||
     {
@@ -1474,11 +1533,16 @@
 	configfile=$rootconfigfile
 	return
     fi
+
     configfile=""
     while ( [ "$configfile" = "" ] || [ ! -f $configfile ] )
     do
-        $echo "Server config filename:  ${nnl}" 
+        $echo "Server config filename:  [${DEFAULTCFGFILE}] ${nnl}" 
         read configfile
+	if [ "$configfile" = "" ]
+        then
+            configfile="${DEFAULTCFGFILE}"
+        fi
     done
     rootconfigfile=$configfile
 }
@@ -1517,28 +1581,51 @@
     
     getrootconfigfile
     httpdconfigfile=$configfile
-    
+
+    defadmin="fpadmin"
     admin=""
     until [ "$admin" != "" ]
     do
-        $echo "FrontPage Administrator's user name:  ${nnl}" 
+        $echo "FrontPage Administrator's user name:  [$defadmin] ${nnl}" 
         read admin
+        if [ "$admin" = "" ]
+        then
+            admin=$defadmin
+        fi
     done
-    httpdconfigfile=$configfile
-    
+
+    defport="80"
     getHttpRootDirective $configfile Port
     port=$param
     
     until [ "$port" != "" ]
     do
-        $echo "Enter the new server's port number:  ${nnl}" 
+        $echo "Enter the new server's port number:  [$defport] ${nnl}" 
         read port
+        if [ "$port" = "" ]
+        then
+            port=$defport
+        fi
     done
     weconfigfile="${installdir}/we${port}.cnf"
-    
+ 
+    getHttpRootDirective $configfile DocumentRoot
+    docroot=$param
+    if [ ! -d "$docroot" ]
+    then
+         echo "ERROR: $docroot does not exist!"
+         return 1
+    fi
+   
     echo 
     getparam User $configfile $port "Getting User from "
     defwebowner=$param
+
+    if [ "$defwebowner" = "" ]
+    then
+        defwebowner=`$lsg ${docroot}${service} | $awk ' { print $3}'`
+    fi
+
     webowner=""
     until [ "$webowner" != "" ]
     do
@@ -1553,6 +1640,12 @@
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
@@ -1670,6 +1763,113 @@
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
+       echo "You have chosen not to install FrontPage Server Administration.  If you wish"
+       echo "to install it later, you will need to use the following command:"
+       echo
+       echo "${FPDIR}/owsadm.exe -o setadminport -p 10865 \\"
+       echo "  -s ${DEFAULTCFGFILE} -u <FP Admin user> -pw <FP Admin password>"
+       echo
+       echo "The FrontPage Server Administration setup will require the following change"
+       echo "in ${DEFAULTCFGFILE} for <VirtualHost _default_:10865>:"
+       echo
+       echo "  AllowOverride AuthConfig Limit Indexes Options"
+       echo
+       echo "otherwise, the FrontPage Server Administration web will not allow you to login."
+       echo
+       echo "This will then make FrontPage Server Administration available at:"
+       echo
+       echo "  http://`hostname`:10865/fpadmcgi.exe"
+       echo
+       return $retval
+    fi
+
+    echo " "
+    echo "Installing FrontPage Server Administration..."
+    echo " "
+
+    getrootconfigfile
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
+    getpassword "FrontPage Server Administration Password:"
+    password=${PASSWORD}
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
+       if [ "$port" = "" ]
+       then
+           port=$defport
+       fi
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
+    ${FPDIR}/bin/owsadm.exe -o deleteadminport -t $fpversionoption -s $configfile
+    ${FPDIR}/bin/owsadm.exe -o setadminport -p $port -s $configfile -u $admin -pw $password -t $fpversionoption ||
+    {
+        echo "ERROR:  FrontPage Server Administration installation failed."
+        $echo "Hit enter to continue${nnl}"
+        read continue
+        return 1
+    }
+    echo
+    echo "FrontPage Server Administration is now available at:"
+    echo
+    echo "     http://`hostname`:${port}/fpadmcgi.exe"
+    echo
+    echo "The FrontPage Server Administration setup requires the following change"
+    echo "in ${configfile} for <VirtualHost _default_:${port}>:"
+    echo
+    echo "     AllowOverride AuthConfig Limit Indexes Options"
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
@@ -1684,17 +1884,7 @@
         return $retval
     fi
     
-    defaultconfigfile=$configfile
-    configfile=""
-    while ( [ "$configfile" = "" ] || [ ! -f $configfile ] )
-    do
-        $echo "Server config filename [${defaultconfigfile}]:  ${nnl}" 
-        read configfile
-        if [ "$configfile" = "" ]
-        then
-            configfile=$defaultconfigfile
-        fi
-    done
+    getrootconfigfile
     httpdconfigfile=$configfile
     
     getHttpRootDirective $configfile Port
@@ -1792,12 +1982,17 @@
         done
         
         webname="/"
-        
+
+        defadmin="fpadmin"
         admin=""
         until [ "$admin" != "" ]
         do
-            $echo "FrontPage Administrator's user name:  ${nnl}" 
+            $echo "FrontPage Administrator's user name:  [$defadmin] ${nnl}"
             read admin
+            if [ "$admin" = "" ]
+            then
+                admin=$defadmin
+            fi
         done
         
         servertype="apache-fp"
@@ -1880,9 +2075,9 @@
     echo
     
     servertype="apache-fp"
-    configfile=`grep -i "^serverconfig:" $weconfigfile | sed -e '
-                s/serverconfig://g
-                s/fakeconf.*\///'`
+
+    getconfigfile $weconfigfile || return 1
+
     configfiledir=`dirname $configfile`"/"
     
     getdocroot $weconfigfile ||
@@ -1908,11 +2103,16 @@
     while $echo "Enter the web name (CTRL-D if no more webs): ${nnl}" 
         read webname    
     do
+        defadmin="fpadmin"
         admin=""
         until [ "$admin" != "" ]
         do
-            $echo "FrontPage Administrator's user name:  ${nnl}" 
+            $echo "FrontPage Administrator's user name:  [$defadmin] ${nnl}" 
             read admin
+            if [ "$admin" = "" ]
+            then
+                admin=$defadmin
+            fi
         done
         
         case "$webname" in
@@ -2113,42 +2313,43 @@
     weconfigfile=$1
     
     servertype="apache-fp"
-    configfile=`grep -i "^serverconfig:" $weconfigfile | sed -e '
-                s/serverconfig://g
-                s/fakeconf.*\///'`
-    
+
     echo "Getting DocumentRoot and UserDir."
     
-    if [ ! -f "$configfile" ]
-    then
-        echo "$configfile does not exist."
-        return 1
-    fi
-    
+    getconfigfile $weconfigfile || return 1
+ 
     configfiledir=`dirname $configfile`"/"
     
     docroot=""
-    resconffile=$configfile
-    echo "Getting resource configuration file"
-    getHttpDirective $configfile ResourceConfig $port
-    if [ "$param" != "" ]
-    then
-        case $param in
-            /dev/null) resconffile=$configfile
-                ;;
-            /*) resconffile=$param  # fully qualified pathname
-                ;;
-            *)  file=`basename $param`
-                resconffile="${configfiledir}${file}"
-                ;;
-        esac
-    elif [ $httpdmajor -eq 1 ]
+
+    # only Apache < 2.0 uses srm.conf
+    if [ $httpdmajor -eq 1 ]
     then
-    # only Apache 1 requires srm.conf
-        resconffile="${configfiledir}srm.conf"
-        if [ ! -f $resconffile ]
+        echo "Getting resource configuration file"
+        getHttpDirective $configfile ResourceConfig $port
+        if [ "$param" != "" ]
         then
-            resconffile=$configfile
+            case $param in
+                /dev/null) resconffile=$configfile
+                    ;;
+                /*) resconffile=$param  # fully qualified pathname
+                    ;;
+                *)  file=`basename $param`
+                    resconffile="${configfiledir}${file}"
+                    ;;
+            esac
+	    if [ ! -f $resconffile ]
+            then
+                echo "ERROR:  $resconffile does not exist! Using $configfile instead."
+                resconffile=$configfile
+            fi
+        else
+            resconffile="${configfiledir}srm.conf"
+            if [ ! -f $resconffile ]
+            then
+	        echo "ERROR: No ResourceConfig directive found, add 'ResourceConfig /dev/null' to $configfile"
+                resconffile=$configfile
+            fi
         fi
     else
        resconffile=$configfile
@@ -2274,7 +2475,7 @@
                                     print ARRAY[i] 
                                 }
                             }
-                    } "`
+                    } " | sed -e 's/"//g'`
     
     if [ "$param" = "" ]
     then
@@ -2340,22 +2541,22 @@
         # Apache 2.0
 	httpdmajor=2
         fpversionoption="apache-2.0"
-	installfpdso2 || 
-	{
-	    echo "ERROR: Unable to install mod_frontpage dso"
-	    return 1
-	}
+#	installfpdso2 ||
+#	{
+#	    echo "ERROR: Unable to install mod_frontpage dso"
+#	    return 1
+#	}
 	return 0
     elif [ $rtc -eq 4 ]
     then
 	# Apache 1.3 with mod_so
 	httpdmajor=1
 	fpversionoption="apache-fp"
-	installfpdso1 || 
-	{
-	    echo "ERROR: Unable to install mod_frontpage dso"
-	    return 1
-	}
+#	installfpdso1 || 
+#	{
+#	    echo "ERROR: Unable to install mod_frontpage dso"
+#	    return 1
+#	}
 	return 0
     elif [ $rtc -ne 0 ]
     then
@@ -2578,23 +2779,7 @@
 
 getModFpVersion1() 
 {
-    httpdir=`dirname $HttpdFile`
-    # Remove the /bin
-    httpdir=`dirname $httpdir`/libexec
-    if [ ! -d "$httpdir" ]
-    then
-	httpdir="/usr/local/apache/modules"
-    fi
-    while ( [ ! -d "$httpdir" ] )
-    do 
-	$echo "Where is the current Apache modules directory: [$httpdir] ${nnl}"
-	read location
-	if [ "$location" != "" ]
-	then
-	    httpdir=$location
-	fi
-    done
-    modfpso="${httpdir}/mod_frontpage.so"
+    modfpso="${AP_LIBEXEC}/mod_frontpage.so"
 }
 
 checkModFpSo1()
@@ -2822,11 +3007,11 @@
     echo "This version of FrontPage requires either:"
     echo "  Apache Version $sourceVersion"
     echo "or"
-    echo "  Apache Version APACHE_2_0_VERSION (with mod_so)"
+    echo "  Apache Version ${APACHE_2_0_VERSION} (with mod_so)"
     echo 
     echo "We recommend you install one of these versions, with mod_so."
     echo "Alternatively, we can install a prebuilt Apache $sourceVersion ."
-    echo "This prebuilt version does not use mod_so for FronPage, but instead"
+    echo "This prebuilt version does not use mod_so for FrontPage, but instead"
     echo "has been patched to work with FrontPage."
     myprompt 'yYnN' "Do you want to install this prebuilt version (y/n)" "N"
     if [ $answer = n ] || [ $answer = N ]
@@ -2908,22 +3093,6 @@
 
 installfpdso1()
 {
-    httpdir=`dirname $HttpdFile`
-    while ( [ ! -d "$httpdir" ] )
-    do 
-	httpdir="/usr/local/apache/bin"
-	$echo "Where is the current Apache 1.3 bin directory: [$httpdir] ${nnl}"
-	read location
-	if [ "$location" != "" ]
-	then
-	    httpdir=$location
-	fi
-    done
-    if [ ! -x "$httpdir/apxs" ]
-    then
-	echo "Cannot find Apache apxs at $httpdir/apxs"
-	return 1
-    fi
     echo "Using the Apache apxs utility to build mod_frontpage.so"
     CURPATH=$PATH
     PATH=$OLDPATH
@@ -2933,7 +3102,7 @@
        linux)   opts=-Wc,-Dlinux ;;
        *)       opts= ;;
     esac
-    $httpdir/apxs -c $opts $FPDIR/apache-fp/mod_frontpage.c
+    $apxs_utility -c $opts $FPDIR/apache-fp/mod_frontpage.c
     res=$?
     PATH=$CURPATH
     if [ $res -ne 0 ]
@@ -2943,7 +3112,7 @@
     
     echo "Using the Apache apxs utility to install mod_frontpage.so"
     PATH=$OLDPATH
-    $httpdir/apxs -i -a -n frontpage $FPDIR/apache-fp/mod_frontpage.so
+    $apxs_utility -i -a -n frontpage $FPDIR/apache-fp/mod_frontpage.so
     res=$?
     PATH=$CURPATH
     echo "Finished running the Apache apxs utility."
@@ -2953,22 +3122,6 @@
 
 installfpdso2()
 {
-    httpdir=`dirname $HttpdFile`
-    while ( [ ! -d "$httpdir" ] )
-    do 
-	httpdir="/usr/local/apache/bin"
-	$echo "Where is the current Apache 2.0 bin directory: [$httpdir] ${nnl}"
-	read location
-	if [ "$location" != "" ]
-	then
-	    httpdir=$location
-	fi
-    done
-    if [ ! -x "$httpdir/apxs" ]
-    then
-	echo "Cannot find Apache apxs at $httpdir/apxs"
-	return 1
-    fi
     echo "Using the Apache apxs utility to build mod_frontpage.so"
     CURPATH=$PATH
     PATH=$OLDPATH
@@ -2978,7 +3131,7 @@
        linux)   opts=-Wc,-Dlinux ;;
        *)       opts= ;;
     esac
-    $httpdir/apxs -c $opts $FPDIR/apache2/mod_frontpage.c $FPDIR/apache2/mod_fpcgid.c
+    $apxs_utility -c $opts $FPDIR/apache2/mod_frontpage.c $FPDIR/apache2/mod_fpcgid.c
     res=$?
     PATH=$CURPATH
     if [ $res -ne 0 ]
@@ -2987,7 +3140,7 @@
     fi
     echo "Using the Apache apxs utility to install mod_frontpage.so"
     PATH=$OLDPATH
-    $httpdir/apxs -i -a -n frontpage $FPDIR/apache2/mod_frontpage.la
+    $apxs_utility -i -a -n frontpage $FPDIR/apache2/mod_frontpage.la
     res=$?
     PATH=$CURPATH
     echo "Finished running the Apache apxs utility."
