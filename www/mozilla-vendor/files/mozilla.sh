#!/bin/sh
#
# $FreeBSD$

cd @PREFIX@/lib/mozilla-vendor
exec ./mozilla "$@"
