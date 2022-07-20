PORTNAME=	flatery-icon-themes
DISTVERSION=	2022-01-17
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Flatery is an icon theme for linux in flat style

LICENSE=	CC-BY-NC-SA-3.0

USE_GITHUB=	yes

GH_ACCOUNT=	cbrnix
GH_PROJECT=	Flatery
GH_TAGNAME=	59ebcf4cb7a68
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	${CP} -R ${WRKSRC}/Flatery* ${STAGEDIR}${PREFIX}/share/icons

.include <bsd.port.mk>
