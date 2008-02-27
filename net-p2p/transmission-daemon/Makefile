# New ports collection makefile for:	transmission-daemon
# Date created:				08 February 2008
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	1
PKGNAMESUFFIX=	-daemon

COMMENT=	A free BitTorrent daemon written from scratch in C

DESCR=		${.CURDIR}/pkg-descr
MASTERDIR=	${.CURDIR}/../transmission
PLIST=		${.CURDIR}/pkg-plist

CUSTOM_SUBDIRS=	third-party libtransmission daemon
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
MAN1=		transmission-daemon.1 transmission-proxy.1 \
		transmission-remote.1

post-patch: general-patch

post-install: general-install

.include "${MASTERDIR}/Makefile"
