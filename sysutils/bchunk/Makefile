# New ports collection makefile for:	bchunk
# Date created:			9 Jan 1999
# Whom:				bsdx
#
# $FreeBSD$
#

PORTNAME=	bchunk
PORTVERSION=	1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://he.fi/bchunk/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/disk-management

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts .bin/.cue files to .iso/audio

MAN1=		bchunk.1
PLIST_FILES=	bin/bchunk

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} bchunk.c -o bchunk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bchunk ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bchunk.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
