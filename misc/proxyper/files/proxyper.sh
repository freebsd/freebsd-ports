#!/bin/sh

dir="CHANGETHIS"

echo -n " proxyper" 
su -m nobody -c "$dir/proxyper" 2>/dev/null >/dev/null &
