--- tests/t_lpback.sh.orig	2019-09-03 13:22:50 UTC
+++ tests/t_lpback.sh
@@ -26,7 +26,7 @@ trap "rm -f key.$$ tc-server-key.$$ tc-client-key.$$ l
 
 # Get list of supported ciphers from openvpn --show-ciphers output
 CIPHERS=$(${top_builddir}/src/openvpn/openvpn --show-ciphers | \
-            sed -e '/The following/,/^$/d' -e s'/ .*//' -e '/^\s*$/d')
+            sed -e '/The following/,/^$/d' -e s'/ .*//' -e '/^[[:space:]]*$/d')
 
 # SK, 2014-06-04: currently the DES-EDE3-CFB1 implementation of OpenSSL is
 # broken (see http://rt.openssl.org/Ticket/Display.html?id=2867), so exclude
