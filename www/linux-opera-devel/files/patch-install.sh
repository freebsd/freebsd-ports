--- install.sh.orig	Mon Oct 13 17:19:39 2003
+++ install.sh	Mon Oct 13 17:26:37 2003
@@ -180,7 +180,7 @@
     echo '      --help=long              show advanced functions'
     echo
     echo 'If you choose to do a standard locations install, files will be put into'
-    echo '/usr/bin, /usr/share/doc/opera and /usr/share/opera.'
+    echo '/usr/bin, %%PREFIX%%/share/doc/opera and %%PREFIX%%/share/opera.'
     echo
     echo 'However, if you choose to install to user defined locations, you must either'
     echo '  specify one directory (all files will be put in this directory), or'
@@ -760,23 +760,18 @@
 
     wrapper_opera_plugin_paths="    \"\${HOME}/.opera/plugins\" \\
     ${str_localdirplugin} \\
-    /usr/lib/opera/plugins \\
-    /usr/local/lib/opera/plugins \\
-    /opt/lib/opera/plugins \\"
+    %%LOCALBASE%%/share/opera/plugins \\"
 
     case "${machine}:${os}" in
 	i[3456]86:Linux|i[3456]86:FreeBSD|i[3456]86:NetBSD|i[3456]86:OpenBSD)
 	    wrapper_plugin_paths="
-    /usr/local/Acrobat[45]/Browsers/intellinux \\
-    /usr/lib/Acrobat[45]/Browsers/intellinux \\
-    /usr/X11R6/lib/Acrobat[45]/Browsers/intellinux \\
-    /opt/Acrobat[45]/Browsers/intellinux \\
-    /usr/Acrobat[45]/Browsers/intellinux \\"
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
 
@@ -817,15 +812,9 @@
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
 
     wrapper_file="${wrapper_dir}/opera"
     
@@ -887,39 +876,14 @@
 
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
+	linux-sun-jdk1.3.1/jre \\
+	linux-sun-jdk1.4.1/jre \\
+	linux-sun-jdk1.4.2/jre \\
 	; do
 	for PREFIX in \${PREFIXES}; do
 	    if test -f \"\${PREFIX}/\${SUNJAVA}/lib/${wrapper_sunjava_machine}/libjava.so\"; then OPERA_JAVA_DIR=\"\${PREFIX}/\${SUNJAVA}/lib/${wrapper_sunjava_machine}\" && break; fi
@@ -983,11 +947,8 @@
 
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
@@ -1246,8 +1207,9 @@
 	if test -z "${OPERADESTDIR}"; then
 
 	# System wide configuration files
-	config_dir="/etc"
+	config_dir="$prefix/etc"
 	if can_write_to "$config_dir"; then
+if false; then # XXX
 	    echo
 	    echo "System wide configuration files:"
 	    echo "  $config_dir/opera6rc"
@@ -1259,6 +1221,7 @@
 		cp $cpv $cpf config/opera6rc $config_dir
 		cp $cpv $cpf config/opera6rc.fixed $config_dir
 	    fi
+fi # XXX
 	else
 	    echo
 	    echo "User \"${USERNAME}\" does not have write access to $config_dir"
@@ -1358,22 +1321,22 @@
 
     debug_msg 0 "in icons()"
 
-    if test ! -d /usr/share/icons; then
-      if test -w /usr/share; then
-        mkdir $mkdirv $mkdirp /usr/share/icons/
-	chmod $chmodv 755 /usr/share/icons
-	cp $cpv $share_dir/images/opera.xpm /usr/share/icons/opera.xpm
+    if test ! -d %%X11BASE%%/share/icons; then
+      if test -w %%X11BASE%%/share; then
+        mkdir $mkdirv $mkdirp %%X11BASE%%/share/icons/
+	chmod $chmodv 755 %%X11BASE%%/share/icons
+	cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/icons/opera.xpm
       fi
-    elif test -w /usr/share/icons; then cp $cpv $share_dir/images/opera.xpm /usr/share/icons/opera.xpm
+    elif test -w %%X11BASE%%/share/icons; then cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/icons/opera.xpm
     fi
   
