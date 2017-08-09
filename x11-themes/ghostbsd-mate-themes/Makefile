# New ports collection makefile for: ghostbsd themes
# Date created:        17 may 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	ghostbsd-mate-themes
PORTVERSION=	1.5
CATEGORIES=	x11-themes

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD themes for mate flavour

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/
	${CP} -R ${WRKSRC}/themes/* ${STAGEDIR}${PREFIX}/share/themes
.include <bsd.port.mk>
