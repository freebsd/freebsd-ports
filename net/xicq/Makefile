# New ports collection makefile for:	xicq
# Date created:				29 June 1998
# Whom:					scrappy
#
# $FreeBSD$
#

PORTNAME=	xicq
PORTVERSION=	19980712	
CATEGORIES=	net
MASTER_SITES=	http://www.xtrophy.dk/xicq/
DISTNAME=	xicq-071298-snapshot.src

MAINTAINER=	scrappy@FreeBSD.org

WRKSRC=		${WRKDIR}/xicq-071298

USE_GMAKE=	yes
MAKE_ENV=	OPT="${CFLAGS}"

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/xicq/main ${PREFIX}/bin/xicq
		${MKDIR} ${PREFIX}/share/examples/xicq
.for file in contact config
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/examples/xicq
.endfor

.include <bsd.port.mk>
