--- install.sh.orig	Wed Jun  2 05:13:50 2004
+++ install.sh	Sun Jun  6 01:48:11 2004
@@ -758,25 +758,21 @@
 
     debug_msg 0 "in generate_wrapper()"
 
-    wrapper_opera_plugin_paths="    \"\${HOME}/.opera/plugins\" \\
-    ${str_localdirplugin} \\
-    /usr/lib/opera/plugins \\
-    /usr/local/lib/opera/plugins \\
-    /opt/lib/opera/plugins \\"
+    wrapper_opera_plugin_paths="    \"\${HOME}/.linux-opera/plugins\" \\
+    ${str_localdirplugin} \\"
 
     case "${machine}:${os}" in
 	i[3456]86:Linux|x86_64:Linux|i[3456]86:FreeBSD|i[3456]86:NetBSD|i[3456]86:OpenBSD)
 	    wrapper_plugin_paths="
-    /usr/local/Acrobat[45]/Browsers/intellinux \\
-    /usr/lib/Acrobat[45]/Browsers/intellinux \\
-    /usr/X11R6/lib/Acrobat[45]/Browsers/intellinux \\
-    /opt/Acrobat[45]/Browsers/intellinux \\
-    /usr/Acrobat[45]/Browsers/intellinux \\"
+    %%LOCALBASE%%/lib/linux-flashplugin6 \\
+    %%LOCALBASE%%/lib/linux-flashplugin7 \\
+    %%LOCALBASE%%/Acrobat4/Browsers/intellinux \\
+    %%LOCALBASE%%/Acrobat5/Browsers/intellinux \\"
 
 	    wrapper_ibmjava="
-	    IBMJava2-141/jre \\
-	    IBMJava2-14/jre \\
-	    IBMJava2-131/jre \\"
+	    linux-ibm-jdk1.3.1/jre \\
+	    linux-ibm-jdk1.4.0/jre \\
+	    linux-ibm-jdk1.4.1/jre \\"
 	    wrapper_sunjava_machine="i386"
 	;;
 
@@ -817,17 +813,11 @@
 	;;
     esac
     wrapper_netscape_plugin_paths="
-    /usr/lib/RealPlayer8/Plugins \\
-    /usr/lib/realplay/plugins \\
-    /usr/lib/RealPlayer8 \\
-    /usr/lib/realplay \\
+    %%LOCALBASE%%/lib/RealPlayer8/Plugins \\
     \"\${HOME}/.netscape/plugins\" \\
-    /opt/netscape/plugins \\
-    /usr/lib/netscape/plugins \\
-    /usr/local/netscape/plugins \\
-    /usr/local/lib/netscape/plugins \\"
+    %%LOCALBASE%%/lib/netscape-linux/plugins \\"
 
-    wrapper_file="${wrapper_dir}/opera"
+    wrapper_file="${wrapper_dir}/linux-opera"
     
     wrapper_contain="#!/bin/sh
 
@@ -871,9 +861,13 @@
 OPERA_LD_PRELOAD=\"\${LD_PRELOAD}\"
 export OPERA_LD_PRELOAD
 
+# ~/.linux-opera
+OPERA_PERSONALDIR=\${HOME}/.linux-opera
+export OPERA_PERSONALDIR
+
 # Native Java enviroment
