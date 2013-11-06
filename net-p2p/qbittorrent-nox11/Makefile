# Created by: Doug Barton <dougb@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-nox11

COMMENT=	Bittorrent client using libtorrent-rasterbar, web UI version

MASTERDIR=	${.CURDIR}/../qbittorrent

DESCR=		${.CURDIR}/../qbittorrent/pkg-descr
PLIST_FILES+=	bin/qbittorrent-nox \
		man/man1/qbittorrent-nox.1.gz
PLIST=		${NONEXISTENT}

SLAVE_PORT=	yes

OPTIONS_EXCLUDE=	DOCS

.include "${MASTERDIR}/Makefile"
