#!/bin/sh

dir="CHANGETHIS"

if [ ! -d $dir ]; then
 logger -i "dnetc client directory doesn't exist. ($dir)."
 exit
fi

if [ ! -f $dir/dnetc ]; then
 logger -i "dnetc client doesn't exist. ($dir/dnetc)."
 exit
fi

if [ ! -f $dir/dnetc.ini ]; then
 logger -i "dnetc client config file doesn't exist. ($dir/dnetc.ini)."
 exit
fi

email=`grep "^id=" $dir/dnetc.ini|cut -d"=" -f2`

if [ "$email" = "rc5@distributed.net" ]; then
 logger -i "dnetc client running with default email address. ($email)"
fi

echo -n " dnetc"
su -m nobody -c "$dir/dnetc -quiet" 2>/dev/null >/dev/null &
