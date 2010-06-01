
$FreeBSD$

--- m4/codecs.m4.orig
+++ m4/codecs.m4
@@ -25,6 +25,10 @@
 			MOONLIGHT_CODEC_OSTYPE=linux
 			CODECS_OS_SUPPORTED="yes"
 			;;
+		*-*-*freebsd*)
+			MOONLIGHT_CODEC_OSTYPE=freebsd
+			CODECS_OS_SUPPORTED="yes"
+			;;
 	esac
 
 	if test ${MOONLIGHT_CODEC_ARCH} = unknown; then
