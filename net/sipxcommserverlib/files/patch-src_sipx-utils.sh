--- ./src/sipx-utils.sh.orig	Mon Jan  1 19:30:33 2007
+++ ./src/sipx-utils.sh	Mon Jan  1 19:37:57 2007
@@ -41,16 +41,24 @@
   }
 
 
+#
+# Let's modify this slightly to allow a hostname as the second arg and
+# not just an IP address.
+#
 sip_resolves_to () { # ( unresolved, targetIp )
     # returns true (0) if the unresolved name resolves to the targetIp address by sip rules
      unresolvedName=$1
      targetAddr=$2
+     targetAddr2=`dns_a $2`
 
      for ip in `dns_a ${unresolvedName}`
      do
        if [ "${ip}" = "${targetAddr}" ]
        then
            return 0
+       elif [ "${ip}" = "${targetAddr2}" ]
+       then
+           return 0
        fi
      done
 
@@ -61,6 +69,9 @@
          if [ "${ip}" = "${targetAddr}" ]
          then
              return 0
+         elif [ "${ip}" = "${targetAddr2}" ]
+         then
+             return 0
          fi
        done
      done
@@ -70,12 +81,18 @@
        if [ "${tcpSrv}" = "${targetAddr}" ]
        then
            return 0
+       elif [ "${tcpSrv}" = "${targetAddr2}" ]
+       then
+           return 0
        else
            for ip in `dns_a ${tcpSrv}`
            do
              if [ "${ip}" = "${targetAddr}" ]
              then
                  return 0
+             elif [ "${ip}" = "${targetAddr2}" ]
+             then
+                 return 0
              fi
            done
        fi
@@ -86,10 +103,16 @@
        if [ "${udpSrv}" = "${targetAddr}" ]
        then
            return 0
+       elif [ "${udpSrv}" = "${targetAddr2}" ]
+       then
+           return 0
        else
            for ip in `dns_a ${udpSrv}`
            do
              if [ "${ip}" = "${targetAddr}" ]
+             then
+                 return 0
+             elif [ "${ip}" = "${targetAddr2}" ]
              then
                  return 0
              fi
