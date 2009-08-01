--- ./source4/script/installmisc.sh.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./source4/script/installmisc.sh	2009-07-12 02:39:36.000000000 +0000
@@ -8,11 +8,14 @@
 
 echo "Installing setup templates"
 mkdir -p $SETUPDIR || exit 1
+for p in enableaccount newuser provision provision-backend setexpiry setpassword upgrade
+do
+	chmod 0555 setup/$p
+	cp setup/$p $SETUPDIR || exit 1
+done
+cp -R setup/ad-schema $SETUPDIR || exit 1
 cp setup/schema-map-* $SETUPDIR || exit 1
 cp setup/DB_CONFIG $SETUPDIR || exit 1
-cp setup/provision-backend $SETUPDIR || exit 1
-cp setup/provision $SETUPDIR || exit 1
-cp setup/newuser $SETUPDIR || exit 1
 cp setup/*.inf $SETUPDIR || exit 1
 cp setup/*.ldif $SETUPDIR || exit 1
 cp setup/*.reg $SETUPDIR || exit 1
