#!/bin/sh
cd /tmp
fetch http://www.maxmind.com/download/geoip/database/GeoIP.dat.gz
gunzip GeoIP.dat.gz
mv -f GeoIP.dat /usr/local/share/GeoIP
