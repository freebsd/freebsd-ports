--- install.sh.orig	Tue Nov 16 15:11:43 2004
+++ install.sh	Tue Nov 16 15:26:04 2004
@@ -108,8 +108,8 @@
 
     if test ${os} = 'FreeBSD' -o ${os} = 'OpenBSD'; then
         wrapper_dir="${prefix}/bin"
-        doc_dir="${prefix}/share/doc/opera"
-        share_dir="${prefix}/share/opera"
+        doc_dir="${prefix}/share/doc/opera-devel"
+        share_dir="${prefix}/share/opera-devel"
         exec_dir="${share_dir}/bin"
         plugin_dir="${share_dir}/plugins"
     else
@@ -373,7 +373,7 @@
 	    mvv=''    # SunOS mv (no -v verbose option)
 	;;
 
-	i[3456]86:FreeBSD|i[3456]86:NetBSD)
+	i[3456]86:FreeBSD|amd64:FreeBSD|i[3456]86:NetBSD)
 		cpf='-f'
 		if test "$verbose" -gt '1'; then
 		    chmodv='-v'
@@ -759,7 +759,7 @@
     debug_msg 0 "in generate_wrapper()"
 
     case "${machine}:${os}" in
-	i[3456]86:Linux|x86_64:Linux|i[3456]86:FreeBSD|i[3456]86:NetBSD|i[3456]86:OpenBSD)
+	i[3456]86:Linux|x86_64:Linux|i[3456]86:FreeBSD|amd64:FreeBSD|i[3456]86:NetBSD|i[3456]86:OpenBSD)
 	    wrapper_ibmjava="
 	    IBMJava2-142/jre \\
 	    IBMJava2-141/jre \\
@@ -794,7 +794,7 @@
 		error 'os'
 	;;
     esac
-    wrapper_file="${wrapper_dir}/opera"
+    wrapper_file="${wrapper_dir}/opera-devel"
     
     wrapper_contain="#!/bin/sh
 
@@ -838,6 +838,9 @@
 OPERA_LD_PRELOAD=\"\${LD_PRELOAD}\"
 export OPERA_LD_PRELOAD
 
