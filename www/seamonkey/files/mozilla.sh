#!/bin/sh
#
# $FreeBSD$

cd @PREFIX@/lib/%%MOZILLA%%
exec ./mozilla "$@"
