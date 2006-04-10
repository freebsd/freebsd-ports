--- install.sh.orig	Fri Mar 31 14:12:48 2006
+++ install.sh	Mon Apr 10 08:09:43 2006
@@ -397,7 +397,7 @@
 	    mvv=''    # SunOS mv (no -v verbose option)
 	;;
 
-	i[3456]86:FreeBSD|i[3456]86:NetBSD)
+	i[3456]86:FreeBSD|amd64:FreeBSD|i[3456]86:NetBSD)
 		cpf='-f'
 		if test "$verbose" -gt '1'
 		then
@@ -789,7 +789,7 @@
     debug_msg 0 "in generate_wrapper()"
 
     case "${machine}:${os}" in
-	i[3456]86:Linux|x86_64:Linux|i[3456]86:FreeBSD|i[3456]86:NetBSD|i[3456]86:OpenBSD)
+	i[3456]86:Linux|x86_64:Linux|i[3456]86:FreeBSD|amd64:FreeBSD|i[3456]86:NetBSD|i[3456]86:OpenBSD)
 	    wrapper_ibmjava="
 	    IBMJava2-142/jre \\
 	    IBMJava2-141/jre \\
@@ -832,10 +832,19 @@
 OPERA_SCRIPT_PATH=$0
 export OPERA_SCRIPT_PATH
 
+# Location of locale data
+if [ -f %%LOCALBASE%%/share/compat/locale/UTF-8/LC_CTYPE ]; then
+    PATH_LOCALE=%%LOCALBASE%%/share/compat/locale
+    export PATH_LOCALE
+fi
+
 # Location of the Opera binaries
 OPERA_BINARYDIR=${str_localdirexec}
 export OPERA_BINARYDIR
 
+# Make sure the compat libraries are found
+test -d %%LOCALBASE%%/lib/compat/ && LD_LIBRARY_PATH=\"\${LD_LIBRARY_PATH}:%%LOCALBASE%%/lib/compat/\"
+
 # Parse commandline parameters
 toset=
 _QTSTYLE_FROM_CMDLINE_='NO'
@@ -887,6 +896,9 @@
 OPERA_LD_PRELOAD=\"\${LD_PRELOAD}\"
 export OPERA_LD_PRELOAD
 
