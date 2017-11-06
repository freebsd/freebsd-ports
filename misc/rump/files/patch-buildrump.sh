--- buildrump.sh.orig	2017-03-28 02:35:28 UTC
+++ buildrump.sh
@@ -177,6 +177,9 @@ probeld ()
 	elif echo ${linkervers} | grep -q 'GNU gold' ; then
 		LD_FLAVOR=gold
 		LD_AS_NEEDED='-Wl,--no-as-needed'
+	elif echo ${linkervers} | grep -q 'LLD' ; then
+		LD_FLAVOR=GNU
+		LD_AS_NEEDED='-Wl,--no-as-needed'
 	elif echo ${linkervers} | grep -q 'Solaris Link Editor' ; then
 		LD_FLAVOR=sun
 		SHLIB_MKMAP=no
@@ -788,6 +791,8 @@ makebuild ()
 	     -o ${MACHINE#evbearm} != ${MACHINE} \
 	     -o ${MACHINE#evbppc} != ${MACHINE} ]; then
 		DIRS_emul=sys/rump/kern/lib/libsys_linux
+	else
+		DIRS_emul=
 	fi
 	${SYS_SUNOS} && appendvar DIRS_emul sys/rump/kern/lib/libsys_sunos
 	if ${HIJACK}; then
@@ -1059,6 +1064,7 @@ evaltoolchain ()
 		;;
 	*-freebsd*)
 		RUMPKERN_UNDEF='-U__FreeBSD__'
+		${KERNONLY} || EXTRA_RUMPCLIENT='-lpthread'
 		;;
 	*-sun-solaris*|*-pc-solaris*)
 		RUMPKERN_UNDEF='-U__sun__ -U__sun -Usun'
