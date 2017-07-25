--- buildrump.sh.orig	2013-12-14 09:51:57 UTC
+++ buildrump.sh
@@ -893,6 +893,7 @@ evaltarget ()
 		;;
 	"freebsd")
 		RUMPKERN_UNDEF='-U__FreeBSD__'
+		${KERNONLY} || EXTRA_RUMPCLIENT='-lpthread'
 		;;
 	"linux")
 		RUMPKERN_UNDEF='-Ulinux -U__linux -U__linux__ -U__gnu_linux__'
