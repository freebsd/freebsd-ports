# New ports collection makefile for:    miniupnpc
# Date created:         31 Oct 2007
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	miniupnpc
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.free.fr/files/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	UPnP IGD client lightweight library

USE_GMAKE=	yes
MAKE_ENV+=	INSTALLPREFIX=${PREFIX}
USE_LDCONFIG=	yes
MAN3=		miniupnpc.3

post-configure:
	${REINPLACE_CMD} -e 's|--mode=|-m |' -e 's|--symbolic|-s|' \
		-e 's| -Wall | -Wall -fPIC |' -e 's|--force|-f|' ${WRKSRC}/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/man3/miniupnpc.3 ${PREFIX}/man/man3/

.include <bsd.port.mk>
