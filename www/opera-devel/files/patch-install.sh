--- install.sh.orig	Wed Apr 14 12:49:50 2004
+++ install.sh	Thu Apr 15 12:11:26 2004
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
@@ -758,11 +758,9 @@
 
     debug_msg 0 "in generate_wrapper()"
 
-    wrapper_opera_plugin_paths="    \"\${HOME}/.opera/plugins\" \\
+    wrapper_opera_plugin_paths="    \"\${HOME}/.opera-devel/plugins\" \\
     ${str_localdirplugin} \\
-    /usr/lib/opera/plugins \\
-    /usr/local/lib/opera/plugins \\
-    /opt/lib/opera/plugins \\"
+    /usr/local/share/opera/plugins \\"
 
     case "${machine}:${os}" in
 	i[3456]86:Linux|i[3456]86:FreeBSD|i[3456]86:NetBSD|i[3456]86:OpenBSD)
@@ -817,17 +815,12 @@
 	;;
     esac
     wrapper_netscape_plugin_paths="
-    /usr/lib/RealPlayer8/Plugins \\
-    /usr/lib/realplay/plugins \\
-    /usr/lib/RealPlayer8 \\
-    /usr/lib/realplay \\
+    /usr/local/lib/RealPlayer8/Plugins \\
+    /usr/X11R6/lib/browser_plugins \\
     \"\${HOME}/.netscape/plugins\" \\
-    /opt/netscape/plugins \\
-    /usr/lib/netscape/plugins \\
-    /usr/local/netscape/plugins \\
-    /usr/local/lib/netscape/plugins \\"
+    /usr/local/lib/netscape-linux/plugins \\"
 
-    wrapper_file="${wrapper_dir}/opera"
+    wrapper_file="${wrapper_dir}/opera-devel"
     
     wrapper_contain="#!/bin/sh
 
@@ -871,9 +864,12 @@
 OPERA_LD_PRELOAD=\"\${LD_PRELOAD}\"
 export OPERA_LD_PRELOAD
 
+OPERA_PERSONALDIR=\${HOME}/.opera-devel
+export OPERA_PERSONALDIR
+
 # Native Java enviroment
