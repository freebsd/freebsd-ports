#!/bin/sh

CHANGETHIS/bin/gs -sDEVICE=pbm -q -dNOPAUSE -r600 -sOutputFile=- - | \
CHANGETHIS/bin/pbm2ppa - -
