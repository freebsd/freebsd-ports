#!/bin/sh
#
# Where did they actually store the spool area?
# Check the NQS config file!
#
# Fortunately the ports system creates a temporary packing list that we can
# modify post-install before the install gets officially recorded.
#

PATH="/usr/bin:/bin"; export PATH       

me=`basename $0`

if [ $# -lt 2 ]; then
	echo usage: $me configfile workdir >&2
	exit 1
fi

root=`grep NQS_ROOTPRIV $1 | cut -f2 -d\"`
mv $2/.PLIST.mktmp $2/.PLIST.mktmp.orig
sed -e"s#XXXX#$root#" $2/.PLIST.mktmp.orig > $2/.PLIST.mktmp
