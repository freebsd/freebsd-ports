# New ports collection makefile for:	rtorrent-devel
# Date created:				May 17 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rtorrent-devel
PORTVERSION=	0.5.1
PORTREVISION=	0
DISTNAME=	${PORTNAME:S/-devel//}-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	BitTorrent Client written in C++ (development version)

LIB_DEPENDS=	torrent.7:${PORTSDIR}/net-p2p/libtorrent-devel

MASTERDIR=	${.CURDIR}/../rtorrent
MD5_FILE=	${.CURDIR}/distinfo
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${MASTERDIR}/pkg-descr

CONFLICTS=	rtorrent-[0-9]*

.include "${MASTERDIR}/Makefile"
