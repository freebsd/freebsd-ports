#!/bin/sh

%%LOCALBASE%%/bin/gs -sDEVICE=ppmraw -q -dNOPAUSE -r600 -sOutputFile=- - | \
%%PREFIX%%/bin/pnm2ppa -i - -o -
