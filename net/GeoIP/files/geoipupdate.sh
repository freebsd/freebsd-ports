#!/bin/sh
cd /tmp
fetch http://64.246.48.99/download/geoip/database/GeoLiteCountry/GeoIP.dat.gz
gunzip GeoIP.dat.gz
mv -f GeoIP.dat /usr/local/share/GeoIP
