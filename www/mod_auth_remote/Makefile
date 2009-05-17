# New ports collection makefile for:	mod_auth_remote
# Date created:				Sun Oct  5
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_remote
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/ \
		http://www.cultdeadsheep.org/FreeBSD/ports/download/distfiles/
# Original location is here: http://puggy.symonds.net/~srp/stuff/
DIST_SUBDIR=	apache

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows users to authenticate on a remote web server

MAKE_JOBS_SAFE=  yes

USE_APACHE=	20
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

PORTDOCS=	readme.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
