# New ports collection makefile for: ghostbsd wallpapers
# Date created:        17 may 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	ghostbsd-wallpapers-new
PORTVERSION=	1.0
CATEGORIES=	x11-themes

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD art for DE's

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share 
	${CP} -PR ${WRKSRC}/share/* ${STAGEDIR}${PREFIX}/share
.include <bsd.port.mk>