-    if test ! -d /usr/share/pixmaps; then
-      if test -w /usr/share; then
-	mkdir $mkdirv $mkdirp /usr/share/pixmaps/
-	chmod $chmodv 755 /usr/share/pixmaps
-	cp $cpv $share_dir/images/opera.xpm /usr/share/pixmaps/opera.xpm
+    if test ! -d %%X11BASE%%/share/pixmaps; then
+      if test -w %%X11BASE%%/share; then
+	mkdir $mkdirv $mkdirp %%X11BASE%%/share/pixmaps/
+	chmod $chmodv 755 %%X11BASE%%/share/pixmaps
+	cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/pixmaps/opera.xpm
       fi
-    elif test -w /usr/share/pixmaps/; then cp $cpv $share_dir/images/opera.xpm /usr/share/pixmaps/opera.xpm
+    elif test -w %%X11BASE%%/share/pixmaps/; then cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/pixmaps/opera.xpm
     fi
   
     if test ! -d /etc/X11/wmconfig/; then
@@ -1439,36 +1402,36 @@
       fi
       # end /opt/gnome share
 
-    elif test -d /usr/share/gnome/; then
+    elif test -d %%X11BASE%%/share/gnome/; then
 
-        # /usr/share/gnome icon
-        if test ! -d /usr/share/gnome/pixmaps/; then
-	  if test -w /usr/share/gnome; then
-	    mkdir $mkdirv $mkdirp /usr/share/gnome/pixmaps/
-	    chmod $chmodv 755 /usr/share/gnome/pixmaps
-	    cp $cpv $share_dir/images/opera.xpm /usr/share/gnome/pixmaps/opera.xpm
+        # %%X11BASE%%/share/gnome icon
+        if test ! -d %%X11BASE%%/share/gnome/pixmaps/; then
+	  if test -w %%X11BASE%%/share/gnome; then
+	    mkdir $mkdirv $mkdirp %%X11BASE%%/share/gnome/pixmaps/
+	    chmod $chmodv 755 %%X11BASE%%/share/gnome/pixmaps
+	    cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/gnome/pixmaps/opera.xpm
 	  fi
-	elif test -w /usr/share/gnome/pixmaps; then cp $cpv $share_dir/images/opera.xpm /usr/share/gnome/pixmaps/opera.xpm
+	elif test -w %%X11BASE%%/share/gnome/pixmaps; then cp $cpv $share_dir/images/opera.xpm %%X11BASE%%/share/gnome/pixmaps/opera.xpm
 	fi
-	# end /usr/share/gnome icon
+	# end %%X11BASE%%/share/gnome icon
 
-	# /usr/share/gnome link
-	if test -d /usr/share/gnome/apps/; then
-          if test -d /usr/share/gnome/apps/Internet/; then
-            if test -w /usr/share/gnome/apps/Internet; then
-              generate_desktop /usr/share/gnome/apps/Internet
+	# %%X11BASE%%/share/gnome link
+	if test -d %%X11BASE%%/share/gnome/apps/; then
+          if test -d %%X11BASE%%/share/gnome/apps/Internet/; then
+            if test -w %%X11BASE%%/share/gnome/apps/Internet; then
+              generate_desktop %%X11BASE%%/share/gnome/apps/Internet
 	    fi
-          elif test -d /usr/share/gnome/apps/Networking/WWW/; then
-            if test -w /usr/share/gnome/apps/Networking/WWW; then
-	     generate_desktop /usr/share/gnome/apps/Networking/WWW
+          elif test -d %%X11BASE%%/share/gnome/apps/Networking/WWW/; then
+            if test -w %%X11BASE%%/share/gnome/apps/Networking/WWW; then
+	     generate_desktop %%X11BASE%%/share/gnome/apps/Networking/WWW
 	    fi
-	  elif test -w /usr/share/gnome/apps; then
-	    mkdir $mkdirv $mkdirp /usr/share/gnome/apps/Internet/
-	    chmod $chmodv 755 /usr/share/gnome/apps/Internet
-            generate_desktop /usr/share/gnome/apps/Internet
+	  elif test -w %%X11BASE%%/share/gnome/apps; then
+	    mkdir $mkdirv $mkdirp %%X11BASE%%/share/gnome/apps/Internet/
+	    chmod $chmodv 755 %%X11BASE%%/share/gnome/apps/Internet
+            generate_desktop %%X11BASE%%/share/gnome/apps/Internet
           fi
 	fi
-	# end /usr/share/gnome link
+	# end %%X11BASE%%/share/gnome link
    fi
    # Add ximian here
 }
@@ -1505,12 +1468,12 @@
 
     fi  
     
