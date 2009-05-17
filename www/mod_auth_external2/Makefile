# New ports collection makefile for:	mod_auth_external2
# Date created:				Fri Oct  10
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	mod_auth_external
PORTVERSION=	2.2.11
CATEGORIES=	www
MASTER_SITES=	http://www.unixpapa.com/software/
DIST_SUBDIR=	apache20

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users authentication based on external mechanisms

MAKE_JOBS_SAFE=  yes

USE_APACHE=	20
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
LATEST_LINK=	mod_auth_external2
SHORTMODNAME=	auth_external

PORTDOCS=	AUTHENTICATORS INSTALL README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.mk>
