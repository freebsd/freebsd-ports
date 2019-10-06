# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/x11-themes/mint-themes/Makefile 19873 2014-09-14 17:17:23Z kwm $

PORTNAME=	mint-themes
PORTVERSION=	0.0.41cf70d
CATEGORIES=	x11-themes gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Themes for the cinnamon desktop

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GH_TAGNAME=	41cf70d

NO_BUILD=	yes

do-install:
	@(cd ${WRKSRC}/usr/share/themes/ && ${CP} -pPR * ${STAGEDIR}${PREFIX}/share/themes/)

.include <bsd.port.mk>
