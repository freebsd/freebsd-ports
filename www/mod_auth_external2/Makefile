# New ports collection makefile for:	mod_auth_external2
# Date created:				Fri Oct  10
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	mod_auth_external
PORTVERSION=	2.2.7
CATEGORIES=	www
MASTER_SITES=	http://www.unixpapa.com/software/
DIST_SUBDIR=	apache

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Allows users authentication based on external mechanisms

USE_APACHE=	YES
APACHE_PORT=	www/apache2

LATEST_LINK=	mod_auth_external2

PORTDOCS=	AUTHENTICATORS INSTALL README
do-build:
	@(cd ${WRKSRC}/ && ${APXS} -I. -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC}/ && ${APXS} -A -i ${PORTNAME}.la)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.mk>
