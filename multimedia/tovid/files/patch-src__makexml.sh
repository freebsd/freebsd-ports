--- src/makexml.sh.orig	Sun Feb 19 05:52:41 2006
+++ src/makexml.sh	Sun Feb 19 05:52:41 2006
@@ -183,7 +183,7 @@
     # Generate XML for the button linking to this titleset menu from the top menu
     TOP_MENU_BUTTONS=`cat << EOF
   $TOP_MENU_BUTTONS\
-    <button>jump titleset $CUR_TS menu;<\/button>\n
+    <button>jump titleset $CUR_TS menu;<\/button>
 EOF`
 
     # Generate XML for the menu header, with a placeholder for
@@ -206,7 +206,7 @@
     # Generate XML for the button linking to this menu from the top menu
     TOP_MENU_BUTTONS=`cat << EOF
 $TOP_MENU_BUTTONS\
-    <select ref="select-menu-$CUR_TS"\/>\n
+    <select ref="select-menu-$CUR_TS"\/>
 EOF`
 
     # Generate XML for the segment item
@@ -271,7 +271,7 @@
       if [ $CUR_VIDEO -lt 2 ]; then
         MENU_BUTTONS=`cat << EOF
 $MENU_BUTTONS\
-        <button>jump title $CUR_TITLE;<\/button>\n
+        <button>jump title $CUR_TITLE;<\/button>
 EOF`
       fi
     else
@@ -279,7 +279,7 @@
       if [ $CUR_VIDEO -le 1 ]; then
         TOP_MENU_BUTTONS=`cat << EOF
 $TOP_MENU_BUTTONS\
-        <button>jump titleset $CUR_TS menu;<\/button>\n
+        <button>jump titleset $CUR_TS menu;<\/button>
 EOF`
       fi
     fi 
@@ -377,7 +377,7 @@
       if $FIRST_TITLE; then
         MENU_BUTTONS=`cat << EOF
 $MENU_BUTTONS
-    <select ref="play-title-$CUR_TITLE"\/>\n
+    <select ref="play-title-$CUR_TITLE"\/>
 EOF`
       fi
 
@@ -413,7 +413,7 @@
       # jump to this playlist (title)
       MENU_BUTTONS=`cat << EOF
 $MENU_BUTTONS\
-    <select ref="play-title-$CUR_TITLE"\/>\n
+    <select ref="play-title-$CUR_TITLE"\/>
 EOF`
 
       # Generate XML for the sequence item
@@ -457,7 +457,7 @@
     if $HAVE_TOP_MENU; then
       MENU_BUTTONS=`cat << EOF
 $MENU_BUTTONS\
-      <button>jump vmgm menu;<\/button>\n
+      <button>jump vmgm menu;<\/button>
 EOF`
     fi
 
