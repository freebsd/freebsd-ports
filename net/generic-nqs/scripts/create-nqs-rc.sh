#!/bin/sh

PATH="/usr/bin:/bin"; export PATH
me=`basename $0`

if [ $# -lt 3 ]; then
	echo usage: $me configfile nqs.sh rcdir >&2
	exit 1
fi

root=`grep NQS_ROOTDIR $1 | cut -f2 -d\"`
sed -e"s#XXXX#$root#" $2 > $3
chmod 755 $3
echo ""
echo "Created $3 boot startup file." 
echo "    -  it will startup the 2 NQS daemons"
echo "    -  run this script manually now before attempting to create queues"
echo ""