+OPERA_PERSONALDIR=\${HOME}/.opera
+export OPERA_PERSONALDIR
+
 # Native Java enviroment
 if test -f \"\${OPERA_PERSONALDIR}/javapath.txt\"; then
     INIJAVA=\`cat \${OPERA_PERSONALDIR}/javapath.txt\`
@@ -910,69 +922,12 @@
 
 if test ! \"\${OPERA_JAVA_DIR}\"; then
 
-    PREFIXES=\"
-	/usr
-	/usr/java
-	/usr/lib
-	/usr/local
-	/opt\"
+	PREFIXES=\"%%LOCALBASE%%\"
 
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
+	jdk1.3.1/jre \\
+	jdk1.4.2/jre \\
+	jdk1.5.0/jre \\
 	; do
 	for PREFIX in \${PREFIXES}; do
 	    if test -f \"\${PREFIX}/\${SUNJAVA}/lib/${wrapper_sunjava_machine}/libjava.so\"; then OPERA_JAVA_DIR=\"\${PREFIX}/\${SUNJAVA}/lib/${wrapper_sunjava_machine}\" && break; fi
@@ -1023,11 +978,8 @@
 
 # Acrobat Reader
 for BINDIR in \\
-    /usr/local/Acrobat[45]/bin \\
-    /usr/lib/Acrobat[45]/bin \\
-    /usr/X11R6/lib/Acrobat[45]/bin \\
-    /opt/Acrobat[45]/bin \\
-    /usr/Acrobat[45]/bin \\
+	%%LOCALBASE%%/Acrobat4/bin \\
+	%%LOCALBASE%%/Acrobat5/bin \\
     ; do
     if test -d \${BINDIR} ; then PATH=\${PATH}:\${BINDIR}; fi
 done
@@ -1038,12 +990,13 @@
 LD_LIBRARY_PATH=\"\${OPERA_BINARYDIR}\${LD_LIBRARY_PATH:+:}\${LD_LIBRARY_PATH}\"
 export LD_LIBRARY_PATH
 
-# Spellchecker needs to find libaspell.so.15
+# Spellchecker needs to find libaspell.so.16
 for LIBASPELL_DIR in \\
+    %%LOCALBASE%%/lib \\
     /usr/local/lib \\
     /opkg/lib \\
 ; do
-    if test -f \"\${LIBASPELL_DIR}/libaspell.so.15\"; then
+    if test -f \"\${LIBASPELL_DIR}/libaspell.so.16\"; then
         LD_LIBRARY_PATH=\"\${LD_LIBRARY_PATH}:\${LIBASPELL_DIR}\"
     fi
 done"
@@ -1153,7 +1106,7 @@
     chop "${OPERADESTDIR}" "str_localdirshare"
     chop "${OPERADESTDIR}" "str_localdirplugin"
 
-    backup ${wrapper_dir}/opera opera
+    #backup ${wrapper_dir}/opera opera
 
     # Executable
     debug_msg 1 "Executable"
@@ -1193,15 +1146,6 @@
     generate_wrapper
     chmod $chmodv 755 $wrapper_dir/opera
 
-    # Manual page
-    debug_msg 1 "Manual page"
-
-    mkdir $mkdirv $mkdirp ${man_dir}
-    chmod $chmodv 755 ${man_dir}
-    mkdir $mkdirv $mkdirp ${man_dir}/man1
-    chmod $chmodv 755 ${man_dir}/man1
-    cp $cpv $cpf man/opera.1 ${man_dir}/man1
-
     # Documentation
     debug_msg 1 "Documentation"
 
@@ -1377,44 +1321,13 @@
 
     if test -z "${OPERADESTDIR}"
     then
-	# System wide configuration files
-	config_dir='/usr/local/etc'
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
 	then
-	    xdg
+		gnome
+		kde 3
 	fi
 
     fi # OPERADESTDIR
@@ -1623,48 +1536,42 @@
     # This function searches for common gnome icon paths.
     debug_msg 1 "in gnome()"
 
-    if test -d /opt/gnome/
+    if test -d %%X11BASE%%/share/gnome/;
     then
-	# /opt/gnome share
-	if test -d /opt/gnome/share
-	then
-	    # /opt/gnome icon
-	    if test ! -d /opt/gnome/share/pixmaps/
+	   # %%X11BASE%%/share/gnome icon
+           if test ! -d %%X11BASE%%/share/gnome/pixmaps
 	    then
-		if test -w /opt/gnome/share
+		if test -w %%X11BASE%%/share/gnome;
 		then
-		    mkdir $mkdirv $mkdirp /opt/gnome/share/pixmaps/
-		    chmod $chmodv 755 /opt/gnome/share/pixmaps
-		    cp $cpv $share_dir/images/opera.xpm /opt/gnome/share/pixmaps/opera.xpm
+                   mkdir $mkdirv $mkdirp %%X11BASE%%/share/gnome/pixmaps/
+                   chmod $chmodv 755 %%X11BASE%%/share/gnome/pixmaps
+                   cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/gnome/pixmaps/opera.xpm
 		fi
-	    elif test -w /opt/gnome/share/pixmaps
-	    then cp $cpv $share_dir/images/opera.xpm /opt/gnome/share/pixmaps/opera.xpm
+           elif test -w %%X11BASE%%/share/gnome/pixmaps
+           then cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/gnome/pixmaps/opera.xpm
 	    fi
-	    # end /opt/gnome icon
-
-	    # /opt/gnome link
-	    if test -d /opt/gnome/share/gnome/apps/
+           # end %%X11BASE%%/share/gnome icon
+           # %%X11BASE%%/share/gnome link
+           if test -d %%X11BASE%%/share/gnome/apps/
 	    then
-		if test -d /opt/gnome/share/gnome/apps/Internet/
+               if test -d %%X11BASE%%/share/gnome/apps/Internet/
 		then
-		    if test -w /opt/gnome/share/gnome/apps/Internet
-		    then generate_desktop /opt/gnome/share/gnome/apps/Internet
+                   if test -w %%X11BASE%%/share/gnome/apps/Internet
+                   then generate_desktop %%X11BASE%%/share/gnome/apps/Internet
 		    fi
-		elif test -d /opt/gnome/share/gnome/apps/Networking/WWW/
+               elif test -d %%X11BASE%%/share/gnome/apps/Networking/WWW/
 		then
-		    if test -w /opt/gnome/share/gnome/apps/Networking/WWW
-		    then generate_desktop /opt/gnome/share/gnome/apps/Networking/WWW
+                   if test -w %%X11BASE%%/share/gnome/apps/Networking/WWW
+                   then generate_desktop %%X11BASE%%/share/gnome/apps/Networking/WWW
 		    fi
-		elif test -w /opt/gnome/share/gnome/apps
+               elif test -w %%X11BASE%%/share/gnome/apps
 		then
-		    mkdir $mkdirv $mkdirp /opt/gnome/share/gnome/apps/Internet/
-		    chmod $chmodv 755 /opt/gnome/share/gnome/apps/Internet
-		    generate_desktop /opt/gnome/share/gnome/apps/Internet
+                   mkdir $mkdirv $mkdirp %%X11BASE%%/share/gnome/apps/Internet/
+                   chmod $chmodv 755 %%X11BASE%%/share/gnome/apps/Internet
+                   generate_desktop %%X11BASE%%/share/gnome/apps/Internet
 		fi
 	    fi
-	    # end /opt/gnome link
-	fi
-	# end /opt/gnome share
+           # end %%X11BASE%%/share/gnome link
 
     elif test -d /usr/share/gnome/
     then
@@ -1712,9 +1619,9 @@
     # This function searches for common kde2 and kde 3 icon paths.
     debug_msg 1 "in kde()"
 
-    if test -d /opt/kde$1/share
+    if test -d %%LOCALBASE%%/share;
     then
-	DIR_HI=/opt/kde$1/share/icons/hicolor
+        DIR_HI=%%LOCALBASE%%/share/icons/hicolor
 	if test -d "$DIR_HI" -a -w "$DIR_HI"
 	then
 	    if test -d "$DIR_HI"/48x48/apps -a -w "$DIR_HI"/48x48/apps
@@ -1728,7 +1635,7 @@
 	    fi
 	fi
 
-	DIR_LO=/opt/kde$1/share/icons/locolor
+        DIR_LO=%%LOCALBASE%%/share/icons/locolor
 	if test -d $DIR_LO -a -w $DIR_LO
 	then
 	    if test -d $DIR_LO/32x32/apps -a -w $DIR_LO/32x32/apps
@@ -1742,15 +1649,15 @@
 	    fi
 	fi
 
-	if test -d /opt/kde$1/share/applnk/
+        if test -d %%LOCALBASE%%/share/applnk/
 	then
-	    if test ! -d /opt/kde$1/share/applnk/Internet/ -a -w /opt/kde$1/share/applnk
+            if test ! -d %%LOCALBASE%%/share/applnk/Internet/ -a -w %%LOCALBASE%%/share/applnk
 	    then
-		mkdir $mkdirv $mkdirp /opt/kde$1/share/applnk/Internet/
-		chmod $chmodv 755 /opt/kde$1/share/applnk/Internet
+                mkdir $mkdirv $mkdirp %%LOCALBASE%%/share/applnk/Internet/
+                chmod $chmodv 755 %%LOCALBASE%%/share/applnk/Internet
 	    fi
-	    if test -w /opt/kde$1/share/applnk/Internet
-	    then generate_desktop /opt/kde$1/share/applnk/Internet $1
+            if test -w %%LOCALBASE%%/share/applnk/Internet
+            then generate_desktop %%LOCALBASE%%/share/applnk/Internet $1
 	    fi
 	fi
     fi
@@ -1866,12 +1773,8 @@
 	generate_desktop ${SHORTCUT_DIR} xdg
 	${UDD}
     else
-	icons
 	gnome
 	kde 3
-	kde 2
-	kde1
-	mandrake
     fi
 }
 
