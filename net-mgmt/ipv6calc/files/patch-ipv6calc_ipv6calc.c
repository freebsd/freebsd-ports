--- ipv6calc/ipv6calc.c.orig	2015-08-23 09:53:27 UTC
+++ ipv6calc/ipv6calc.c
@@ -1209,9 +1209,9 @@ PIPE_input:
 			outputtype = FORMAT_ipv4addr;
 		} else if ( ((inputtype == FORMAT_ipv4addr) || (inputtype == FORMAT_ipv4hex) || (inputtype == FORMAT_ipv4revhex)) && (action == ACTION_undefined || action == ACTION_anonymize) ) {
 			outputtype = FORMAT_ipv4addr;
-		} else if ( (inputtype == FORMAT_mac) ) {
+		} else if ( inputtype == FORMAT_mac ) {
 			outputtype = FORMAT_mac;
-		} else if ( (inputtype == FORMAT_eui64) ) {
+		} else if ( inputtype == FORMAT_eui64 ) {
 			outputtype = FORMAT_eui64;
 		} else if ( (inputtype == FORMAT_bitstring) || (inputtype == FORMAT_base85) ) {
 			outputtype = FORMAT_ipv6addr;
