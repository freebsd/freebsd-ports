# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	mod_auth_external
PORTVERSION=	2.2.11
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.unixpapa.com/software/
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users authentication based on external mechanisms


USE_APACHE=	22
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
LATEST_LINK=	mod_auth_external2
SHORTMODNAME=	auth_external

PORTDOCS=	AUTHENTICATORS INSTALL README

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.   endfor
.endif

.include <bsd.port.mk>
