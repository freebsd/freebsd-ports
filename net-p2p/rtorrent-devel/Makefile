# New ports collection makefile for:	rtorrent-devel
# Date created:				May 17 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rtorrent-devel
PORTVERSION=	0.8.5
DISTNAME=	${PORTNAME:S/-devel//}-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	BitTorrent Client written in C++ (development version)

BUILD_DEPENDS=	libtorrent-devel=0.12.5:${PORTSDIR}/net-p2p/libtorrent-devel
RUN_DEPENDS=	libtorrent-devel=0.12.5:${PORTSDIR}/net-p2p/libtorrent-devel

MASTERDIR=	${.CURDIR}/../rtorrent
PATCHDIR=	${.CURDIR}/files/
MD5_FILE=	${.CURDIR}/distinfo
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${MASTERDIR}/pkg-descr

CONFLICTS=	rtorrent-[0-9]*

USE_GCC=	4.2+

.include "${MASTERDIR}/Makefile"
