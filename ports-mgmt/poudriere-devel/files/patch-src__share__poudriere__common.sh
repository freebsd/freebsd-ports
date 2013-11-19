--- ./src/share/poudriere/common.sh.orig	2013-10-28 13:45:28.000000000 -0500
+++ ./src/share/poudriere/common.sh	2013-11-19 17:57:59.613130066 -0600
@@ -1161,6 +1161,14 @@
 			echo "- ${mnt}/${l% *}"
 			;;
 		*changed) echo "M ${mnt}/${l% *}" ;;
+		extra:*)
+			if [ -d ${mnt}/${l#* } ]; then
+				find ${mnt}/${l#* } -exec echo "+ {}" \;
+			else
+				echo "+ ${mnt}/${l#* }"
+			fi
+			;;
+		*:*) echo "M ${mnt}/${l%:*}" ;;
 		esac
 	done
 }
