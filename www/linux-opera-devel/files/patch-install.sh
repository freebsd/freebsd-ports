--- install.sh.orig	Fri Dec 10 06:49:32 2004
+++ install.sh	Tue Dec 14 17:26:29 2004
@@ -761,10 +761,9 @@
     case "${machine}:${os}" in
 	i[3456]86:Linux|x86_64:Linux|i[3456]86:FreeBSD|i[3456]86:NetBSD|i[3456]86:OpenBSD)
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
 
@@ -794,7 +793,7 @@
 		error 'os'
 	;;
     esac
-    wrapper_file="${wrapper_dir}/opera"
+    wrapper_file="${wrapper_dir}/linux-opera"
     
     wrapper_contain="#!/bin/sh
 
@@ -850,6 +849,10 @@
 OPERA_LD_PRELOAD=\"\${LD_PRELOAD}\"
 export OPERA_LD_PRELOAD
 
+# ~/.linux-opera
+OPERA_PERSONALDIR=\${HOME}/.linux-opera
+export OPERA_PERSONALDIR
+
 # Native Java enviroment
 if test -f \"\${OPERA_PERSONALDIR}/javapath.txt\"; then
     INIJAVA=\`cat \${OPERA_PERSONALDIR}/javapath.txt\`
@@ -857,8 +860,8 @@
 fi
 
 if test ! \"\${OPERA_JAVA_DIR}\"; then
-    if test -f \"\${HOME}/.opera/javapath.txt\"; then
-        INIJAVA=\`cat \${HOME}/.opera/javapath.txt\`
+    if test -f \"\${OPERA_PERSONALDIR}/javapath.txt\"; then
+        INIJAVA=\`cat \${OPERA_PERSONALDIR}/javapath.txt\`
         if test -f \"\${INIJAVA}/libjava.so\"; then OPERA_JAVA_DIR=\"\${INIJAVA}\"; fi
     fi
 fi
@@ -873,47 +876,16 @@
 
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
@@ -962,11 +934,8 @@
 
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
@@ -1004,7 +973,7 @@
 };
 
 // Opera package classes get all permissions
-grant codebase \"file://${str_localdirshare}/java//opera.jar\" {
+grant codebase \"file://${str_localdirshare}/java/opera.jar\" {
 	permission java.security.AllPermission;
 };
 
@@ -1076,7 +1045,7 @@
     chop "${OPERADESTDIR}" "str_localdirshare"
     chop "${OPERADESTDIR}" "str_localdirplugin"
 
-    backup ${wrapper_dir}/opera opera
+    #backup ${wrapper_dir}/opera opera
 
     # Executable
 	debug_msg 1 "Executable"
@@ -1111,7 +1080,7 @@
 
 	#cp $cpv $cpf wrapper.sh $wrapper_dir/opera
 	generate_wrapper
-        chmod $chmodv 755 $wrapper_dir/opera
+        chmod $chmodv 755 $wrapper_dir/linux-opera
 
     # Documentation
 	debug_msg 1 "Documentation"
@@ -1210,27 +1179,6 @@
 	mkdir $mkdirv $mkdirp $plugin_dir/
 	chmod $chmodv 755 $plugin_dir
 
-	if test -f plugins/operamotifwrapper
-	    then
-		cp $cpv $cpf plugins/operamotifwrapper $plugin_dir/
-		chmod $chmodv 755 $plugin_dir/operamotifwrapper
-		plugin_support='yes'
-	fi
-
-	if test -f plugins/operamotifwrapper-1
-	    then
-		cp $cpv $cpf plugins/operamotifwrapper-1 $plugin_dir/
-		chmod $chmodv 755 $plugin_dir/operamotifwrapper-1
-		plugin_support='yes'
-	fi
-
-	if test -f plugins/operamotifwrapper-2
-	    then
-		cp $cpv $cpf plugins/operamotifwrapper-2 $plugin_dir/
-		chmod $chmodv 755 $plugin_dir/operamotifwrapper-2
-		plugin_support='yes'
-	fi
-
 	if test -f plugins/operamotifwrapper-3
 	    then
 		cp $cpv $cpf plugins/operamotifwrapper-3 $plugin_dir/
@@ -1238,13 +1186,6 @@
 		plugin_support='yes'
 	fi
 
-	if test -f plugins/operamotifwrapper-4
-	    then
-		cp $cpv $cpf plugins/operamotifwrapper-4 $plugin_dir/
-		chmod $chmodv 755 $plugin_dir/operamotifwrapper-4
-		plugin_support='yes'
-	fi
-
 	if test -f plugins/libnpp.so
 	    then
 		cp $cpv $cpf plugins/libnpp.so $plugin_dir/
@@ -1282,8 +1223,9 @@
 	if test -z "${OPERADESTDIR}"; then
 
 	# System wide configuration files
-	config_dir="/etc"
+	config_dir="$prefix/etc"
 	if can_write_to "$config_dir"; then
+if false; then # XXX
 	    echo
 	    echo "System wide configuration files:"
 	    echo "  $config_dir/opera6rc"
@@ -1295,6 +1237,7 @@
 		cp $cpv $cpf config/opera6rc $config_dir
 		cp $cpv $cpf config/opera6rc.fixed $config_dir
 	    fi
+fi # XXX
 	else
 	    echo
 	    echo "User \"${USERNAME}\" does not have write access to $config_dir"
@@ -1305,12 +1248,12 @@
 	fi
 
      # Shorcuts and Icons
-	icons
+#	icons
 	gnome
 	kde 3
-	kde 2
-	kde1
-	mandrake
+#	kde 2
+#	kde1
+#	mandrake
 
 	fi # OPERADESTDIR
 
@@ -1355,13 +1298,13 @@
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
 
@@ -1439,74 +1382,39 @@
 
     debug_msg 1 "in gnome()"
 
-    if test -d /opt/gnome/; then
+    if test -d %%X11BASE%%/share/gnome/; then
 
-      # /opt/gnome share
-      if test -d /opt/gnome/share; then
+      # %%X11BASE%%/share/gnome icon
+      if test ! -d %%X11BASE%%/share/gnome/pixmaps/; then
+        if test -w %%X11BASE%%/share/gnome; then
+          mkdir $mkdirv $mkdirp %%X11BASE%%/share/gnome/pixmaps/
+          chmod $chmodv 755 %%X11BASE%%/share/gnome/pixmaps
+          cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/gnome/pixmaps/linux-opera.xpm
+        fi
+      elif test -w %%X11BASE%%/share/gnome/pixmaps; then
+        cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/gnome/pixmaps/linux-opera.xpm
+      fi
+      # end %%X11BASE%%/share/gnome icon
 
-        # /opt/gnome icon
-        if test ! -d /opt/gnome/share/pixmaps/; then
-	  if test -w /opt/gnome/share; then
-	    mkdir $mkdirv $mkdirp /opt/gnome/share/pixmaps/
-	    chmod $chmodv 755 /opt/gnome/share/pixmaps
-	    cp $cpv $share_dir/images/opera.xpm /opt/gnome/share/pixmaps/opera.xpm
-	  fi
-	elif test -w /opt/gnome/share/pixmaps; then cp $cpv $share_dir/images/opera.xpm /opt/gnome/share/pixmaps/opera.xpm
-	fi
-	# end /opt/gnome icon
-
-	# /opt/gnome link
-	if test -d /opt/gnome/share/gnome/apps/; then
-          if test -d /opt/gnome/share/gnome/apps/Internet/; then
-            if test -w /opt/gnome/share/gnome/apps/Internet; then
-              generate_desktop /opt/gnome/share/gnome/apps/Internet
-	    fi
-          elif test -d /opt/gnome/share/gnome/apps/Networking/WWW/; then
-            if test -w /opt/gnome/share/gnome/apps/Networking/WWW; then
-	      generate_desktop /opt/gnome/share/gnome/apps/Networking/WWW
-	    fi
-	  elif test -w /opt/gnome/share/gnome/apps; then
-	    mkdir $mkdirv $mkdirp /opt/gnome/share/gnome/apps/Internet/
-	    chmod $chmodv 755 /opt/gnome/share/gnome/apps/Internet
-            generate_desktop /opt/gnome/share/gnome/apps/Internet
+      # %%X11BASE%%/share/gnome link
+      if test -d %%X11BASE%%/share/gnome/apps/; then
+        if test -d %%X11BASE%%/share/gnome/apps/Internet/; then
+          if test -w %%X11BASE%%/share/gnome/apps/Internet; then
+            generate_desktop %%X11BASE%%/share/gnome/apps/Internet
           fi
-	fi
-	# end /opt/gnome link
+        elif test -d %%X11BASE%%/share/gnome/apps/Networking/WWW/; then
+          if test -w %%X11BASE%%/share/gnome/apps/Networking/WWW; then
+            generate_desktop %%X11BASE%%/share/gnome/apps/Networking/WWW
+          fi
+        elif test -w %%X11BASE%%/share/gnome/apps; then
+          mkdir $mkdirv $mkdirp %%X11BASE%%/share/gnome/apps/Internet/
+          chmod $chmodv 755 %%X11BASE%%/share/gnome/apps/Internet
+          generate_desktop %%X11BASE%%/share/gnome/apps/Internet
+        fi
       fi
-      # end /opt/gnome share
+      # end %%X11BASE%%/share/gnome link
 
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
-   fi
-   # Add ximian here
+    fi
 }
 
 kde()
@@ -1515,39 +1423,31 @@
 
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
