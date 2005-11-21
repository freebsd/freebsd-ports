--- makei18n.sh.orig	Sun Nov 20 23:17:39 2005
+++ makei18n.sh	Sun Nov 20 23:18:34 2005
@@ -1,5 +1,5 @@
 APP_NAME="bittorrent"
-LANGUAGES=`python language_codes.py`
+LANGUAGES=`cd po; ls *.po | sed -e 's/\.po//'`
 MESSAGES_PO="messages.pot"
 
 rm -f $APP_NAME.lis
