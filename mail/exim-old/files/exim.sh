#!/bin/sh
args='-bd -q30m'
[ -x /usr/local/sbin/exim ] && /usr/local/sbin/exim $args && echo -n ' exim'
