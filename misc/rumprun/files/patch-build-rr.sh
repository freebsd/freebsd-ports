--- build-rr.sh.orig	2018-04-08 14:37:33 UTC
+++ build-rr.sh
@@ -63,8 +63,6 @@ BUILDRUMP=$(pwd)/buildrump.sh
 # overriden by script if true
 HAVECXX=false
 
-: ${GIT:=git}
-
 # figure out where gmake lies
 if [ -z "${MAKE:-}" ]; then
 	MAKE=make
@@ -135,17 +133,7 @@ parseargs ()
 	done
 	shift $((${OPTIND} - 1))
 
-	# are we on a git branch which is not master?
-	if type ${GIT} >/dev/null; then
-		GITBRANCH=$(${GIT} rev-parse --abbrev-ref HEAD 2>/dev/null)
-		if [ ${GITBRANCH} = "master" -o ${GITBRANCH} = "HEAD" ]; then
-			GITBRANCH=
-		else
-			GITBRANCH=-${GITBRANCH}
-		fi
-	else
-		GITBRANCH=
-	fi
+        GITBRANCH=
 
 	[ -n "${RRDEST}" ] || RRDEST=./rumprun${GITBRANCH}${EXTSRC}
 
@@ -196,33 +184,6 @@ parseargs ()
 	ARGSSHIFT=$((${orignargs} - $#))
 }
 
-checksubmodules ()
-{
-
-	# We assume that if the git submodule command fails, it's because
-	# we're using external $RUMPSRC.
-	if git submodule status ${RUMPSRC} 2>/dev/null | grep -q '^-' \
-	    || git submodule status ${BUILDRUMP} 2>/dev/null | grep -q '^-';
-	then
-		echo '>>'
-		echo '>> submodules missing.  run "git submodule update --init"'
-		echo '>>'
-		exit 1
-	fi
-
-	if git submodule status ${RUMPSRC} 2>/dev/null | grep -q '^+' \
-	    || git submodule status ${BUILDRUMP} 2>/dev/null | grep -q '^+'
-	then
-		echo '>>'
-		echo '>> Your git submodules are out-of-date'
-		echo '>> Forgot to run "git submodule update" after pull?'
-		echo '>> (sleeping for 5s, press ctrl-C to abort)'
-		echo '>>'
-		echo -n '>>'
-		for x in 1 2 3 4 5; do echo -n ' !' ; sleep 1 ; done
-	fi
-}
-
 # check that the necessary things are available on the build system
 probeprereqs ()
 {
@@ -358,8 +319,17 @@ buildrump ()
 	# Disable new errors on GCC 7 which break netbsd-src compilation
 	#
 	[ `${CC} -dumpversion | cut -f1 -d.` -ge 7 ] \
-		&& extracflags="$extracflags -F CPPFLAGS=-Wimplicit-fallthrough=0"	
+		&& extracflags="$extracflags -F CPPFLAGS=-Wimplicit-fallthrough=0" \
+		&& extracflags="$extracflags -F CFLAGS=-Wno-error=maybe-uninitialized" \
+		&& extracflags="$extracflags -F CFLAGS=-Wno-error=implicit-function-declaration"
 
+	# Disable new errors on GCC 8 which break netbsd-src compilation
+	#
+	[ `${CC} -dumpversion | cut -f1 -d.` -ge 8 ] \
+		&& extracflags="$extracflags -F CFLAGS=-Wno-error=packed-not-aligned" \
+		&& extracflags="$extracflags -F CFLAGS=-Wno-error=cast-function-type" \
+		&& extracflags="$extracflags -F CFLAGS=-Wno-error=tautological-compare" \
+		&& extracflags="$extracflags -F CFLAGS=-Wno-error=attributes" \
 
 	# build tools
 	${BUILDRUMP}/buildrump.sh ${BUILD_QUIET} ${STDJ} -k		\
@@ -514,8 +484,6 @@ makeconfig ()
 
 dobuild ()
 {
-
-	checksubmodules
 
 	. ${BUILDRUMP}/subr.sh
 
