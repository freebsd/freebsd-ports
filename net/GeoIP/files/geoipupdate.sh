#!/bin/sh
cd /tmp
fetch http://geolite.maxmind.com/download/geoip/database/GeoLiteCountry/GeoIP.dat.gz
gunzip GeoIP.dat.gz
mv -f GeoIP.dat /usr/local/share/GeoIP