-if test -f \"\${HOME}/.opera/javapath.txt\"; then
-    INIJAVA=\`cat \${HOME}/.opera/javapath.txt\`
+if test -f \"\${HOME}/.opera-devel/javapath.txt\"; then
+    INIJAVA=\`cat \${HOME}/.opera-devel/javapath.txt\`
     if test -f \"\${INIJAVA}/libjava.so\"; then OPERA_JAVA_DIR=\"\${INIJAVA}\"; fi
 fi
 
@@ -983,11 +979,8 @@
 
 # Acrobat Reader
 for BINDIR in \\
-    /usr/local/Acrobat[45]/bin \\
-    /usr/lib/Acrobat[45]/bin \\
-    /usr/X11R6/lib/Acrobat[45]/bin \\
-    /opt/Acrobat[45]/bin \\
-    /usr/Acrobat[45]/bin \\
+    /usr/local/Acrobat4/bin \\
+    /usr/local/Acrobat5/bin \\
     ; do
     if test -d \${BINDIR} ; then PATH=\${PATH}:\${BINDIR}; fi
 done
@@ -1086,7 +1079,7 @@
     chop "${OPERADESTDIR}" "str_localdirshare"
     chop "${OPERADESTDIR}" "str_localdirplugin"
 
-    backup ${wrapper_dir}/opera opera
+    #backup ${wrapper_dir}/opera opera
 
     # Executable
 	debug_msg 1 "Executable"
@@ -1121,7 +1114,7 @@
 
 	#cp $cpv $cpf wrapper.sh $wrapper_dir/opera
 	generate_wrapper
-        chmod $chmodv 755 $wrapper_dir/opera
+        chmod $chmodv 755 $wrapper_file
 
     # Documentation
 	debug_msg 1 "Documentation"
@@ -1254,31 +1247,8 @@
 
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
 	kde 2
@@ -1311,13 +1281,13 @@
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
@@ -1328,12 +1298,12 @@
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
@@ -1367,22 +1337,22 @@
 
     debug_msg 0 "in icons()"
 
-    if test ! -d /usr/share/icons; then
-      if test -w /usr/share; then
-        mkdir $mkdirv $mkdirp /usr/share/icons/
-	chmod $chmodv 755 /usr/share/icons
-	cp $cpv $share_dir/images/opera.xpm /usr/share/icons/opera.xpm
+    if test ! -d /usr/X11R6/share/icons; then
+      if test -w /usr/X11R6/share; then
+        mkdir $mkdirv $mkdirp /usr/X11R6/share/icons/
+	chmod $chmodv 755 /usr/X11R6/share/icons
+	cp $cpv $share_dir/images/opera.xpm /usr/X11R6/share/icons/opera.xpm
       fi
-    elif test -w /usr/share/icons; then cp $cpv $share_dir/images/opera.xpm /usr/share/icons/opera.xpm
+    elif test -w /usr/X11R6/share/icons; then cp $cpv $share_dir/images/opera.xpm /usr/X11R6/share/icons/opera.xpm
     fi
   
-    if test ! -d /usr/share/pixmaps; then
-      if test -w /usr/share; then
-	mkdir $mkdirv $mkdirp /usr/share/pixmaps/
-	chmod $chmodv 755 /usr/share/pixmaps
-	cp $cpv $share_dir/images/opera.xpm /usr/share/pixmaps/opera.xpm
+    if test ! -d /usr/X11R6/share/pixmaps; then
+      if test -w /usr/X11R6/share; then
+	mkdir $mkdirv $mkdirp /usr/X11R6/share/pixmaps/
+	chmod $chmodv 755 /usr/X11R6/share/pixmaps
+	cp $cpv $share_dir/images/opera.xpm /usr/X11R6/share/pixmaps/opera.xpm
       fi
-    elif test -w /usr/share/pixmaps/; then cp $cpv $share_dir/images/opera.xpm /usr/share/pixmaps/opera.xpm
+    elif test -w /usr/X11R6/share/pixmaps/; then cp $cpv $share_dir/images/opera.xpm /usr/X11R6/share/pixmaps/opera.xpm
     fi
   
     if test ! -d /etc/X11/wmconfig/; then
@@ -1448,33 +1418,33 @@
       fi
       # end /opt/gnome share
 
-    elif test -d /usr/share/gnome/; then
+    elif test -d /usr/X11R6/share/gnome/; then
 
-        # /usr/share/gnome icon
-        if test ! -d /usr/share/gnome/pixmaps/; then
-	  if test -w /usr/share/gnome; then
-	    mkdir $mkdirv $mkdirp /usr/share/gnome/pixmaps/
-	    chmod $chmodv 755 /usr/share/gnome/pixmaps
-	    cp $cpv $share_dir/images/opera.xpm /usr/share/gnome/pixmaps/opera.xpm
+        # /usr/X11R6/share/gnome icon
+        if test ! -d /usr/X11R6/share/gnome/pixmaps/; then
+	  if test -w /usr/X11R6/share/gnome; then
+	    mkdir $mkdirv $mkdirp /usr/X11R6/share/gnome/pixmaps/
+	    chmod $chmodv 755 /usr/X11R6/share/gnome/pixmaps
+	    cp $cpv $share_dir/images/opera.xpm /usr/X11R6/share/gnome/pixmaps/opera.xpm
 	  fi
-	elif test -w /usr/share/gnome/pixmaps; then cp $cpv $share_dir/images/opera.xpm /usr/share/gnome/pixmaps/opera.xpm
+	elif test -w /usr/X11R6/share/gnome/pixmaps; then cp $cpv $share_dir/images/opera.xpm /usr/X11R6/share/gnome/pixmaps/opera.xpm
 	fi
-	# end /usr/share/gnome icon
+	# end /usr/X11R6/share/gnome icon
 
-	# /usr/share/gnome link
-	if test -d /usr/share/gnome/apps/; then
-          if test -d /usr/share/gnome/apps/Internet/; then
-            if test -w /usr/share/gnome/apps/Internet; then
-              generate_desktop /usr/share/gnome/apps/Internet
+	# /usr/X11R6/share/gnome link
+	if test -d /usr/X11R6/share/gnome/apps/; then
+          if test -d /usr/X11R6/share/gnome/apps/Internet/; then
+            if test -w /usr/X11R6/share/gnome/apps/Internet; then
+              generate_desktop /usr/X11R6/share/gnome/apps/Internet
 	    fi
-          elif test -d /usr/share/gnome/apps/Networking/WWW/; then
-            if test -w /usr/share/gnome/apps/Networking/WWW; then
-	     generate_desktop /usr/share/gnome/apps/Networking/WWW
+          elif test -d /usr/X11R6/share/gnome/apps/Networking/WWW/; then
+            if test -w /usr/X11R6/share/gnome/apps/Networking/WWW; then
+	     generate_desktop /usr/X11R6/share/gnome/apps/Networking/WWW
 	    fi
-	  elif test -w /usr/share/gnome/apps; then
-	    mkdir $mkdirv $mkdirp /usr/share/gnome/apps/Internet/
-	    chmod $chmodv 755 /usr/share/gnome/apps/Internet
-            generate_desktop /usr/share/gnome/apps/Internet
+	  elif test -w /usr/X11R6/share/gnome/apps; then
+	    mkdir $mkdirv $mkdirp /usr/X11R6/share/gnome/apps/Internet/
+	    chmod $chmodv 755 /usr/X11R6/share/gnome/apps/Internet
+            generate_desktop /usr/X11R6/share/gnome/apps/Internet
           fi
 	fi
 	# end /usr/share/gnome link
@@ -1514,12 +1484,12 @@
 
     fi  
     
-    if test -d /usr/share/applnk/Networking; then
-      if test ! -d /usr/share/applnk/Networking/WWW/ -a -w /usr/share/applnk/Networking; then
-	    mkdir $mkdirv $mkdirp /usr/share/applnk/Networking/WWW/
-	    chmod $chmodv 755 /usr/share/applnk/Networking/WWW
+    if test -d /usr/X11R6/share/applnk/Networking; then
+      if test ! -d /usr/X11R6/share/applnk/Networking/WWW/ -a -w /usr/X11R6/share/applnk/Networking; then
+	    mkdir $mkdirv $mkdirp /usr/X11R6/share/applnk/Networking/WWW/
+	    chmod $chmodv 755 /usr/X11R6/share/applnk/Networking/WWW
       fi
-      if test -w /usr/share/applnk/Networking/WWW; then generate_desktop /usr/share/applnk/Networking/WWW ${1}; fi
+      if test -w /usr/X11R6/share/applnk/Networking/WWW; then generate_desktop /usr/X11R6/share/applnk/Networking/WWW ${1}; fi
     fi
 }
 
@@ -1543,8 +1513,8 @@
       fi
       if test -w /opt/kde/share/applnk/Internet; then generate_desktop /opt/kde/share/applnk/Internet; fi
 
-    elif test -d /usr/share/applnk/Internet/ -a -w /usr/share/applnk/Internet; then
-      generate_desktop /usr/share/applnk/Internet
+    elif test -d /usr/X11R6/share/applnk/Internet/ -a -w /usr/X11R6/share/applnk/Internet; then
+      generate_desktop /usr/X11R6/share/applnk/Internet
     fi
 }
 
