#!/bin/sh

##
## script that converts remote module GitHub addresses to GH_TUPLE/CMAKE_ON values in Makefile.remote_modules
##

set -x

(
	# GH_TUPLE
	echo "GH_TUPLE+= \\"
	grep -h -E "^  (GIT_REPOSITORY |GIT_TAG )" $(make -V WRKSRC)/Modules/Remote/*.remote.cmake | \
	sed -e 's| \${git_protocol}://github.com/| |; s|/| |; s|\.git$||' | \
	awk '/^  GIT_REPOSITORY/ { printf("\t%s:%s:", $2, $3); name=$3 } /^  GIT_TAG/ { gsub("-","_",name); printf("%s:%s \\\n", $2, name) }'
	echo ""

	# CMAKE_ON
	grep -h -E "^  GIT_REPOSITORY " $(make -V WRKSRC)/Modules/Remote/*.remote.cmake | \
	sed -e 's|^  GIT_REPOSITORY \${git_protocol}://github.com/.*/|CMAKE_ON+=Module_|; s|ITK||; s|\.git$||'; \
	echo ""
) > Makefile.remote_modules
