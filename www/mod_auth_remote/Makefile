# New ports collection makefile for:	mod_auth_remote
# Date created:				Sun Oct  5
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_remote
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/ \
		http://www.cultdeadsheep.org/FreeBSD/ports/download/distfiles/
# Original location is here: http://puggy.symonds.net/~srp/stuff/
DIST_SUBDIR=	apache

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users to authenticate on a remote web server

USE_APACHE=	YES
WITH_APACHE2=	YES

PORTDOCS=	readme.txt
do-build:
	@(cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC} && ${APXS} -A -i ${PORTNAME}.la)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
