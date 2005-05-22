# New ports collection makefile for:	mod_layout Apache 2 module
# Date created:				Nov 15 2002
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_layout
PORTVERSION=	4.0.2a
CATEGORIES=	www
MASTER_SITES=	http://download.tangent.org/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache2 module to wrap served pages with a header and/or footer

USE_APACHE=	yes
WITH_APACHE2=	yes
LATEST_LINK=	mod_layout2

MAKE_ARGS+=	builddir=${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
