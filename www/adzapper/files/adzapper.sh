#!/bin/sh

python __PREFIX__/share/adzapper/adzapper.py \
  -f __PREFIX__/etc/adzapper.conf -z __PREFIX__/share/adzapper/zaplets $*
