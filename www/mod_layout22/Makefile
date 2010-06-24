# New ports collection makefile for:	mod_layout Apache 2 module
# Date created:				Nov 15 2002
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_layout
PORTVERSION=	5.1
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://download.tangent.org/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache2.2 module to wrap served pages with a header and/or footer

MAKE_JOBS_SAFE=	yes

CONFLICTS=	mod_layout-3.* mod_layout-4.*

PORTSCOUT=	limit:^5

USE_APACHE=	22
LATEST_LINK=	mod_layout22

MAKE_ARGS+=	builddir=${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
