# New ports collection makefile for:	mod_layout Apache 2 module
# Date created:				Nov 15 2002
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_layout
PORTVERSION=	4.1
CATEGORIES=	www
MASTER_SITES=	http://download.tangent.org/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache2 module to wrap served pages with a header and/or footer

MAKE_JOBS_SAFE=	yes

LATEST_LINK=	mod_layout2
CONFLICTS=	mod_layout-3.* mod_layout-5.*
PORTSCOUT=	limit:4^

USE_APACHE=	20

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
