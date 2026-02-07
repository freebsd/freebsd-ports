--- build/upgrade430.sh.orig	2010-11-17 07:35:58.000000000 +0100
+++ build/upgrade430.sh	2011-04-02 10:17:51.000000000 +0200
@@ -119,6 +119,8 @@
 	ln -s xymonserver.cfg hobbitserver.cfg
 fi
 
+if test -f /nonexistent
+then
 cd $BBHOME || (echo "Cannot cd to BBHOME directory"; exit 1)
 if test ! -w .; then echo "Cannot write to BBHOME directory"; exit 1; fi
 renameandlink hobbit.sh xymon.sh
@@ -249,6 +251,7 @@
 renameandlink hobbit-nkedit.sh criticaleditor.sh
 renameandlink hobbit-ackinfo.sh ackinfo.sh
 renameandlink hobbit-useradm.sh useradm.sh
+fi
 
 
 cd $BBSERVERROOT/client/etc || (echo "Cannot cd to client/etc directory"; exit 1)
@@ -268,6 +271,8 @@
 	ln -s xymonclient.cfg hobbitclient.cfg
 fi
 
+if test -f /nonexistent
+then
 cd $BBSERVERROOT/client/bin || (echo "Cannot cd to client/bin directory"; exit 1)
 if test ! -w .; then echo "Cannot write to client/bin directory"; exit 1; fi
 renameandlink bb xymon
@@ -289,6 +294,7 @@
 renameandlink hobbitclient-sunos.sh xymonclient-sunos.sh
 renameandlink hobbitlaunch xymonlaunch
 renameandlink orcahobbit orcaxymon
+fi
 
 
 cd $BBRRDS/$MACHINEDOTS || (echo "Cannot cd to Xymon-servers\' RRD directory"; exit 1)
@@ -313,11 +319,14 @@
 if test -d hobbitd; then mv hobbitd xymond; fi
 if test -d bbproxy; then mv bbproxy xymonproxy; fi
 
+if test -f /nonexistent
+then
 cd $BBWWW || (echo "Cannot cd to Xymon-servers\' www directory"; exit 1)
 if test ! -w .; then echo "Cannot write to Xymon-servers\' www directory"; exit 1; fi
 renameandlink bb.html xymon.html
 renameandlink bb2.html nongreen.html
 renameandlink bbnk.html critical.html
+fi
 
 
 echo ""
