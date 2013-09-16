# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-nox11

COMMENT=	Bittorrent client using libtorrent-rasterbar, web UI version

MASTERDIR=	${.CURDIR}/../qbittorrent

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
PLIST_FILES+=	bin/qbittorrent-nox

MAN1=		qbittorrent-nox.1

QB_NOX_SLAVE=	true

.include "${MASTERDIR}/Makefile"
