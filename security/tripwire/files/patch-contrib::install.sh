--- contrib/install.sh.orig	Thu Sep 15 20:12:39 2005
+++ contrib/install.sh	Tue Feb 21 08:22:10 2006
@@ -162,12 +162,6 @@
 # Default installation script configuration file.
 INSTALL_CONFIG_FILE="./install/install.cfg"
 
-# Name of the Readme file.
-README="README"
-
-# Name of the release notes.
-REL_NOTES="Release_Notes"
-
 # Relative path to dir that contains the pkg files.
 PKG_DIR="pkg"
 
@@ -573,8 +567,6 @@
 
 README_LOC=${TWDOCS}/$REL_NOTES
 
-f1=' ff=$README ; d="" ; dd=$TWDOCS ; rr=0444 '
-f2=' ff=$REL_NOTES ; d="" ; dd=$TWDOCS ; rr=0444 '
 f3=' ff=$TWLICENSEFILE ; d="" ; dd=$TWDOCS ; rr=0444 '
 #f4=' ff=tripwire ; d="/bin" ; dd=$TWBIN ; rr=0550 '
 #f5=' ff=twadmin ; d="/bin" ; dd=$TWBIN ; rr=0550 '
@@ -593,7 +585,7 @@
 #f18=' ff=twprint.8 ; d="/man/man8" ; dd=$TWMAN/man8 ; rr=0444 '
 
 # Binaries and manpages are already installed by the install target
-loosefiles="f1 f2 f3 f8 f9 f10"
+loosefiles="f3 f8 f9 f10"
 
 for i in $loosefiles; do
 	eval "eval \"\$$i\""
@@ -719,6 +711,7 @@
 ## Generate tripwire configuration file.
 ##=======================================================
 
+[ ! -f "$TXT_CFG" -o "$CLOBBER" = "false" ] && {
 echo
 echo "----------------------------------------------"
 echo "Generating Tripwire configuration file..."
@@ -757,6 +750,7 @@
 fi
 
 chmod 640 "$TXT_CFG"
+}
 
 ##=======================================================
 ## Create signed tripwire configuration file.
@@ -826,20 +820,21 @@
 echo "----------------------------------------------"
 echo "Customizing default policy file..."
 
-sed '/@@section GLOBAL/,/@@section FS/  {
-  s?^\(TWROOT=\).*$?TWDOCS='\""$TWDOCS"\"';?
-  s?^\(TWBIN=\).*$?\1'\""$TWBIN"\"';?
-  s?^\(TWPOL=\).*$?\1'\""$TWPOLICY"\"';?
-  s?^\(TWDB=\).*$?\1'\""$TWDB"\"';?
-  s?^\(TWSKEY=\).*$?\1'\""$TWSITEKEYDIR"\"';?
-  s?^\(TWLKEY=\).*$?\1'\""$TWLOCALKEYDIR"\"';?
-  s?^\(TWREPORT=\).*$?\1'\""$TWREPORT"\"';?
-  s?^\(HOSTNAME=\).*$?\1'"$HOST_NAME"';?
-}' "${TWPOLICY}/${POLICYSRC}" > "${TXT_POL}.tmp"
-
 # copy the tmp file back over the default policy
 [ -f "${TXT_POL}" ] && cp "${TXT_POL}" "${TXT_POL}.bak"
-mv "${TXT_POL}.tmp" "${TXT_POL}"
+[ ! -f "${TXT_POL}" -o "$CLOBBER" = "true" ] && {
+	sed '/@@section GLOBAL/,/@@section FS/  {
+	  s?^\(TWROOT=\).*$?TWDOCS='\""$TWDOCS"\"';?
+	  s?^\(TWBIN=\).*$?\1'\""$TWBIN"\"';?
+	  s?^\(TWPOL=\).*$?\1'\""$TWPOLICY"\"';?
+	  s?^\(TWDB=\).*$?\1'\""$TWDB"\"';?
+	  s?^\(TWSKEY=\).*$?\1'\""$TWSITEKEYDIR"\"';?
+	  s?^\(TWLKEY=\).*$?\1'\""$TWLOCALKEYDIR"\"';?
+	  s?^\(TWREPORT=\).*$?\1'\""$TWREPORT"\"';?
+	  s?^\(HOSTNAME=\).*$?\1'"$HOST_NAME"';?
+	}' "${TWPOLICY}/${POLICYSRC}" > "${TXT_POL}"
+}
+
 rm -f "${TWPOLICY}/${POLICYSRC}"
 
 # reset rights on the policy files to 640
