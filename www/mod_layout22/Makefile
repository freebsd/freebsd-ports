# New ports collection makefile for:	mod_layout Apache 2 module
# Date created:				Nov 15 2002
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_layout
PORTVERSION=	4.0.1a
CATEGORIES=	www
MASTER_SITES=	http://software.tangent.org/download/

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	Apache2 module to wrap served pages with a header and/or footer

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache2
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache2

USE_REINPLACE=	yes
MAKE_ARGS+=	builddir=${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
