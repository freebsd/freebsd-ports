#!/bin/sh

CURDIR=`pwd`
WRKDIR=`pwd`/work
#mkdir -p "${WRKDIR}"

if [ \! -d "${CURDIR}/spacenavd-repo" ]; then
 git clone -b master https://github.com/FreeSpacenav/spacenavd.git "${CURDIR}/spacenavd-repo";
else
  cd "${CURDIR}/spacenavd-repo"
  git pull https://github.com/FreeSpacenav/spacenavd.git;
fi

cd "${CURDIR}/spacenavd-repo"
GIT_SRC_HASH=`git log -n 1 --pretty=format:"%H"`;
GIT_SRC_DATE=`git log -n 1 --date=iso-local -n 1 --pretty=format:"%cd" | \
    cut -c '1-19' | sed -e 's,-,,g' -e 's,:,,g' -e 's, ,,g'`

echo "$GIT_SRC_HASH, $GIT_SRC_DATE"
echo "GIT_SRC_HASH=  ${GIT_SRC_HASH}"    > ${CURDIR}/Makefile.git_rev
echo "GIT_SRC_DATE=  ${GIT_SRC_DATE}"   >> ${CURDIR}/Makefile.git_rev

