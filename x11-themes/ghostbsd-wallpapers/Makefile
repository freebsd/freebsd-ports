# New ports collection makefile for: ghostbsd wallpapers
# Date created:        17 may 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	ghostbsd-wallpapers
PORTVERSION=	11.0.2
CATEGORIES=	x11-themes

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD wallpaper art

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/backgrounds/ghostbsd
	${CP} -PR ${WRKSRC}/*.jpg ${STAGEDIR}${PREFIX}/share/backgrounds/ghostbsd
	${MKDIR} ${STAGEDIR}${PREFIX}/share/mate-background-properties
	${CP} -PR ${WRKSRC}/ghostbsd.xml ${STAGEDIR}${PREFIX}/share/mate-background-properties/ghostbsd.xml
	${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome-background-properties
	${CP} -PR ${WRKSRC}/ghostbsd.xml ${STAGEDIR}${PREFIX}/share/gnome-background-properties/ghostbsd.xml
.include <bsd.port.mk>
