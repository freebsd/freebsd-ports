# New ports collection makefile for:	libtorrent-devel
# Date created:				May 17 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libtorrent-devel
PORTVERSION=	0.9.1
PORTREVISION=	0
DISTNAME=	${PORTNAME:S/-devel//}-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	BitTorrent Library written in C++ (development version)

MASTERDIR=	${.CURDIR}/../libtorrent
MD5_FILE=	${.CURDIR}/distinfo
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${MASTERDIR}/pkg-descr

CONFLICTS=	libtorrent-[0-9]*

.include "${MASTERDIR}/Makefile"