-if test -f \"\${HOME}/.opera/javapath.txt\"; then
-    INIJAVA=\`cat \${HOME}/.opera/javapath.txt\`
+if test -f \"\${HOME}/.linux-opera/javapath.txt\"; then
+    INIJAVA=\`cat \${HOME}/.linux-opera/javapath.txt\`
     if test -f \"\${INIJAVA}/libjava.so\"; then OPERA_JAVA_DIR=\"\${INIJAVA}\"; fi
 fi
 
@@ -887,39 +881,16 @@
 
 if test ! \"\${OPERA_JAVA_DIR}\"; then
 
-    PREFIXES=\"
-	/usr
-	/usr/java
-	/usr/lib
-	/usr/local
-	/opt\"
+    PREFIXES=\"%%LOCALBASE%%\"
 
     for SUNJAVA in \\
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
-	java2re \\
-	jdk1.2.2/jre \\
-	jdk1.2/jre \\
-	jre \\
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
@@ -983,11 +954,8 @@
 
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
@@ -1086,7 +1054,7 @@
     chop "${OPERADESTDIR}" "str_localdirshare"
     chop "${OPERADESTDIR}" "str_localdirplugin"
 
-    backup ${wrapper_dir}/opera opera
+    #backup ${wrapper_dir}/opera opera
 
     # Executable
 	debug_msg 1 "Executable"
@@ -1121,7 +1089,7 @@
 
 	#cp $cpv $cpf wrapper.sh $wrapper_dir/opera
 	generate_wrapper
-        chmod $chmodv 755 $wrapper_dir/opera
+        chmod $chmodv 755 $wrapper_dir/linux-opera
 
     # Documentation
 	debug_msg 1 "Documentation"
@@ -1155,7 +1123,7 @@
 	if test -d ini; then
 	    mkdir $mkdirv $mkdirp $share_dir/ini/
 	    chmod $chmodv 755 $share_dir/ini
-	    cp $cpv $cpf $cpR ini/* $share_dir/ini/
+	    cp $cpv $cpf $cpR ini/*.ini $share_dir/ini/
 	    if test -f $share_dir/ini/pluginpath.ini; then
 		echo ${str_localdirplugin} >> $share_dir/ini/pluginpath.ini
 	    fi
@@ -1255,8 +1223,9 @@
 	if test -z "${OPERADESTDIR}"; then
 
 	# System wide configuration files
-	config_dir="/etc"
+	config_dir="$prefix/etc"
 	if can_write_to "$config_dir"; then
+if false; then # XXX
 	    echo
 	    echo "System wide configuration files:"
 	    echo "  $config_dir/opera6rc"
@@ -1268,6 +1237,7 @@
 		cp $cpv $cpf config/opera6rc $config_dir
 		cp $cpv $cpf config/opera6rc.fixed $config_dir
 	    fi
+fi # XXX
 	else
 	    echo
 	    echo "User \"${USERNAME}\" does not have write access to $config_dir"
@@ -1281,9 +1251,9 @@
 	icons
 	gnome
 	kde 3
-	kde 2
-	kde1
-	mandrake
+#	kde 2
+#	kde1
+#	mandrake
 
 	fi # OPERADESTDIR
 
@@ -1328,13 +1298,13 @@
 {
     # arg1 = location
 
-    desktop_file="${1}/opera.desktop"
+    desktop_file="${1}/linux-opera.desktop"
 
     desktop_contain='[Desktop Entry]
-Name=Opera
+Name=Opera (linux version)
 Comment=Web Browser
-Exec=opera
-Icon=opera.xpm
+Exec=linux-opera
+Icon=linux-opera.xpm
 Terminal=0
 Type=Application'
 
@@ -1367,42 +1337,13 @@
 
     debug_msg 0 "in icons()"
 
-    if test ! -d /usr/share/icons; then
-      if test -w /usr/share; then
-        mkdir $mkdirv $mkdirp /usr/share/icons/
-	chmod $chmodv 755 /usr/share/icons
-	cp $cpv $share_dir/images/opera.xpm /usr/share/icons/opera.xpm
-      fi
-    elif test -w /usr/share/icons; then cp $cpv $share_dir/images/opera.xpm /usr/share/icons/opera.xpm
-    fi
-  
-    if test ! -d /usr/share/pixmaps; then
-      if test -w /usr/share; then
-	mkdir $mkdirv $mkdirp /usr/share/pixmaps/
-	chmod $chmodv 755 /usr/share/pixmaps
-	cp $cpv $share_dir/images/opera.xpm /usr/share/pixmaps/opera.xpm
-      fi
-    elif test -w /usr/share/pixmaps/; then cp $cpv $share_dir/images/opera.xpm /usr/share/pixmaps/opera.xpm
-    fi
-  
-    if test ! -d /etc/X11/wmconfig/; then
-      if test -w /etc/X11; then
-	mkdir $mkdirv $mkdirp /etc/X11/wmconfig/
-	chmod $chmodv 755 /etc/X11/wmconfig
-	generate_wmconfig /etc/X11/wmconfig
-      fi
-    elif test -w /etc/X11/wmconfig/; then generate_wmconfig /etc/X11/wmconfig
-    fi
-    
-    if test -d /etc/X11/applnk/; then
-      if test ! -d /etc/X11/applnk/Internet/; then
-	if test -w /etc/X11/applnk; then
-	  mkdir $mkdirv $mkdirp /etc/X11/applnk/Internet/
-	  chmod $chmodv 755 /etc/X11/applnk/Internet
-	  generate_desktop /etc/X11/applnk/Internet
-	fi
-      elif test -w /etc/X11/applnk/Internet; then generate_desktop /etc/X11/applnk/Internet
+    if test ! -d %%X11BASE%%/share/pixmaps; then
+      if test -w %%X11BASE%%/share; then
+	mkdir $mkdirv $mkdirp %%X11BASE%%/share/pixmaps/
+	chmod $chmodv 755 %%X11BASE%%/share/pixmaps
+	cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/pixmaps/linux-opera.xpm
       fi
+    elif test -w %%X11BASE%%/share/pixmaps/; then cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/pixmaps/linux-opera.xpm
     fi
 }
 
@@ -1412,72 +1353,36 @@
 
     debug_msg 1 "in gnome()"
 
-    if test -d /opt/gnome/; then
+    if test -d %%X11BASE%%/share/gnome/; then
 
-      # /opt/gnome share
-      if test -d /opt/gnome/share; then
-
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
+	    cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/gnome/pixmaps/linux-opera.xpm
 	  fi
-	elif test -w /opt/gnome/share/pixmaps; then cp $cpv $share_dir/images/opera.xpm /opt/gnome/share/pixmaps/opera.xpm
+	elif test -w %%X11BASE%%/share/gnome/pixmaps; then cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/gnome/pixmaps/linux-opera.xpm
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
@@ -1488,39 +1393,31 @@
 
     debug_msg 1 "in kde()"
 
-    if test -d /opt/kde${1}/share; then
+    if test -d %%LOCALBASE%%/share; then
 
-      DIR_HI=/opt/kde${1}/share/icons/hicolor
+      DIR_HI=%%LOCALBASE%%/share/icons/hicolor
       if test -d "$DIR_HI" -a -w "$DIR_HI"; then
-        if test -d "$DIR_HI"/48x48/apps -a -w "$DIR_HI"/48x48/apps; then cp $cpv $share_dir/images/opera_48x48.png $DIR_HI/48x48/apps/opera.png; fi
-        if test -d "$DIR_HI"/32x32/apps -a -w "$DIR_HI"/32x32/apps; then cp $cpv $share_dir/images/opera_32x32.png $DIR_HI/32x32/apps/opera.png; fi
-        if test -d "$DIR_HI"/22x22/apps -a -w "$DIR_HI"/22x22/apps; then cp $cpv $share_dir/images/opera_22x22.png $DIR_HI/22x22/apps/opera.png; fi
+        if test -d "$DIR_HI"/48x48/apps -a -w "$DIR_HI"/48x48/apps; then cp $cpv $share_dir/images/opera_48x48.png $DIR_HI/48x48/apps/linux-opera.png; fi
+        if test -d "$DIR_HI"/32x32/apps -a -w "$DIR_HI"/32x32/apps; then cp $cpv $share_dir/images/opera_32x32.png $DIR_HI/32x32/apps/linux-opera.png; fi
+        if test -d "$DIR_HI"/22x22/apps -a -w "$DIR_HI"/22x22/apps; then cp $cpv $share_dir/images/opera_22x22.png $DIR_HI/22x22/apps/linux-opera.png; fi
       fi
 
-      DIR_LO=/opt/kde${1}/share/icons/locolor
+      DIR_LO=%%LOCALBASE%%/share/icons/locolor
       if test -d $DIR_LO -a -w $DIR_LO; then
-        if test -d $DIR_LO/32x32/apps -a -w $DIR_LO/32x32/apps; then cp $cpv $share_dir/images/opera_32x32.png $DIR_LO/32x32/apps/opera.png; fi
-        if test -d $DIR_LO/22x22/apps -a -w $DIR_LO/22x22/apps; then cp $cpv $share_dir/images/opera_22x22.png $DIR_LO/22x22/apps/opera.png; fi
-        if test -d $DIR_LO/16x16/apps -a -w $DIR_LO/16x16/apps; then cp $cpv $share_dir/images/opera_16x16.png $DIR_LO/16x16/apps/opera.png; fi
+        if test -d $DIR_LO/32x32/apps -a -w $DIR_LO/32x32/apps; then cp $cpv $share_dir/images/opera_32x32.png $DIR_LO/32x32/apps/linux-opera.png; fi
+        if test -d $DIR_LO/22x22/apps -a -w $DIR_LO/22x22/apps; then cp $cpv $share_dir/images/opera_22x22.png $DIR_LO/22x22/apps/linux-opera.png; fi
+        if test -d $DIR_LO/16x16/apps -a -w $DIR_LO/16x16/apps; then cp $cpv $share_dir/images/opera_16x16.png $DIR_LO/16x16/apps/linux-opera.png; fi
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
