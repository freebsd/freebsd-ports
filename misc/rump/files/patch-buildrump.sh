--- buildrump.sh.orig	2017-03-28 02:35:28 UTC
+++ buildrump.sh
@@ -1059,6 +1059,7 @@ evaltoolchain ()
 		;;
 	*-freebsd*)
 		RUMPKERN_UNDEF='-U__FreeBSD__'
+		${KERNONLY} || EXTRA_RUMPCLIENT='-lpthread'
 		;;
 	*-sun-solaris*|*-pc-solaris*)
 		RUMPKERN_UNDEF='-U__sun__ -U__sun -Usun'
