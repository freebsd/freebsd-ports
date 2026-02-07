--- ostype.awk.orig	1992-01-27 20:37:30 UTC
+++ ostype.awk
@@ -12,7 +12,7 @@ $0 ~ /^SunOS.* Release 4\./ {
 	os = "sunos4"
 }
 
-$0 ~ /^4.[1-9]\ ?BSD / {
+$0 ~ /BSD / {
 	os = "bsd"
 }
 
