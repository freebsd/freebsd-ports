--- install.sh.orig	Thu May 15 11:36:54 2003
+++ install.sh	Tue May 20 18:11:25 2003
@@ -712,27 +712,17 @@
 
     wrapper_opera_plugin_paths="    \"\${HOME}/.opera/plugins\" \\
     ${plugin_dir} \\
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
-    /usr/Acrobat[45]/Browsers/intellinux \\
-    /usr/j2se/jre/plugin/i386/ns4 \\
-    /usr/java/jre1.4.0/plugin/i386/ns4 \\
-    /usr/java/jre1.3.1/plugin/i386/ns4 \\
-    /usr/lib/j2re1.3/plugin/i386/netscape4 \\
-    /usr/local/jdk1.3.1/jre/plugin/i386/ns4 \\
-    /usr/local/linux-jdk1.3.1/jre/plugin/i386/ns4 \\"
+    %%LOCALBASE%%/Acrobat[45]/Browsers/intellinux \\
+    %%LOCALBASE%%/linux-sun-jdk1.[34].1/jre/plugin/i386/ns4 \\
+    %%LOCALBASE%%/linux-blackdown-jdk1.[34].1/jre/plugin/i386/netscape4 \\"
 	    wrapper_ibmjava="
-	    IBMJava2-14/jre \\
-	    IBMJava2-131/jre \\"
+	    linux-ibm-jdk1.3.1/jre \\
+	    linux-ibm-jdk1.4.0/jre \\"
 	    wrapper_sunjava_machine="i386"
 	;;
 
@@ -779,15 +769,9 @@
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
     
@@ -839,28 +823,13 @@
 
 if test ! \"\${OPERA_JAVA_DIR}\"; then
 
-    PREFIXES=\"
-	/usr
-	/usr/java
-	/usr/lib
-	/usr/local
-	/opt\"
+    PREFIXES=\"%%LOCALBASE%%\"
 
     for SUNJAVA in \\
-	j2re1.4.1_01 \\
-	j2re1.4.1 \\
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
+	linux-blackdown-jdk1.3.1/jre \\
+	linux-blackdown-jdk1.4.1/jre \\
+	linux-sun-jdk1.3.1/jre \\
+	linux-sun-jdk1.4.1/jre \\
 	; do
 	for PREFIX in \${PREFIXES}; do
 	    if test -f \"\${PREFIX}/\${SUNJAVA}/lib/${wrapper_sunjava_machine}/libjava.so\"; then OPERA_JAVA_DIR=\"\${PREFIX}/\${SUNJAVA}/lib/${wrapper_sunjava_machine}\" && break; fi
@@ -905,11 +874,8 @@
 
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
@@ -1106,8 +1072,9 @@
         chmod $chmodv 755 $plugin_dir/operamotifwrapper $plugin_dir/operaplugincleaner $plugin_dir/libnpp.so
 
      # System wide configuration files
-	config_dir="/etc"
+	config_dir="$prefix/etc"
 	if can_write_to "$config_dir"; then
+if false; then # XXX
 	    echo
 	    echo "System wide configuration files:"
 	    echo "  $config_dir/opera6rc"
@@ -1134,6 +1101,7 @@
 			;;
 		esac
 	    done
+fi # XXX
 	else
 	    echo
 	    echo "User \"${USERNAME}\" does not have write access to $config_dir"
@@ -1238,22 +1206,22 @@
 
     debug_msg 0 "in icons()"
 
-    if test ! -d /usr/share/icons; then
-      if test -w /usr/share; then
-        mkdir $mkdirv $mkdirp /usr/share/icons/
-	chmod $chmodv 755 /usr/share/icons
-	cp $cpv $share_dir/images/opera.xpm /usr/share/icons/opera.xpm
+    if test ! -d %%X11PREFIX%%/share/icons; then
+      if test -w %%X11PREFIX%%/share; then
+        mkdir $mkdirv $mkdirp %%X11PREFIX%%/share/icons/
+	chmod $chmodv 755 %%X11PREFIX%%/share/icons
+	cp $cpv $share_dir/images/opera.xpm %%X11PREFIX%%/share/icons/opera.xpm
       fi
-    elif test -w /usr/share/icons; then cp $cpv $share_dir/images/opera.xpm /usr/share/icons/opera.xpm
+    elif test -w %%X11PREFIX%%/share/icons; then cp $cpv $share_dir/images/opera.xpm %%X11PREFIX%%/share/icons/opera.xpm
     fi
   
-    if test ! -d /usr/share/pixmaps; then
-      if test -w /usr/share; then
-	mkdir $mkdirv $mkdirp /usr/share/pixmaps/
-	chmod $chmodv 755 /usr/share/pixmaps
-	cp $cpv $share_dir/images/opera.xpm /usr/share/pixmaps/opera.xpm
+    if test ! -d %%X11PREFIX%%/share/pixmaps; then
+      if test -w %%X11PREFIX%%/share; then
+	mkdir $mkdirv $mkdirp %%X11PREFIX%%/share/pixmaps/
+	chmod $chmodv 755 %%X11PREFIX%%/share/pixmaps
+	cp $cpv $share_dir/images/opera.xpm %%X11PREFIX%%/share/pixmaps/opera.xpm
       fi
-    elif test -w /usr/share/pixmaps/; then cp $cpv $share_dir/images/opera.xpm /usr/share/pixmaps/opera.xpm
+    elif test -w %%X11PREFIX%%/share/pixmaps/; then cp $cpv $share_dir/images/opera.xpm %%X11PREFIX%%/share/pixmaps/opera.xpm
     fi
   
     if test ! -d /etc/X11/wmconfig/; then
