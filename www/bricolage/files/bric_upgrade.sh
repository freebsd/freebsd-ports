#!/bin/sh

BRICUPGRADE=%%PREFIX%%/bricolage/upgrade
NEWVERSION=%%PORTVERSION%%

# Ensure the version exists
if [ "X" = "X${NEWVERSION}" ]
then
	echo "New version not supplied (port bug)"
	exit 1
fi

# Ensure the old version exists at the end of the argument list
OLDVERSION=`echo "$*" | sed -e "s/^.* \([^ ]*\)/\1/"`
VTEST=`echo "$OLDVERSION" | sed -e "s/^1\.8\.[01234]$/OKAY/"`
if [ "${VTEST}" != "OKAY" ]
then
	echo "The final argument should be the old version of the port, in the format."
	echo "	$0 [options] <version number>"
	exit 1
fi

HAS_VERSION=`grep ${OLDVERSION} ${BRICUPGRADE}/versions.txt`
if [ "${HAS_VERSION}" = "" ]
then
	echo "Version ${OLDVERSION} could not be found in the ${BRICUPGRADE}/versions.txt file"
	echo "There are no components to upgrade"
	exit 0
fi

# Now try to upgrade it
for ver in `grep -A 1000 ${OLDVERSION} ${BRICUPGRADE}/versions.txt | tail -n +2`
do
	if [ -d ${BRICUPGRADE}/${ver} ]
	then
		for file in `ls ${BRICUPGRADE}/${ver}`
		do
			${BRICUPGRADE}/${ver}/${file} $@ # Run with our args
		done
	fi
done

echo "Upgrade complete"
exit 0
