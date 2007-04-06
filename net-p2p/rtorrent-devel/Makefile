# New ports collection makefile for:	rtorrent-devel
# Date created:				May 17 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rtorrent-devel
PORTVERSION=	0.7.4
PORTREVISION=	0
DISTNAME=	${PORTNAME:S/-devel//}-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	BitTorrent Client written in C++ (development version)

# Libtorrent 0.11.* are all libtorrent.10, explicitely depend on 0.11.2+.
BUILD_DEPENDS=	libtorrent-devel>=0.11.2:${PORTSDIR}/net-p2p/libtorrent-devel
RUN_DEPENDS=	libtorrent-devel>=0.11.2:${PORTSDIR}/net-p2p/libtorrent-devel
LIB_DEPENDS=	# empty

MASTERDIR=	${.CURDIR}/../rtorrent
MD5_FILE=	${.CURDIR}/distinfo
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${MASTERDIR}/pkg-descr

CONFLICTS=	rtorrent-[0-9]*

.include "${MASTERDIR}/Makefile"