@@ -1319,36 +1287,36 @@
       fi
       # end /opt/gnome share
 
-    elif test -d /usr/share/gnome/; then
+    elif test -d %%X11PREFIX%%/share/gnome/; then
 
-        # /usr/share/gnome icon
-        if test ! -d /usr/share/gnome/pixmaps/; then
-	  if test -w /usr/share/gnome; then
-	    mkdir $mkdirv $mkdirp /usr/share/gnome/pixmaps/
-	    chmod $chmodv 755 /usr/share/gnome/pixmaps
-	    cp $cpv $share_dir/images/opera.xpm /usr/share/gnome/pixmaps/opera.xpm
+        # %%X11PREFIX%%/share/gnome icon
+        if test ! -d %%X11PREFIX%%/share/gnome/pixmaps/; then
+	  if test -w %%X11PREFIX%%/share/gnome; then
+	    mkdir $mkdirv $mkdirp %%X11PREFIX%%/share/gnome/pixmaps/
+	    chmod $chmodv 755 %%X11PREFIX%%/share/gnome/pixmaps
+	    cp $cpv $share_dir/images/opera.xpm %%X11PREFIX%%/share/gnome/pixmaps/opera.xpm
 	  fi
-	elif test -w /usr/share/gnome/pixmaps; then cp $cpv $share_dir/images/opera.xpm /usr/share/gnome/pixmaps/opera.xpm
+	elif test -w %%X11PREFIX%%/share/gnome/pixmaps; then cp $cpv $share_dir/images/opera.xpm %%X11PREFIX%%/share/gnome/pixmaps/opera.xpm
 	fi
-	# end /usr/share/gnome icon
+	# end %%X11PREFIX%%/share/gnome icon
 
-	# /usr/share/gnome link
-	if test -d /usr/share/gnome/apps/; then
-          if test -d /usr/share/gnome/apps/Internet/; then
-            if test -w /usr/share/gnome/apps/Internet; then
-              generate_desktop /usr/share/gnome/apps/Internet
+	# %%X11PREFIX%%/share/gnome link
+	if test -d %%X11PREFIX%%/share/gnome/apps/; then
+          if test -d %%X11PREFIX%%/share/gnome/apps/Internet/; then
+            if test -w %%X11PREFIX%%/share/gnome/apps/Internet; then
+              generate_desktop %%X11PREFIX%%/share/gnome/apps/Internet
 	    fi
-          elif test -d /usr/share/gnome/apps/Networking/WWW/; then
-            if test -w /usr/share/gnome/apps/Networking/WWW; then
-	     generate_desktop /usr/share/gnome/apps/Networking/WWW
+          elif test -d %%X11PREFIX%%/share/gnome/apps/Networking/WWW/; then
+            if test -w %%X11PREFIX%%/share/gnome/apps/Networking/WWW; then
+	     generate_desktop %%X11PREFIX%%/share/gnome/apps/Networking/WWW
 	    fi
-	  elif test -w /usr/share/gnome/apps; then
-	    mkdir $mkdirv $mkdirp/usr/share/gnome/apps/Internet/
-	    chmod $chmodv 755 /usr/share/gnome/apps/Internet
-            generate_desktop /usr/share/gnome/apps/Internet
+	  elif test -w %%X11PREFIX%%/share/gnome/apps; then
+	    mkdir $mkdirv $mkdirp %%X11PREFIX%%/share/gnome/apps/Internet/
+	    chmod $chmodv 755 %%X11PREFIX%%/share/gnome/apps/Internet
+            generate_desktop %%X11PREFIX%%/share/gnome/apps/Internet
           fi
 	fi
-	# end /usr/share/gnome link
+	# end %%X11PREFIX%%/share/gnome link
    fi
    # Add ximian here
 }
@@ -1385,12 +1353,12 @@
 
     fi  
     
-    if test -d /usr/share/applnk/Networking; then
-      if test ! -d /usr/share/applnk/Networking/WWW/ -a -w /usr/share/applnk/Networking; then
-	    mkdir $mkdirv $mkdirp /usr/share/applnk/Networking/WWW/
-	    chmod $chmodv 755 /usr/share/applnk/Networking/WWW
+    if test -d %%X11PREFIX%%/share/applnk/Networking; then
+      if test ! -d %%X11PREFIX%%/share/applnk/Networking/WWW/ -a -w %%X11PREFIX%%/share/applnk/Networking; then
+	    mkdir $mkdirv $mkdirp %%X11PREFIX%%/share/applnk/Networking/WWW/
+	    chmod $chmodv 755 %%X11PREFIX%%/share/applnk/Networking/WWW
       fi
-      if test -w /usr/share/applnk/Networking/WWW; then generate_desktop /usr/share/applnk/Networking/WWW ${1}; fi
+      if test -w %%X11PREFIX%%/share/applnk/Networking/WWW; then generate_desktop %%X11PREFIX%%/share/applnk/Networking/WWW ${1}; fi
     fi
 }
 
@@ -1414,8 +1382,8 @@
       fi
       if test -w /opt/kde/share/applnk/Internet; then generate_desktop /opt/kde/share/applnk/Internet; fi
 
-    elif test -d /usr/share/applnk/Internet/ -a -w /usr/share/applnk/Internet; then
-      generate_desktop /usr/share/applnk/Internet
+    elif test -d %%X11PREFIX%%/share/applnk/Internet/ -a -w %%X11PREFIX%%/share/applnk/Internet; then
+      generate_desktop %%X11PREFIX%%/share/applnk/Internet
     fi
 }
 
