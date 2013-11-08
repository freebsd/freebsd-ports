# Created by: bsdx
# $FreeBSD$

PORTNAME=	bchunk
PORTVERSION=	1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://he.fi/bchunk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts .bin/.cue files to .iso/audio

PLIST_FILES=	bin/bchunk man/man1/bchunk.1.gz

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} bchunk.c -o bchunk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bchunk ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bchunk.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
