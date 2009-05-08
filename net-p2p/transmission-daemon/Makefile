# New ports collection makefile for:	transmission-daemon
# Date created:				08 February 2008
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	1
PKGNAMESUFFIX=	-daemon

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A fast and lightweight daemon BitTorrent client

DESCR=		${.CURDIR}/pkg-descr
MASTERDIR=	${.CURDIR}/../transmission-cli
PLIST=		${.CURDIR}/pkg-plist
SLAVEPORT=	daemon

MAN1=		transmission-daemon.1 transmission-remote.1

.include "${MASTERDIR}/Makefile"
