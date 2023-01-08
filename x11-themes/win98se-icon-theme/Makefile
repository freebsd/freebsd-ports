PORTNAME=	win98se-icon-theme
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.15
CATEGORIES=	x11-themes

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Enhanced Classic Win98SE icon theme
WWW=		https://github.com/nestoris/Win98SE

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	nestoris
GH_PROJECT=	Win98SE
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} SE98 ${STAGEDIR}${PREFIX}/share/icons)

.include <bsd.port.mk>
