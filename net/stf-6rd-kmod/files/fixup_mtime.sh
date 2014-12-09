#!/bin/sh

EXPDIR=$1
SVN_REV=$2
SVN_MIRROR=$3
OSREL=$4

cd ${EXPDIR} || exit 1
t=`TZ=UTC svn info -r${SVN_REV} ${SVN_MIRROR}/releng/${OSREL}/sys/net | grep 'Last Changed Date:' |\
	sed -Ee 's|Last Changed Date: ||; s|(....-..-..) (..:..:..) .0000 \(.*|\1T\2Z|'`
find ${EXPDIR} -type d -print0 | xargs -0 touch -d$t

# Local Variables:
# sh-basic-offset: 8
# sh-indentation: 8
# End:
