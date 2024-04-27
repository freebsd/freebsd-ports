PORTNAME=	canta-icon-theme
DISTVERSION=	2021-09-08
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Flat icons for Canta GTK theme
WWW=		https://github.com/vinceliuice/Canta-theme

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	numix-icon-theme-circle>0:x11-themes/numix-icon-theme-circle

USE_GITHUB=	yes
GH_ACCOUNT=	vinceliuice
GH_PROJECT=	Canta-theme
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC}/icons && ${COPYTREE_SHARE} Canta ${STAGEDIR}${PREFIX}/share/icons)

.include <bsd.port.mk>