+OPERA_PERSONALDIR=\${HOME}/.opera-devel
+export OPERA_PERSONALDIR
+
 # Native Java enviroment
 if test -f \"\${OPERA_PERSONALDIR}/javapath.txt\"; then
     INIJAVA=\`cat \${OPERA_PERSONALDIR}/javapath.txt\`
@@ -861,47 +864,12 @@
 
 if test ! \"\${OPERA_JAVA_DIR}\"; then
 
-    PREFIXES=\"
-	/usr
-	/usr/java
-	/usr/lib
-	/usr/local
-	/opt\"
+    PREFIXES=\"%%LOCALBASE%%\"
 
     for SUNJAVA in \\
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
-	jre1.3.1_02 \\
-	jre1.3.1_01 \\
-	j2re1.3.1 \\
-	jre1.3.1 \\
-	j2re1.3 \\
-	j2se/1.3/jre \\
-	SunJava2-1.3/jre \\
-	java2re \\
 	jdk1.2.2/jre \\
-	jdk1.2/jre \\
-	jre \\
-	java \\
+	jdk1.3.1/jre \\
+	jdk1.4.2/jre \\
 	; do
 	for PREFIX in \${PREFIXES}; do
 	    if test -f \"\${PREFIX}/\${SUNJAVA}/lib/${wrapper_sunjava_machine}/libjava.so\"; then OPERA_JAVA_DIR=\"\${PREFIX}/\${SUNJAVA}/lib/${wrapper_sunjava_machine}\" && break; fi
@@ -950,11 +918,8 @@
 
 # Acrobat Reader
 for BINDIR in \\
-    /usr/local/Acrobat[45]/bin \\
-    /usr/lib/Acrobat[45]/bin \\
-    /usr/X11R6/lib/Acrobat[45]/bin \\
-    /opt/Acrobat[45]/bin \\
-    /usr/Acrobat[45]/bin \\
+    %%LOCALBASE%%/Acrobat4/bin \\
+    %%LOCALBASE%%/Acrobat5/bin \\
     ; do
     if test -d \${BINDIR} ; then PATH=\${PATH}:\${BINDIR}; fi
 done
@@ -965,12 +930,13 @@
 LD_LIBRARY_PATH=\"\${OPERA_BINARYDIR}:\${LD_LIBRARY_PATH}\"
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
 done
@@ -1064,7 +1030,7 @@
     chop "${OPERADESTDIR}" "str_localdirshare"
     chop "${OPERADESTDIR}" "str_localdirplugin"
 
-    backup ${wrapper_dir}/opera opera
+    #backup ${wrapper_dir}/opera opera
 
     # Executable
 	debug_msg 1 "Executable"
@@ -1099,7 +1065,7 @@
 
 	#cp $cpv $cpf wrapper.sh $wrapper_dir/opera
 	generate_wrapper
-        chmod $chmodv 755 $wrapper_dir/opera
+        chmod $chmodv 755 $wrapper_file
 
     # Documentation
 	debug_msg 1 "Documentation"
@@ -1264,36 +1230,13 @@
 
 	if test -z "${OPERADESTDIR}"; then
 
-	# System wide configuration files
-	config_dir='/usr/local/etc'
-	if can_write_to "$config_dir"; then
-	    echo
-	    echo "System wide configuration files:"
-	    echo "  $config_dir/opera6rc"
-	    echo "  $config_dir/opera6rc.fixed"
-	    echo " cannot be prefixed"
-	    if con_firm "Do you want to install them"; then
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
-	    echo " were not installed"
-	fi
-
      # Shorcuts and Icons
-	icons
+	#icons
 	gnome
 	kde 3
-	kde 2
-	kde1
-	mandrake
+	#kde 2
+	#kde1
+	#mandrake
 
 	fi # OPERADESTDIR
 
@@ -1321,13 +1264,13 @@
 {
     # arg1 = location
 
-    wmconfig_file="${1}/opera"
+    wmconfig_file="${1}/opera-devel"
 
-    wmconfig_contain='opera name "Opera"
+    wmconfig_contain='opera name "Opera Beta"
 opera description "Opera Web Browser"
 opera icon "opera.xpm"
 opera mini-icon "opera.xpm"
-opera exec "opera &"
+opera exec "opera-devel &"
 opera group "Internet"'
 
     echo "${wmconfig_contain}" > ${wmconfig_file}
@@ -1338,12 +1281,12 @@
 {
     # arg1 = location
 
-    desktop_file="${1}/opera.desktop"
+    desktop_file="${1}/opera-devel.desktop"
 
     desktop_contain='[Desktop Entry]
-Name=Opera
+Name=Opera Beta
 Comment=Web Browser
-Exec=opera
+Exec=opera-devel
 Icon=opera.xpm
 Terminal=0
 Type=Application'
@@ -1422,72 +1365,36 @@
 
     debug_msg 1 "in gnome()"
 
-    if test -d /opt/gnome/; then
-
-      # /opt/gnome share
-      if test -d /opt/gnome/share; then
+    if test -d %%X11BASE%%/share/gnome/; then
 
-        # /opt/gnome icon
-        if test ! -d /opt/gnome/share/pixmaps/; then
-	  if test -w /opt/gnome/share; then
-	    mkdir $mkdirv $mkdirp /opt/gnome/share/pixmaps/
-	    chmod $chmodv 755 /opt/gnome/share/pixmaps
-	    cp $cpv $share_dir/images/opera.xpm /opt/gnome/share/pixmaps/opera.xpm
+        # %%X11BASE%%/share/gnome icon
+        if test ! -d %%X11BASE%%/share/gnome/pixmaps/; then
+	  if test -w %%X11BASE%%/share/gnome; then
+	    mkdir $mkdirv $mkdirp %%X11BASE%%/share/gnome/pixmaps/
+	    chmod $chmodv 755 %%X11BASE%%/share/gnome/pixmaps
+	    cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/gnome/pixmaps/opera.xpm
 	  fi
-	elif test -w /opt/gnome/share/pixmaps; then cp $cpv $share_dir/images/opera.xpm /opt/gnome/share/pixmaps/opera.xpm
+	elif test -w %%X11BASE%%/share/gnome/pixmaps; then cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/gnome/pixmaps/opera.xpm
 	fi
-	# end /opt/gnome icon
+	# end %%X11BASE%%/share/gnome icon
 
-	# /opt/gnome link
-	if test -d /opt/gnome/share/gnome/apps/; then
-          if test -d /opt/gnome/share/gnome/apps/Internet/; then
-            if test -w /opt/gnome/share/gnome/apps/Internet; then
-              generate_desktop /opt/gnome/share/gnome/apps/Internet
+	# %%X11BASE%%/share/gnome link
+	if test -d %%X11BASE%%/share/gnome/apps/; then
+          if test -d %%X11BASE%%/share/gnome/apps/Internet/; then
+            if test -w %%X11BASE%%/share/gnome/apps/Internet; then
+              generate_desktop %%X11BASE%%/share/gnome/apps/Internet
 	    fi
-          elif test -d /opt/gnome/share/gnome/apps/Networking/WWW/; then
-            if test -w /opt/gnome/share/gnome/apps/Networking/WWW; then
-	      generate_desktop /opt/gnome/share/gnome/apps/Networking/WWW
+          elif test -d %%X11BASE%%/share/gnome/apps/Networking/WWW/; then
+            if test -w %%X11BASE%%/share/gnome/apps/Networking/WWW; then
+	     generate_desktop %%X11BASE%%/share/gnome/apps/Networking/WWW
 	    fi
-	  elif test -w /opt/gnome/share/gnome/apps; then
-	    mkdir $mkdirv $mkdirp /opt/gnome/share/gnome/apps/Internet/
-	    chmod $chmodv 755 /opt/gnome/share/gnome/apps/Internet
-            generate_desktop /opt/gnome/share/gnome/apps/Internet
+	  elif test -w %%X11BASE%%/share/gnome/apps; then
+	    mkdir $mkdirv $mkdirp %%X11BASE%%/share/gnome/apps/Internet/
+	    chmod $chmodv 755 %%X11BASE%%/share/gnome/apps/Internet
+            generate_desktop %%X11BASE%%/share/gnome/apps/Internet
           fi
 	fi
-	# end /opt/gnome link
-      fi
-      # end /opt/gnome share
-
-    elif test -d /usr/share/gnome/; then
-
-        # /usr/share/gnome icon
-        if test ! -d /usr/share/gnome/pixmaps/; then
-	  if test -w /usr/share/gnome; then
-	    mkdir $mkdirv $mkdirp /usr/share/gnome/pixmaps/
-	    chmod $chmodv 755 /usr/share/gnome/pixmaps
-	    cp $cpv $share_dir/images/opera.xpm /usr/share/gnome/pixmaps/opera.xpm
-	  fi
-	elif test -w /usr/share/gnome/pixmaps; then cp $cpv $share_dir/images/opera.xpm /usr/share/gnome/pixmaps/opera.xpm
-	fi
-	# end /usr/share/gnome icon
-
-	# /usr/share/gnome link
-	if test -d /usr/share/gnome/apps/; then
-          if test -d /usr/share/gnome/apps/Internet/; then
-            if test -w /usr/share/gnome/apps/Internet; then
-              generate_desktop /usr/share/gnome/apps/Internet
-	    fi
-          elif test -d /usr/share/gnome/apps/Networking/WWW/; then
-            if test -w /usr/share/gnome/apps/Networking/WWW; then
-	     generate_desktop /usr/share/gnome/apps/Networking/WWW
-	    fi
-	  elif test -w /usr/share/gnome/apps; then
-	    mkdir $mkdirv $mkdirp /usr/share/gnome/apps/Internet/
-	    chmod $chmodv 755 /usr/share/gnome/apps/Internet
-            generate_desktop /usr/share/gnome/apps/Internet
-          fi
-	fi
-	# end /usr/share/gnome link
+	# end %%X11BASE%%/share/gnome link
    fi
    # Add ximian here
 }
@@ -1498,39 +1405,31 @@
 
     debug_msg 1 "in kde()"
 
-    if test -d /opt/kde${1}/share; then
+    if test -d %%LOCALBASE%%/share; then
 
-      DIR_HI=/opt/kde${1}/share/icons/hicolor
+      DIR_HI=%%LOCALBASE%%/share/icons/hicolor
       if test -d "$DIR_HI" -a -w "$DIR_HI"; then
         if test -d "$DIR_HI"/48x48/apps -a -w "$DIR_HI"/48x48/apps; then cp $cpv $share_dir/images/opera_48x48.png $DIR_HI/48x48/apps/opera.png; fi
         if test -d "$DIR_HI"/32x32/apps -a -w "$DIR_HI"/32x32/apps; then cp $cpv $share_dir/images/opera_32x32.png $DIR_HI/32x32/apps/opera.png; fi
         if test -d "$DIR_HI"/22x22/apps -a -w "$DIR_HI"/22x22/apps; then cp $cpv $share_dir/images/opera_22x22.png $DIR_HI/22x22/apps/opera.png; fi
       fi
 
-      DIR_LO=/opt/kde${1}/share/icons/locolor
+      DIR_LO=%%LOCALBASE%%/share/icons/locolor
       if test -d $DIR_LO -a -w $DIR_LO; then
         if test -d $DIR_LO/32x32/apps -a -w $DIR_LO/32x32/apps; then cp $cpv $share_dir/images/opera_32x32.png $DIR_LO/32x32/apps/opera.png; fi
         if test -d $DIR_LO/22x22/apps -a -w $DIR_LO/22x22/apps; then cp $cpv $share_dir/images/opera_22x22.png $DIR_LO/22x22/apps/opera.png; fi
         if test -d $DIR_LO/16x16/apps -a -w $DIR_LO/16x16/apps; then cp $cpv $share_dir/images/opera_16x16.png $DIR_LO/16x16/apps/opera.png; fi
       fi
 
-      if test -d /opt/kde${1}/share/applnk/; then
-        if test ! -d /opt/kde${1}/share/applnk/Internet/ -a -w /opt/kde${1}/share/applnk; then
-	    mkdir $mkdirv $mkdirp /opt/kde${1}/share/applnk/Internet/
-	    chmod $chmodv 755 /opt/kde${1}/share/applnk/Internet
+      if test -d %%LOCALBASE%%/share/applnk/; then
+        if test ! -d %%LOCALBASE%%/share/applnk/Internet/ -a -w %%LOCALBASE%%/share/applnk; then
+	    mkdir $mkdirv $mkdirp %%LOCALBASE%%/share/applnk/Internet/
+	    chmod $chmodv 755 %%LOCALBASE%%/share/applnk/Internet
 	fi
-	if test -w /opt/kde${1}/share/applnk/Internet; then generate_desktop /opt/kde${1}/share/applnk/Internet ${1}; fi
+	if test -w %%LOCALBASE%%/share/applnk/Internet; then generate_desktop %%LOCALBASE%%/share/applnk/Internet ${1}; fi
       fi
 
     fi  
-    
-    if test -d /usr/share/applnk/Networking; then
-      if test ! -d /usr/share/applnk/Networking/WWW/ -a -w /usr/share/applnk/Networking; then
-	    mkdir $mkdirv $mkdirp /usr/share/applnk/Networking/WWW/
-	    chmod $chmodv 755 /usr/share/applnk/Networking/WWW
-      fi
-      if test -w /usr/share/applnk/Networking/WWW; then generate_desktop /usr/share/applnk/Networking/WWW ${1}; fi
-    fi
 }
 
 kde1()
