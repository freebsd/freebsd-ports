# Created by: bsdx
# $FreeBSD$

PORTNAME=	bchunk
DISTVERSION=	1.2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://he.fi/bchunk/

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	Converts .bin/.cue files to .iso/audio

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	bin/bchunk man/man1/bchunk.1.gz

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} bchunk.c -o bchunk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bchunk ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bchunk.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
