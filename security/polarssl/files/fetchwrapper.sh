#!/bin/sh

# $FreeBSD$

# This script tacks the first argument onto each URL found in the list,
# discards and then executes the list.

# URL matching is simplistic, a URL is what matches *tp://* (so file:///
# is not matched).

# For instance, calling:
#   fetchwrapper.sh '?do=yes' /usr/bin/fetch -pPr http://example.org/file
# will execute:
#   /usr/bin/fetch -pPr http://example.org/file?do=yes

# The intention is to work around download splash screens on web servers.

# (C) Copyright 2013 by Matthias Andree.
# Licensed under the 2-clause BSD license.

if [ $# -lt 3 ] ; then
    echo >&2 "Usage: $0 URLsuffix fetch-command [options] URL [post-options]"
    exit 1
fi

patcharray() {
    # based on Rich Felker's "Working with arrays",
    # http://www.etalabs.net/sh_tricks.html
    for i do
	case "$i" in *tp://*) j=$suffix ;; *) j= ;; esac
	printf %s%s\\n "$i" "$j" | sed -e "s/'/'\\\\''/g;1s/^/'/;\$s/\$/' \\\\/"
    done
    echo " "
}

suffix="$1" ; shift
args=$(patcharray "$@")
eval "set -- $args"

set -x
exec "$@"
