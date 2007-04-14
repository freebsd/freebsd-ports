--- install.sh.orig	Mon Apr  9 10:57:12 2007
+++ install.sh	Fri Apr 13 20:17:57 2007
@@ -805,10 +805,9 @@
     case "${machine}:${os}" in
 	x86:Linux|x86_64:Linux|x86:AnyBSD|x86_64:AnyBSD|x86:OpenBSD)
 	    wrapper_ibmjava="
-	    IBMJava2-142/jre \\
-	    IBMJava2-141/jre \\
-	    IBMJava2-14/jre \\
-	    IBMJava2-131/jre \\"
+	    linux-ibm-jdk1.3.1/jre \\
+	    linux-ibm-jdk1.4.0/jre \\
+	    linux-ibm-jdk1.4.1/jre \\"
 	    wrapper_sunjava_machine="i386"
 	;;
 
@@ -838,10 +837,19 @@
 		error 'os'
 	;;
     esac
-    wrapper_file="${wrapper_dir}/opera"
+    wrapper_file="${wrapper_dir}/linux-opera"
 
     wrapper_contain="#!/bin/sh
 
+# Required to check on shm_allow_removed if it is disable then set the
+# OPERA_NUM_XSHM to 0 or it will causing Opera to halt or/and give strange
+# behavior.
+if [ \`/sbin/sysctl -n kern.ipc.shm_allow_removed\` -eq 0 ]; then
+	OPERA_NUM_XSHM=\"0\"
+	export OPERA_NUM_XSHM
+	echo \"shm_allow_removed is disable, set OPERA_NUM_XSHM to 0 to disable shared memory.\"
+fi
+
 # Required for Session Management
 case \$0 in /*) OPERA_SCRIPT_PATH=\$0;; *) OPERA_SCRIPT_PATH=`/bin/pwd`/\$0;; esac
 export OPERA_SCRIPT_PATH
@@ -901,6 +909,10 @@
 OPERA_LD_PRELOAD=\"\${LD_PRELOAD}\"
 export OPERA_LD_PRELOAD
 
+# ~/.linux-opera
+OPERA_PERSONALDIR=\${HOME}/.linux-opera
+export OPERA_PERSONALDIR
+
 # Native Java enviroment
 if test -f \"\${OPERA_PERSONALDIR}/javapath.txt\"; then
     INIJAVA=\`cat \${OPERA_PERSONALDIR}/javapath.txt\`
@@ -908,8 +920,8 @@
 fi
 
 if test ! \"\${OPERA_JAVA_DIR}\"; then
-    if test -f \"\${HOME}/.opera/javapath.txt\"; then
-        INIJAVA=\`cat \${HOME}/.opera/javapath.txt\`
+    if test -f \"\${OPERA_PERSONALDIR}/javapath.txt\"; then
+        INIJAVA=\`cat \${OPERA_PERSONALDIR}/javapath.txt\`
         if test -f \"\${INIJAVA}/libjava.so\"; then OPERA_JAVA_DIR=\"\${INIJAVA}\"; fi
     fi
 fi
@@ -924,69 +936,16 @@
 
 if test ! \"\${OPERA_JAVA_DIR}\"; then
 
-    PREFIXES=\"
-	/usr
-	/usr/java
-	/usr/lib
-	/usr/local
-	/opt\"
+    PREFIXES=\"%%LOCALBASE%%\"
 
     for SUNJAVA in \\
-	java-1.5.0-sun-1.5.0.06 \\
-	java-1.5.0-sun-1.5.0.06/jre \\
-	java-1.5.0-sun-1.5.0.05 \\
-	java-1.5.0-sun-1.5.0.05/jre \\
-	java-1.5.0-sun-1.5.0.04 \\
-	java-1.5.0-sun-1.5.0.04/jre \\
-	jre1.5.0_06 \\
-	jdk1.5.0_06/jre \\
-	jre1.5.0_05 \\
-	jdk1.5.0_05/jre \\
-	jre1.5.0_04 \\
-	jdk1.5.0_04/jre \\
-	jre1.5.0_03 \\
-	jdk1.5.0_03/jre \\
-	jre1.5.0_02 \\
-	jdk1.5.0_02/jre \\
-	jre1.5.0_01 \\
-	jdk1.5.0_01/jre \\
-	j2re1.4.2_06 \\
-	j2sdk1.4.2_06/jre \\
-	j2re1.4.2_04 \\
-	j2sdk1.4.2_04/jre \\
-	j2re1.4.2_03 \\
-	j2sdk1.4.2_03/jre \\
-	j2re1.4.2_02 \\
-	j2sdk1.4.2_02/jre \\
-	j2re1.4.2_01 \\
-	j2sdk1.4.2_01/jre \\
-	j2re1.4.2 \\
-	j2sdk1.4.2/jre \\
-	j2re1.4.1_01 \\
-	j2re1.4.1 \\
-	SUNJava2-1.4.1 \\
-	BlackdownJava2-1.4.1/jre \\
-	j2re1.4.0_01 \\
-	j2sdk1.4.0_01/jre \\
-	j2re1.4.0 \\
-	jre1.4.0 \\
-	j2se/1.4/jre \\
-	j2se/1.3/jre \\
-	j2se/jre \\
-	jre1.3.1_15 \\
-	jre1.3.1_04 \\
-	jre1.3.1_02 \\
-	jre1.3.1_01 \\
-	j2re1.3.1 \\
-	jre1.3.1 \\
-	j2re1.3 \\
-	j2se/1.3/jre \\
-	SunJava2-1.3/jre \\
-	java2re \\
-	jdk1.2.2/jre \\
-	jdk1.2/jre \\
-	jre \\
-	java \\
+	linux-blackdown-jdk1.3.1/jre \\
+	linux-blackdown-jdk1.4.1/jre \\
+	linux-blackdown-jdk1.4.2/jre \\
+	linux-sun-jdk1.3.1/jre \\
+	linux-sun-jdk1.4.1/jre \\
+	linux-sun-jdk1.4.2/jre \\
+	linux-sun-jdk1.5.0/jre \\
 	; do
 	for PREFIX in \${PREFIXES}; do
 	    if test -f \"\${PREFIX}/\${SUNJAVA}/lib/${wrapper_sunjava_machine}/libjava.so\"; then OPERA_JAVA_DIR=\"\${PREFIX}/\${SUNJAVA}/lib/${wrapper_sunjava_machine}\" && break; fi
@@ -1037,11 +996,8 @@
 
 # Acrobat Reader
 for BINDIR in \\
-    /usr/local/Acrobat[45]/bin \\
-    /usr/lib/Acrobat[45]/bin \\
-    /usr/X11R6/lib/Acrobat[45]/bin \\
-    /opt/Acrobat[45]/bin \\
-    /usr/Acrobat[45]/bin \\
+    %%LOCALBASE%%/Acrobat5/bin \\
+    %%X11BASE%%/Acrobat5/bin \\
     ; do
     if test -d \${BINDIR} ; then PATH=\${PATH}:\${BINDIR}; fi
 done
@@ -1063,13 +1019,6 @@
 done"
 
 case "${os}" in
-	AnyBSD|OpenBSD)
-wrapper_contain="${wrapper_contain}
-
-# Make sure the compat libraries are found
-test -d /usr/local/lib/compat/ && LD_LIBRARY_PATH=\"\${LD_LIBRARY_PATH}:/usr/local/lib/compat/\"
-"
-	;;
     SunOS)
 wrapper_contain="${wrapper_contain}
 
@@ -1098,7 +1047,7 @@
 };
 
 // Opera package classes get all permissions
-grant codebase \"file://${str_localdirshare}/java//opera.jar\" {
+grant codebase \"file://${str_localdirshare}/java/opera.jar\" {
 	permission java.security.AllPermission;
 };
 
@@ -1167,7 +1116,7 @@
     chop "${OPERADESTDIR}" "str_localdirshare"
     chop "${OPERADESTDIR}" "str_localdirplugin"
 
-    backup ${wrapper_dir}/opera opera
+    #backup ${wrapper_dir}/opera opera
 
     # Executable
     debug_msg 1 "Executable"
@@ -1201,7 +1150,7 @@
 
     #cp $cpv $cpf wrapper.sh $wrapper_dir/opera
     generate_wrapper
-    chmod $chmodv 755 $wrapper_dir/opera
+    chmod $chmodv 755 $wrapper_dir/linux-opera
 
     # Manual page
     debug_msg 1 "Manual page"
@@ -1210,7 +1159,7 @@
     chmod $chmodv 755 ${man_dir}
     mkdir $mkdirv $mkdirp ${man_dir}/man1
     chmod $chmodv 755 ${man_dir}/man1
-    cp $cpv $cpf man/opera.1 ${man_dir}/man1
+    cp $cpv $cpf man/opera.1 ${man_dir}/man1/linux-opera.1
 
     # Documentation
     debug_msg 1 "Documentation"
@@ -1242,13 +1191,6 @@
 	mkdir $mkdirv $mkdirp $share_dir/ini/
 	chmod $chmodv 755 $share_dir/ini
 	cp $cpv $cpf $cpR ini/* $share_dir/ini/
-	if test -f $share_dir/ini/pluginpath.ini
-	then (
-	    echo
-	    echo '; locally installed:'
-	    echo "${str_localdirplugin}=1"
-	    ) >> $share_dir/ini/pluginpath.ini
-	fi
     fi
 
     mkdir $mkdirv $mkdirp $share_dir/locale/
@@ -1340,43 +1282,11 @@
 
     if test -z "${OPERADESTDIR}"
     then
-	# System wide configuration files
-	config_dir="/etc"
-	if can_write_to "$config_dir"
-	then
-	    echo
-	    echo "System wide configuration files:"
-	    echo "  $config_dir/opera6rc"
-	    echo "  $config_dir/opera6rc.fixed"
-	    echo " would be ignored if installed with the prefix \"$prefix\"."
-	    if con_firm "Do you want to install them in $config_dir"
-	    then
-		backup $config_dir/opera6rc opera6rc config
-		backup $config_dir/opera6rc.fixed opera6rc.fixed config
-		cp $cpv $cpf config/opera6rc $config_dir
-		cp $cpv $cpf config/opera6rc.fixed $config_dir
-	    fi
-	else
-	    echo
-	    echo "User \"${USERNAME}\" does not have write access to $config_dir"
-	    echo " System wide configuration files:"
-	    echo "  $config_dir/opera6rc"
-	    echo "  $config_dir/opera6rc.fixed"
-	    echo " were not installed."
-	fi
-
 	# Shorcuts and Icons
 	bool_icons=1 # install icons by default
 
-	if test "${flag_mode}" = "--force" -o "${flag_mode}" = "--prefix="
-	then
-	    echo
-	    echo "Shortcut icons will be ignored if installed with the prefix \"$prefix\"."
-	    con_firm "Do you want to (try to) install them in default locations" || bool_icons=0
-	fi
-
 	if test "${bool_icons}" -ne 0
-	then xdg
+	then icons
 	fi
 
     fi # OPERADESTDIR
@@ -1428,19 +1338,19 @@
     # arg1 = location
     # arg2 = type
 
-    desktop_file="${1}/opera.desktop"
+    desktop_file="${1}/linux-opera.desktop"
     desktop_contain='[Desktop Entry]'
 
     if test ${2}; then
 	if test "${2}" = "xdg"; then
 	    desktop_contain="${desktop_contain}
 Version=1.0
-TryExec=opera"
+TryExec=linux-opera"
 	fi
 
 	desktop_contain="${desktop_contain}
 Encoding=UTF-8
-Name=Opera
+Name=Opera (linux version)
 Name[af]=opera
 Name[eo]=Opero
 Name[zu]=I Opera
@@ -1464,7 +1374,7 @@
 GenericName[ven]=Buronza ya Webu
 GenericName[xh]=Umkhangeli Zincwadi Zokubhaliweyo
 GenericName[zu]=Umkhangeli zincwadi we Web
-Exec=opera %u
+Exec=linux-opera %u
 Terminal=false"
 
 # Application is not a category, according to
@@ -1479,25 +1389,26 @@
 	if test "${2}" = "xdg"; then
 	    desktop_contain="${desktop_contain}
 Categories=Application;Qt;Network;WebBrowser;X-Ximian-Main;X-Ximian-Toplevel
-Icon=opera.png"
+Icon=linux-opera.png"
 	else
 	    desktop_contain="${desktop_contain}
-Icon=opera"
+Icon=linux-opera"
 	fi
 
 	desktop_contain="${desktop_contain}
 MimeType=text/html;text/xml;application/xhtml+xml"
     else
 	desktop_contain="${desktop_contain}
-Name=Opera
-Exec=opera
-Icon=opera.xpm
+Name=Opera (linux version)
+Exec=linux-opera
+Icon=linux-opera.png
 Terminal=0"
     fi
 
     desktop_contain="${desktop_contain}
 Comment=Web Browser
-Type=Application"
+Type=Application
+Categories=Application;Network;WebBrowser;"
 
     echo "${desktop_contain}" > ${desktop_file}
     chmod $chmodv 644 ${desktop_file}
@@ -1528,55 +1439,28 @@
 
     debug_msg 0 "in icons()"
 
-    if test ! -d /usr/share/icons
-    then
-	if test -w /usr/share
-	then
-	    mkdir $mkdirv $mkdirp /usr/share/icons/
-	    chmod $chmodv 755 /usr/share/icons
-	    cp $cpv $share_dir/images/opera.xpm /usr/share/icons/opera.xpm
-	fi
-    elif test -w /usr/share/icons
-    then cp $cpv $share_dir/images/opera.xpm /usr/share/icons/opera.xpm
-    fi
-
-    if test ! -d /usr/share/pixmaps
-    then
-	if test -w /usr/share
-	then
-	    mkdir $mkdirv $mkdirp /usr/share/pixmaps/
-	    chmod $chmodv 755 /usr/share/pixmaps
-	    cp $cpv $share_dir/images/opera.xpm /usr/share/pixmaps/opera.xpm
-	fi
-    elif test -w /usr/share/pixmaps/
-    then cp $cpv $share_dir/images/opera.xpm /usr/share/pixmaps/opera.xpm
-    fi
-
-    if test ! -d /etc/X11/wmconfig/
+    if test ! -d %%LOCALBASE%%/share/pixmaps/
     then
-	if test -w /etc/X11
+	if test -w %%LOCALBASE%%/share
 	then
-	    mkdir $mkdirv $mkdirp /etc/X11/wmconfig/
-	    chmod $chmodv 755 /etc/X11/wmconfig
-	    generate_wmconfig /etc/X11/wmconfig
+	    mkdir $mkdirv $mkdirp %%LOCALBASE%%/share/pixmaps/
+	    chmod $chmodv 755 %%LOCALBASE%%/share/pixmaps
+	    cp $cpv $share_dir/images/opera_48x48.png %%LOCALBASE%%/share/pixmaps/linux-opera.png
 	fi
-    elif test -w /etc/X11/wmconfig/
-    then generate_wmconfig /etc/X11/wmconfig
+    elif test -w %%LOCALBASE%%/share/pixmaps/
+    then cp $cpv $share_dir/images/opera_48x48.png %%LOCALBASE%%/share/pixmaps/linux-opera.png
     fi
 
-    if test -d /etc/X11/applnk/
+    if test ! -d %%LOCALBASE%%/share/applications/
     then
-	if test ! -d /etc/X11/applnk/Internet/
+	if test -w %%LOCALBASE%%/share
 	then
-	    if test -w /etc/X11/applnk
-	    then
-		mkdir $mkdirv $mkdirp /etc/X11/applnk/Internet/
-		chmod $chmodv 755 /etc/X11/applnk/Internet
-		generate_desktop /etc/X11/applnk/Internet
-	    fi
-	elif test -w /etc/X11/applnk/Internet
-	then generate_desktop /etc/X11/applnk/Internet
+	    mkdir $mkdirv $mkdirp %%LOCALBASE%%/share/applications/
+	    chmod $chmodv 755 %%LOCALBASE%%/share/applications
+	    generate_desktop %%LOCALBASE%%/share/applications
 	fi
+    elif test -w %%LOCALBASE%%/share/applications
+    then generate_desktop %%LOCALBASE%%/share/applications
     fi
 }
 
