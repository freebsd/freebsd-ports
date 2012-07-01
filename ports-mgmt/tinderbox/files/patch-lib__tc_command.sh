--- ./lib/tc_command.sh.orig	2012-03-11 18:29:27.000000000 +0100
+++ ./lib/tc_command.sh	2012-03-11 18:30:06.000000000 +0100
@@ -2299,9 +2299,9 @@
 		    oldcwd=${PWD}
 		    path=$(tinderLoc portstree ${portstree})
 		    cd "${path}/ports/${port}"
-		    distinfo=$(env PORTSDIR="${path}/ports" make -V MD5_FILE)
+		    distinfo=$(env PORTSDIR="${path}/ports" make -V DISTINFO_FILE)
 		    if [ -f "${distinfo}" ]; then
-			for df in $(grep '^MD5' ${distinfo} | awk -F '[\(\)]' '{print $2}'); do
+			for df in $(grep '^SHA256' ${distinfo} | awk -F '[\(\)]' '{print $2}'); do
 			    if ! grep -q "^${df}\$" ${disttmp}; then
 				echo ${df} >> ${disttmp}
 			    fi
