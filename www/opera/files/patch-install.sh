--- install.sh.orig	Tue Jun  1 12:35:02 2004
+++ install.sh	Tue Jun  1 19:40:04 2004
@@ -760,9 +760,7 @@
 
     wrapper_opera_plugin_paths="    \"\${HOME}/.opera/plugins\" \\
     ${str_localdirplugin} \\
-    /usr/lib/opera/plugins \\
-    /usr/local/lib/opera/plugins \\
-    /opt/lib/opera/plugins \\"
+    /usr/local/share/opera/plugins \\"
 
     case "${machine}:${os}" in
 	i[3456]86:Linux|x86_64:Linux|i[3456]86:FreeBSD|i[3456]86:NetBSD|i[3456]86:OpenBSD)
@@ -817,15 +815,10 @@
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
 
     wrapper_file="${wrapper_dir}/opera"
     
@@ -983,11 +976,8 @@
 
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
@@ -1254,36 +1244,13 @@
 
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
 
@@ -1367,22 +1334,22 @@
 
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
@@ -1412,72 +1379,36 @@
 
     debug_msg 1 "in gnome()"
 
-    if test -d /opt/gnome/; then
-
-      # /opt/gnome share
-      if test -d /opt/gnome/share; then
-
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
-          fi
-	fi
-	# end /opt/gnome link
-      fi
-      # end /opt/gnome share
-
-    elif test -d /usr/share/gnome/; then
+    if test -d %%X11BASE%%/share/gnome/; then
 
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
+	   if test -d %%X11BASE%%/share/gnome/apps/Internet/; then
+	     if test -w %%X11BASE%%/share/gnome/apps/Internet; then
+	       generate_desktop %%X11BASE%%/share/gnome/apps/Internet
 	    fi
-          elif test -d /usr/share/gnome/apps/Networking/WWW/; then
-            if test -w /usr/share/gnome/apps/Networking/WWW; then
-	     generate_desktop /usr/share/gnome/apps/Networking/WWW
+           elif test -d %%X11BASE%%/share/gnome/apps/Networking/WWW/; then
+             if test -w %%X11BASE%%/share/gnome/apps/Networking/WWW; then
+             generate_desktop %%X11BASE%%/share/gnome/apps/Networking/WWW
 	    fi
-	  elif test -w /usr/share/gnome/apps; then
-	    mkdir $mkdirv $mkdirp /usr/share/gnome/apps/Internet/
-	    chmod $chmodv 755 /usr/share/gnome/apps/Internet
-            generate_desktop /usr/share/gnome/apps/Internet
+          elif test -w %%X11BASE%%/share/gnome/apps; then
+            mkdir $mkdirv $mkdirp %%X11BASE%%/share/gnome/apps/Internet/
+            chmod $chmodv 755 %%X11BASE%%/share/gnome/apps/Internet
+             generate_desktop %%X11BASE%%/share/gnome/apps/Internet
           fi
 	fi
-	# end /usr/share/gnome link
+	# end %%X11BASE%%/share/gnome link
    fi
    # Add ximian here
 }
@@ -1488,39 +1419,31 @@
 
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
@@ -1543,8 +1466,8 @@
       fi
       if test -w /opt/kde/share/applnk/Internet; then generate_desktop /opt/kde/share/applnk/Internet; fi
 
-    elif test -d /usr/share/applnk/Internet/ -a -w /usr/share/applnk/Internet; then
-      generate_desktop /usr/share/applnk/Internet
+    elif test -d /usr/X11R6/share/applnk/Internet/ -a -w /usr/X11R6/share/applnk/Internet; then
+      generate_desktop /usr/X11R6/share/applnk/Internet
     fi
 }
 
