#! /bin/sh
# $FreeBSD$
JDISKDIR="%%JDISKDIR%%"
JAVAVM="%%JAVAVM%%"

$JAVAVM -jar "$JDISKDIR/jdiskreport.jar"
