# New ports collection makefile for: netscape-communcator-linux-4.x
# Date created:			27 June 1999
# Whom:				girgen@partitur.se
# Based on work by:		thepish
#
# $FreeBSD$
#

PORTNAME=	linux-netscape-${BROWSER}
PORTVERSION=	4.77
CATEGORIES=	www linux

MAINTAINER=	girgen@partitur.se

RUN_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386

NETSCAPE_DIST_ARCH=	supported/linux22
NETSCAPE_DIST_TAG=	x86-unknown-linux2.2

# don't overwrite the native FreeBSD port's shell script wrapper in ${PREFIX}/bin
BROWSER_ARC=	${BROWSER}-linux

USE_LINUX_LIB=	yes

MAILCAP=	${.CURDIR}/../linux-netscape47-communicator/files/mailcap
NSUBDIR=	lib/netscape-linux

.include "../netscape47-communicator/Makefile"
