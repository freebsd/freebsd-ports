PORTNAME=	mint-themes
PORTVERSION=	0.0.41cf70d
CATEGORIES=	x11-themes gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Themes for the cinnamon desktop

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GH_TAGNAME=	41cf70d

NO_BUILD=	yes

do-install:
	@(cd ${WRKSRC}/usr/share/themes/ && ${CP} -pPR * ${STAGEDIR}${PREFIX}/share/themes/)

.include <bsd.port.mk>