-    if test -d /usr/share/applnk/Networking; then
-      if test ! -d /usr/share/applnk/Networking/WWW/ -a -w /usr/share/applnk/Networking; then
-	    mkdir $mkdirv $mkdirp /usr/share/applnk/Networking/WWW/
-	    chmod $chmodv 755 /usr/share/applnk/Networking/WWW
+    if test -d %%LOCALBASE%%/share/applnk/Networking; then
+      if test ! -d %%LOCALBASE%%/share/applnk/Networking/WWW/ -a -w %%LOCALBASE%%/share/applnk/Networking; then
+	    mkdir $mkdirv $mkdirp %%LOCALBASE%%/share/applnk/Networking/WWW/
+	    chmod $chmodv 755 %%LOCALBASE%%/share/applnk/Networking/WWW
       fi
-      if test -w /usr/share/applnk/Networking/WWW; then generate_desktop /usr/share/applnk/Networking/WWW ${1}; fi
+      if test -w %%LOCALBASE%%/share/applnk/Networking/WWW; then generate_desktop %%LOCALBASE%%/share/applnk/Networking/WWW ${1}; fi
     fi
 }
 
@@ -1534,8 +1497,8 @@
       fi
       if test -w /opt/kde/share/applnk/Internet; then generate_desktop /opt/kde/share/applnk/Internet; fi
 
-    elif test -d /usr/share/applnk/Internet/ -a -w /usr/share/applnk/Internet; then
-      generate_desktop /usr/share/applnk/Internet
+    elif test -d %%LOCALBASE%%/share/applnk/Internet/ -a -w %%LOCALBASE%%/share/applnk/Internet; then
+      generate_desktop %%LOCALBASE%%/share/applnk/Internet
     fi
 }
 
@@ -1546,14 +1509,14 @@
 	test ! -d /usr/lib/menu && test -w /usr/lib && mkdir $mkdirv $mkdirp /usr/lib/menu/
 	test -d /usr/lib/menu && generate_mdk_menu /usr/lib/menu
 
-	test ! -d /usr/share/icons && test -w /usr/share && mkdir $mkdirv $mkdirp /usr/share/icons/ && chmod $chmodv 755 /usr/share/icons
-	test -d /usr/share/icons && cp $cpv $share_dir/images/opera_32x32.png /usr/share/icons/opera.png
+	test ! -d %%X11BASE%%/share/icons && test -w %%X11BASE%%/share && mkdir $mkdirv $mkdirp %%X11BASE%%/share/icons/ && chmod $chmodv 755 %%X11BASE%%/share/icons
+	test -d %%X11BASE%%/share/icons && cp $cpv $share_dir/images/opera_32x32.png %%X11BASE%%/share/icons/opera.png
 
-	test ! -d /usr/share/icons/mini && test -w /usr/share/icons && mkdir $mkdirv $mkdirp /usr/share/icons/mini/ && chmod $chmodv 755 /usr/share/icons/mini
-	test -d /usr/share/icons/mini && cp $cpv $share_dir/images/opera_16x16.png /usr/share/icons/mini/opera.png
+	test ! -d %%X11BASE%%/share/icons/mini && test -w %%X11BASE%%/share/icons && mkdir $mkdirv $mkdirp %%X11BASE%%/share/icons/mini/ && chmod $chmodv 755 %%X11BASE%%/share/icons/mini
+	test -d %%X11BASE%%/share/icons/mini && cp $cpv $share_dir/images/opera_16x16.png %%X11BASE%%/share/icons/mini/opera.png
 
-	test ! -d /usr/share/icons/large && test -w /usr/share/icons && mkdir $mkdirv $mkdirp /usr/share/icons/large && chmod $chmodv 755 /usr/share/icons/large
-	test -d /usr/share/icons/large && cp $cpv $share_dir/images/opera_48x48.png /usr/share/icons/large/opera.png
+	test ! -d %%X11BASE%%/share/icons/large && test -w %%X11BASE%%/share/icons && mkdir $mkdirv $mkdirp %%X11BASE%%/share/icons/large && chmod $chmodv 755 %%X11BASE%%/share/icons/large
+	test -d %%X11BASE%%/share/icons/large && cp $cpv $share_dir/images/opera_48x48.png %%X11BASE%%/share/icons/large/opera.png
 
 	/usr/bin/update-menus || true
     fi
