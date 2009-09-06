--- install.sh.orig	2009-08-30 14:25:11.000000000 -0500
+++ install.sh	2009-08-30 16:51:54.000000000 -0500
@@ -832,10 +832,9 @@
     case "${machine}:${os}" in
 	x86:Linux|x86_64:Linux|x86:AnyBSD|x86_64:AnyBSD|x86:OpenBSD|x86_64:OpenBSD|x86:QNX)
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
 
@@ -865,10 +864,19 @@
 		error os
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
@@ -928,8 +936,12 @@
 OPERA_LD_PRELOAD=\"\${LD_PRELOAD}\"
 export OPERA_LD_PRELOAD
 
+# ~/.linux-opera
+OPERA_PERSONALDIR=\${HOME}/.linux-opera
+export OPERA_PERSONALDIR
+
 # Native Java enviroment
-for d in \"\$OPERA_PERSONALDIR\" \"\$HOME/.opera\"
+for d in \"\$OPERA_PERSONALDIR\" \"\$HOME/.linux-opera\"
 do if test -f \"\$d/javapath.txt\"
    then
       INIJAVA=\`cat \"\$d/javapath.txt\"\`
@@ -950,88 +962,17 @@
 
 if test ! \"\${OPERA_JAVA_DIR}\"
 then
-    PREFIXES=\"
-	/usr
-	/usr/java
-	/usr/lib
-	/usr/local
-	/opt\"
+    PREFIXES=\"%%LOCALBASE%%\"
 
     for SUNJAVA in \\
-	java-6-sun \\
-	java-6-sun-1.6.0.00 \\
-	java-1.5.0-sun \\
-	java-1.5.0-sun-1.5.0.09 \\
-	java-1.5.0-sun-1.5.0.09/jre \\
-	java-1.5.0-sun-1.5.0.08 \\
-	java-1.5.0-sun-1.5.0.08/jre \\
-	java-1.5.0-sun-1.5.0.07 \\
-	java-1.5.0-sun-1.5.0.07/jre \\
-	java-1.5.0-sun-1.5.0.06 \\
-	java-1.5.0-sun-1.5.0.06/jre \\
-	jre1.5.0_06 \\
-	jdk1.5.0_06/jre \\
-	java-1.5.0-sun-1.5.0.05 \\
-	java-1.5.0-sun-1.5.0.05/jre \\
-	jre1.5.0_05 \\
-	jdk1.5.0_05/jre \\
-	java-1.5.0-sun-1.5.0.04 \\
-	java-1.5.0-sun-1.5.0.04/jre \\
-	jre1.5.0_04 \\
-	jdk1.5.0_04/jre \\
-	jre1.5.0_03 \\
-	jdk1.5.0_03/jre \\
-	jre1.5.0_02 \\
-	jdk1.5.0_02/jre \\
-	jre1.5.0_01 \\
-	jdk1.5.0_01/jre \\
-	jdk1.5.0/jre \\
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
-	jdk1.3.1/jre \\
-	jdk1.4.2/jre \\
-	jdk1.5.0/jre \\
-	jdk1.6.0/jre \\
-	diablo-jre1.5.0 \\
-	diablo-jdk1.5.0/jre \\
-	diablo-jre1.6.0 \\
-	diablo-jdk1.6.0/jre \\
-	openjdk6/jre \\
+	linux-blackdown-jdk1.3.1/jre \\
+	linux-blackdown-jdk1.4.1/jre \\
+	linux-blackdown-jdk1.4.2/jre \\
+	linux-sun-jdk1.3.1/jre \\
+	linux-sun-jdk1.4.1/jre \\
+	linux-sun-jdk1.4.2/jre \\
+	linux-sun-jdk1.5.0/jre \\
+	linux-sun-jdk1.6.0/jre \\
 	; do
 	for PREFIX in \${PREFIXES}
 	do d=\"\$PREFIX/\$SUNJAVA/lib/$wrapper_sunjava_machine\"
@@ -1085,11 +1026,8 @@
 
 # Acrobat Reader
 for BINDIR in \\
-    /usr/local/Acrobat[45]/bin \\
-    /usr/lib/Acrobat[45]/bin \\
-    /usr/X11R6/lib/Acrobat[45]/bin \\
-    /opt/Acrobat[45]/bin \\
-    /usr/Acrobat[45]/bin \\
+    %%LOCALBASE%%/Adobe/Reader8/ENU/Adobe/Reader8/Reader/intellinux/bin \\
+    %%LOCALBASE%%/Adobe/Reader9/ENU/Adobe/Reader9/Reader/intellinux/bin \\
     ; do
     if test -d \${BINDIR} ; then PATH=\${PATH}:\${BINDIR}; fi
 done
@@ -1102,8 +1040,7 @@
 
 # Spellchecker needs to find libaspell.so.15
 for LIBASPELL_DIR in \\
-    /usr/local/lib \\
-    /opkg/lib \\
+    %%LINUXBASE%%/usr/lib \\
 ; do
     if ls \$LIBASPELL_DIR/libaspell.so.1[5-9] >/dev/null 2>&1
     then LD_LIBRARY_PATH=\"\${LD_LIBRARY_PATH}:\${LIBASPELL_DIR}\"
@@ -1111,13 +1048,6 @@
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
 
@@ -1146,7 +1076,7 @@
 };
 
 // Opera package classes get all permissions
-grant codebase \"file://${str_localdirshare}/java//opera.jar\" {
+grant codebase \"file://${str_localdirshare}/java/opera.jar\" {
 	permission java.security.AllPermission;
 };
 
@@ -1263,12 +1193,12 @@
     chop "${OPERADESTDIR}" "str_localdirshare"
     chop "${OPERADESTDIR}" "str_localdirplugin"
 
-    md5check Manifest.md5
+    #md5check Manifest.md5
     part_install "`manifest_path operapluginwrapper`" "$exec_dir" Binaries
     manifest_contains operapluginwrapper-native && part_install "`manifest_path operapluginwrapper-native`" "$exec_dir" Binaries
     manifest_contains operapluginwrapper-ia32-linux && part_install "`manifest_path operapluginwrapper-ia32-linux`" "$exec_dir" Binaries
     part_install "`manifest_path LICENSE`" "$doc_dir" Documentation
-    part_install "`manifest_path man1/opera.1`" "$man_dir" "Manual page"
+    part_install "`manifest_path man1/linux-opera.1`" "$man_dir" "Manual page"
 
     share_src="`manifest_path 'html40_entities\.dtd'`"
     part_install "$share_src" "$share_dir" "Shared resources"
@@ -1277,84 +1207,20 @@
     mkdir $mkdirv $mkdirp $plugin_dir/
 
     # Wrapper
-    backup ${wrapper_dir}/opera opera
+    #backup ${wrapper_dir}/opera opera
     debug_msg 1 "Wrapper"
     mkdir $mkdirv $mkdirp $wrapper_dir/
 
     #cp $cpv $cpf wrapper.sh $wrapper_dir/opera
     generate_wrapper
-    chmod $chmodv 755 $wrapper_dir/opera
+    chmod $chmodv 755 $wrapper_dir/linux-opera
 
     if test -z "$OPERADESTDIR"
     then
-	# System wide configuration files
-	case $os in AnyBSD|OpenBSD) config_dir="/usr/local/etc";; *) config_dir="/etc";; esac
-	# TODO: work out what's going on here and replace with something that sets OPERA_ROOTPREFS to where they went !
-	if can_write_to "$config_dir"
-	then
-	    warn
-	    warn "System wide configuration files:"
-	    warn "  $config_dir/operaprefs_default.ini"
-	    warn "  $config_dir/operaprefs_fixed.ini"
-	    warn " would be ignored if installed with the prefix \"$prefix\"."
-	    bool_config=1
-	    if [ "$flag_mode" = '--interactive' ]
-	    then con_firm "Do you want to install them in $config_dir" || bool_config=0
-	    else warn "Installing in default location $config_dir instead."
-	    fi
-
-	    if [ $bool_config -eq 1 ]
-	    then
-			if [ -f "$config_dir/opera6rc" ]
-			then
-				mv -f "$config_dir/opera6rc" "$config_dir/operaprefs_default.ini"
-			fi
-			if [ -f "$config_dir/opera6rc.fixed" ]
-			then
-				mv -f "$config_dir/opera6rc.fixed" "$config_dir/operaprefs_fixed.ini"
-			fi
-			if [ -f "$config_dir/operaprefs_default.ini" ]
-			then
-				if [ "$flag_mode" = '--interactive' ] && con_firm "$config_dir/operaprefs_default.ini exists: over-write it ?"
-				then
-					backup $config_dir/operaprefs_default.ini operaprefs_default.ini config
-					cp $cpv $cpf etc/operaprefs_default.ini $config_dir
-				fi
-			else cp $cpv $cpf etc/operaprefs_default.ini $config_dir
-			fi
-			if [ -f "$config_dir/operaprefs_fixed.ini" ]
-			then
-				if [ "$flag_mode" = '--interactive' ] && con_firm "$config_dir/operaprefs_fixed.ini exists: over-write it ?"
-				then
-					backup $config_dir/operaprefs_fixed.ini operaprefs_fixed.ini config
-					cp $cpv $cpf etc/operaprefs_fixed.ini $config_dir
-				fi
-			else cp $cpv $cpf etc/operaprefs_fixed.ini $config_dir
-			fi
-	    fi
-	else
-	    warn
-	    warn "User \"${USERNAME}\" does not have write access to $config_dir"
-	    warn " System wide configuration files:"
-	    warn "  $config_dir/operaprefs_default.ini"
-	    warn "  $config_dir/operaprefs_fixed.ini"
-	    warn " were not installed."
-	fi
-
 	# Shorcuts and Icons
 	bool_icons=1 # install icons by default
-	if test "${flag_mode}" = "--force" -o "${flag_mode}" = "--prefix="
-	then
-	    warn
-	    warn "Shortcut icons would be ignored if installed with the prefix \"$prefix\"."
-	    if [ "$flag_mode" = "--force" ]
-	    then warn "Installing them in default locations."
-	    else bool_icons=0; warn "Ignoring them; menus shall lack nice icons."
-	    fi
-	fi
-
 	if test "$bool_icons" -ne 0
-	then xdg
+	then icons
 	fi
 
     fi # OPERADESTDIR
@@ -1403,24 +1269,24 @@
     echo '[Desktop Entry]'
     if test -z "$1"
     then cat <<EOF
-Name=Opera
-Exec=opera
-Icon=opera.xpm
+Name=Opera (linux version)
+Exec=linux-opera
+Icon=linux-opera.xpm
 Terminal=false
 EOF
     else
 	if test "$1" = "xdg"
 	then cat <<EOF
 Version=1.0
-TryExec=opera
+TryExec=linux-opera
 EOF
 	fi
 	cat <<EOF
 Encoding=UTF-8
-Name=Opera
-Name[af]=opera
-Name[eo]=Opero
-Name[zu]=I Opera
+Name=Opera (linux version)
+Name[af]=opera (linux version)
+Name[eo]=Opero (linux version)
+Name[zu]=I Opera (linux version)
 GenericName=Web browser
 GenericName[bs]=Web preglednik
 GenericName[de]=Web-Browser
@@ -1441,7 +1307,7 @@
 GenericName[ven]=Buronza ya Webu
 GenericName[xh]=Umkhangeli Zincwadi Zokubhaliweyo
 GenericName[zu]=Umkhangeli zincwadi we Web
-Exec=opera %u
+Exec=linux-opera %u
 Terminal=false
 EOF
 
@@ -1457,15 +1323,16 @@
 	if test "$1" = "xdg"
 	then cat <<EOF
 Categories=Application;Qt;Network;WebBrowser;X-Ximian-Main;X-Ximian-Toplevel
-Icon=opera.png
+Icon=linux-opera.png
 EOF
-	else echo 'Icon=opera'
+	else echo 'Icon=linux-opera'
 	fi
 	echo 'MimeType=text/html;text/xml;application/xhtml+xml'
     fi
     cat <<EOF
 Comment=Web Browser
 Type=Application
+Categories=Application;Network;WebBrowser;
 EOF
 }
 
@@ -1473,7 +1340,7 @@
 {
     # arg1 = location
     # arg2 = type
-    desktop_content $2 > "$1/opera.desktop" && chmod $chmodv 644 "$1/opera.desktop"
+    desktop_content $2 > "$1/linux-opera.desktop" && chmod $chmodv 644 "$1/linux-opera.desktop"
 }
 
 generate_mdk_menu()
@@ -1498,51 +1365,26 @@
 
     debug_msg 0 "in icons()"
 
-    if test ! -d /usr/share/icons
-    then
-	if test -w /usr/share
-	then
-	    mkdir $mkdirv $mkdirp /usr/share/icons/
-	    cp $cpv $share_src/pixmaps/opera.xpm /usr/share/icons/opera.xpm
-	fi
-    elif test -w /usr/share/icons
-    then cp $cpv $share_src/pixmaps/opera.xpm /usr/share/icons/opera.xpm
-    fi
-
-    if test ! -d /usr/share/pixmaps
+    if test ! -d %%LOCALBASE%%/share/pixmaps/
     then
-	if test -w /usr/share
+	if test -w %%LOCALBASE%%/share
 	then
-	    mkdir $mkdirv $mkdirp /usr/share/pixmaps/
-	    cp $cpv $share_src/pixmaps/opera.xpm /usr/share/pixmaps/opera.xpm
+	    mkdir $mkdirv $mkdirp %%LOCALBASE%%/share/pixmaps/
+	    cp $cpv usr/share/icons/hicolor/48x48/apps/opera.png %%LOCALBASE%%/share/pixmaps/linux-opera.png
 	fi
-    elif test -w /usr/share/pixmaps/
-    then cp $cpv $share_src/pixmaps/opera.xpm /usr/share/pixmaps/opera.xpm
+    elif test -w %%LOCALBASE%%/share/pixmaps/
+    then cp $cpv usr/share/icons/hicolor/48x48/apps/opera.png %%LOCALBASE%%/share/pixmaps/linux-opera.png
     fi
 
-    if test ! -d /etc/X11/wmconfig/
+    if test ! -d %%LOCALBASE%%/share/applications/
     then
-	if test -w /etc/X11
+	if test -w %%LOCALBASE%%/share
 	then
-	    mkdir $mkdirv $mkdirp /etc/X11/wmconfig/
-	    generate_wmconfig /etc/X11/wmconfig
-	fi
-    elif test -w /etc/X11/wmconfig/
-    then generate_wmconfig /etc/X11/wmconfig
-    fi
-
-    if test -d /etc/X11/applnk/
-    then
-	if test ! -d /etc/X11/applnk/Internet/
-	then
-	    if test -w /etc/X11/applnk
-	    then
-		mkdir $mkdirv $mkdirp /etc/X11/applnk/Internet/
-		generate_desktop /etc/X11/applnk/Internet
-	    fi
-	elif test -w /etc/X11/applnk/Internet
-	then generate_desktop /etc/X11/applnk/Internet
+	    mkdir $mkdirv $mkdirp %%LOCALBASE%%/share/applications/
+	    generate_desktop %%LOCALBASE%%/share/applications
 	fi
+    elif test -w %%LOCALBASE%%/share/applications
+    then generate_desktop %%LOCALBASE%%/share/applications
     fi
 }
 
