# New ports collection makefile for:	cmatrix
# Version required:			1.0b
# Date created:				1 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	cmatrix-1.0b
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/hacks/curses

MAINTAINER=	ports@FreeBSD.org

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} cmatrix.c -lncurses -o cmatrix

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmatrix ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/cmatrix
.for file in Changelog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/cmatrix
.endfor
.endif

.include <bsd.port.mk>
