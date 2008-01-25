# New ports collection makefile for:    miniupnpc
# Date created:         31 Oct 2007
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	miniupnpc
PORTVERSION=	0.1.0.11
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.free.fr/files/
DISTNAME=	${PORTNAME}-1.0-RC11

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	UPnP IGD client lightweight library

USE_GMAKE=	yes
MAKE_ENV+=	INSTALLPREFIX=${PREFIX}
USE_LDCONFIG=	yes

post-configure:
	${REINPLACE_CMD} -e 's|--mode=|-m |' -e 's|--symbolic|-s|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
