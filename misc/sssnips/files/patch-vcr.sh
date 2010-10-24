Description: Use /usr/local/etc/vcr on FreeBSD.
Forwarded: not-needed
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-10-24

--- vcr.sh.orig
+++ vcr.sh
@@ -90,8 +90,8 @@
 fi
 
 # Look for a definition file if not specified
-if [ -z "$filename" ] && [ -e '/etc/vcr' ]; then
-	filename='/etc/vcr'
+if [ -z "$filename" ] && [ -e '/usr/local/etc/vcr' ]; then
+	filename='/usr/local/etc/vcr'
 fi
 if [ -z "$filename" ] && [ -n "$HOME" ] && [ -d "$HOME" ] && \
    [ -e "$HOME/.vcr" ]; then
