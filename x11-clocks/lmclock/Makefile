# New ports collection makefile for:	lmclock
# Date created:				18 June 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	lmclock
PORTVERSION=	1.2
CATEGORIES=	x11-clocks
MASTER_SITES=	http://pantransit.reptiles.org/prog/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A Xerox Lisp machine clock clone

USE_IMAKE=	yes

PLIST_FILES=	bin/lmclock

post-extract:
	@${TOUCH} ${WRKSRC}/lmclock.man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
