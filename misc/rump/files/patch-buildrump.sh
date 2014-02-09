--- buildrump.sh.orig	2013-12-14 17:51:57.000000000 +0800
+++ buildrump.sh	2014-02-08 23:21:05.880728426 +0800
@@ -893,6 +893,7 @@ evaltarget ()
 		;;
 	"freebsd")
 		RUMPKERN_UNDEF='-U__FreeBSD__'
+		${KERNONLY} || EXTRA_RUMPCLIENT='-lpthread'
 		;;
 	"linux")
 		RUMPKERN_UNDEF='-Ulinux -U__linux -U__linux__ -U__gnu_linux__'
