# New ports collection makefile for:	palmpower
# Date Created:				22 Aug 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	palmpower
PORTVERSION=	1.0.2
CATEGORIES=	palm
MASTER_SITES=	http://www.fh-wilhelmshaven.de/~akcaagaa/palmpower/files/

MAINTAINER=	roman@xpert.com

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		pilotdis.1

post-build:
	cd ${WRKSRC}/utils; ${CC} ${CFLAGS} -o splitprc splitprc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pila/pila ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/pilotdis/pilotdis ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/utils/splitprc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/pilotdis.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
